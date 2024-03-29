interface OnClickHandler 
{
	(x:number, y:number): void;
}


interface HttpPostCallback {
	(x:any): any;
}

const random_id = (len:number) => {
    let p = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
    return [...Array(len)].reduce(a => a + p[Math.floor(Math.random() * p.length)], '');
}

const g_origin = new URL(window.location.href).origin;
const g_id = random_id(12);

// Payload is a marshaled (but not JSON-stringified) object
// A JSON-parsed response object will be passed to the callback
const httpPost = (page_name: string, payload: any, callback: HttpPostCallback) => {
	let request = new XMLHttpRequest();
	request.onreadystatechange = () => {
		if(request.readyState === 4)
		{
			if(request.status === 200) {
				let response_obj;
				try {
					response_obj = JSON.parse(request.responseText);
				} catch(err) {}
				if (response_obj) {
					callback(response_obj);
				} else {
					callback({
						status: 'error',
						message: 'response is not valid JSON',
						response: request.responseText,
					});
				}
			} else {
				if(request.status === 0 && request.statusText.length === 0) {
					callback({
						status: 'error',
						message: 'connection failed',
					});
				} else {
					callback({
						status: 'error',
						message: `server returned status ${request.status}: ${request.statusText}`,
					});
				}
			}
		}
	};
	request.open('post', `${g_origin}/${page_name}`, true);
	request.setRequestHeader('Content-Type', 'application/json');
	request.send(JSON.stringify(payload));
}





class Sprite 
{
	x:number;
	y:number;
	dest_x:number = 0;
	dest_y:number = 0;
	speed:number = 4;
	image = new Image();
	update:()=>void;

	constructor(x:number, y:number, image_url:string, update_method:()=>void, onclick_method:OnClickHandler) 
	{
		this.x = x;
		this.y = y;
		this.dest_x = x;
		this.dest_y = y;
		this.image.src = image_url;
		this.update = update_method;
		let onclick = onclick_method;
	}

	set_destination(x:number, y:number) 
	{
		this.dest_x = x;
		this.dest_y = y;
	}

	ignore_click(x:number, y:number) 
	{
	}

	move(dx:number, dy:number) 
	{
		this.dest_x = this.x + dx;
		this.dest_y = this.y + dy;
	}

	go_toward_destination() 
	{
		if(this.dest_x === undefined)
			return;

		if(this.x < this.dest_x)
			this.x += Math.min(this.dest_x - this.x, this.speed);
		else if(this.x > this.dest_x)
			this.x -= Math.min(this.x - this.dest_x, this.speed);
		if(this.y < this.dest_y)
			this.y += Math.min(this.dest_y - this.y, this.speed);
		else if(this.y > this.dest_y)
			this.y -= Math.min(this.y - this.dest_y, this.speed);
	}

	sit_still() 
	{
	}
	
	onclick(x:number, y:number)
	{
		this.set_destination(x, y);
	}

}

let id_to_sprite: Record<string, Sprite> =  {}








class Model 
{
	sprites:Sprite[] = [];
	turtle:Sprite;
	

	constructor() 
	{
		
		this.sprites.push(new Sprite(200, 100, "lettuce.png", Sprite.prototype.sit_still, Sprite.prototype.ignore_click));
		this.turtle = new Sprite(50, 50, "blue_robot.png", Sprite.prototype.go_toward_destination, Sprite.prototype.set_destination);
		
		this.sprites.push(this.turtle);
		id_to_sprite[g_id] = this.turtle;
	}

	update() 
	{
		for (const sprite of this.sprites) {
			sprite.update();
		}
	}

	onclick(x:number, y:number) 
	{
		// for (const sprite of this.sprites) {
		// 	sprite.onclick(x, y);
		// }
		this.turtle.onclick(x,y);
	}

	move(dx:number, dy:number) 
	{
		this.turtle.move(dx, dy);
	}
}




class View
{
	model:Model;
	canvas = document.getElementById("myCanvas") as HTMLCanvasElement;

	constructor(model:Model) 
	{
		this.model = model;
		let turtle = new Image();
		turtle.src = "blue_robot.png";
	}

	update() 
	{
		let ctx = this.canvas.getContext("2d") as CanvasRenderingContext2D;
		ctx.clearRect(0, 0, 1000, 500);
		for (const sprite of this.model.sprites) {
			ctx.drawImage(sprite.image, sprite.x - sprite.image.width / 2, sprite.y - sprite.image.height);
		}
	}
}







class Controller
{
	key_right = false;
	key_left = false;
	key_up = false;
	key_down = false;
	model:Model;
	view:View;
	last_updates_request_time = 0;
	
	constructor(model:Model, view:View) 
	{
		this.model = model;
		this.view = view;
		let self = this;
		view.canvas.addEventListener("click", function(event) { self.onClick(event); });
		document.addEventListener('keydown', function(event) { self.keyDown(event); }, false);
		document.addEventListener('keyup', function(event) { self.keyUp(event); }, false);
	}

	onClick(event:MouseEvent)
	{
		const x = event.pageX - this.view.canvas.offsetLeft;
		const y = event.pageY - this.view.canvas.offsetTop;
		this.model.onclick(x, y);

		httpPost('radio', {
			id: g_id,
			action: 'userclicked',
			x: x,
			y: y,
		}, this.onAcknowledgeClick);
	}

	keyDown(event:KeyboardEvent) 
	{
		if(event.keyCode == 39) this.key_right = true;
		else if(event.keyCode == 37) this.key_left = true;
		else if(event.keyCode == 38) this.key_up = true;
		else if(event.keyCode == 40) this.key_down = true;
	}

	keyUp(event:KeyboardEvent) 
	{
		if(event.keyCode == 39) this.key_right = false;
		else if(event.keyCode == 37) this.key_left = false;
		else if(event.keyCode == 38) this.key_up = false;
		else if(event.keyCode == 40) this.key_down = false;
	}

	onAcknowledgeClick(ob: any) {
		console.log(`Response to move: ${JSON.stringify(ob)}`);
	}

	on_receive_updates(ob: any)
	{
		console.log(`ob = ${JSON.stringify(ob)}`);
		//ob = {"updates": [["id" , x, posY], ["id" , posX, posY], ["id" , posX, posY]]}
		for (let i = 0; i < ob.updates.length; i++)
		{
			let update = ob.updates [i];
			let id = update.id;
			let x = update.x;
			let y = update.y;


			let s = id_to_sprite[id];
			if (s === undefined) {
				s = new Sprite(x, y, "green_robot.png", Sprite.prototype.go_toward_destination, Sprite.prototype.ignore_click);
				id_to_sprite[id] = s;
				this.model.sprites.push(s);
			}
			s.set_destination(x, y);
			

			// find the sprite with id "id"
			// (if there isnt one, make one)
			// sprite.setDestination (x,y);

			// add to mapping
			// id_to_sprite[id] = sprite;

			// reading from mapping
			// sprite = id_to_sprite[id];
			
			
		}
	}

	request_update()
	{
		let payload =
		{
			action: "needupdate",
			id: g_id
		}
		httpPost("radio", payload, (ob) => this.on_receive_updates(ob));
	}

	update() 
	{
		this.last_updates_request_time++;
		let dx = 0;
		let dy = 0;
        let speed = this.model.turtle.speed;
		if(this.key_right) dx += speed;
		if(this.key_left) dx -= speed;
		if(this.key_up) dy -= speed;
		if(this.key_down) dy += speed;
		if(dx != 0 || dy != 0)
			this.model.move(dx, dy);

		const time = Date.now();
		if (time - this.last_updates_request_time >= 1000) {
		  this.last_updates_request_time = time;
		  this.request_update();
		}
	}
}






class Game 
{
	model:Model;
	view:View;
	controller:Controller;

	constructor() 
	{
		this.model = new Model();
		this.view = new View(this.model);
		this.controller = new Controller(this.model, this.view);
	}

	onTimer() 
	{
		this.controller.update();
		this.model.update();
		this.view.update();
	}
}


const game = new Game();
const timer = setInterval(() => { game.onTimer(); }, 40);

