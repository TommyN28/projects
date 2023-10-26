"use strict";
var __spreadArray = (this && this.__spreadArray) || function (to, from, pack) {
    if (pack || arguments.length === 2) for (var i = 0, l = from.length, ar; i < l; i++) {
        if (ar || !(i in from)) {
            if (!ar) ar = Array.prototype.slice.call(from, 0, i);
            ar[i] = from[i];
        }
    }
    return to.concat(ar || Array.prototype.slice.call(from));
};
var random_id = function (len) {
    var p = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
    return __spreadArray([], Array(len), true).reduce(function (a) { return a + p[Math.floor(Math.random() * p.length)]; }, '');
};
var g_origin = new URL(window.location.href).origin;
var g_id = random_id(12);
// Payload is a marshaled (but not JSON-stringified) object
// A JSON-parsed response object will be passed to the callback
var httpPost = function (page_name, payload, callback) {
    var request = new XMLHttpRequest();
    request.onreadystatechange = function () {
        if (request.readyState === 4) {
            if (request.status === 200) {
                var response_obj = void 0;
                try {
                    response_obj = JSON.parse(request.responseText);
                }
                catch (err) { }
                if (response_obj) {
                    callback(response_obj);
                }
                else {
                    callback({
                        status: 'error',
                        message: 'response is not valid JSON',
                        response: request.responseText,
                    });
                }
            }
            else {
                if (request.status === 0 && request.statusText.length === 0) {
                    callback({
                        status: 'error',
                        message: 'connection failed',
                    });
                }
                else {
                    callback({
                        status: 'error',
                        message: "server returned status ".concat(request.status, ": ").concat(request.statusText),
                    });
                }
            }
        }
    };
    request.open('post', "".concat(g_origin, "/").concat(page_name), true);
    request.setRequestHeader('Content-Type', 'application/json');
    request.send(JSON.stringify(payload));
};
var Sprite = /** @class */ (function () {
    function Sprite(x, y, image_url, update_method, onclick_method) {
        this.dest_x = 0;
        this.dest_y = 0;
        this.speed = 4;
        this.image = new Image();
        this.x = x;
        this.y = y;
        this.dest_x = x;
        this.dest_y = y;
        this.image.src = image_url;
        this.update = update_method;
        var onclick = onclick_method;
    }
    Sprite.prototype.set_destination = function (x, y) {
        this.dest_x = x;
        this.dest_y = y;
    };
    Sprite.prototype.ignore_click = function (x, y) {
    };
    Sprite.prototype.move = function (dx, dy) {
        this.dest_x = this.x + dx;
        this.dest_y = this.y + dy;
    };
    Sprite.prototype.go_toward_destination = function () {
        if (this.dest_x === undefined)
            return;
        if (this.x < this.dest_x)
            this.x += Math.min(this.dest_x - this.x, this.speed);
        else if (this.x > this.dest_x)
            this.x -= Math.min(this.x - this.dest_x, this.speed);
        if (this.y < this.dest_y)
            this.y += Math.min(this.dest_y - this.y, this.speed);
        else if (this.y > this.dest_y)
            this.y -= Math.min(this.y - this.dest_y, this.speed);
    };
    Sprite.prototype.sit_still = function () {
    };
    Sprite.prototype.onclick = function (x, y) {
        this.set_destination(x, y);
    };
    return Sprite;
}());
var id_to_sprite = {};
var Model = /** @class */ (function () {
    function Model() {
        this.sprites = [];
        this.sprites.push(new Sprite(200, 100, "lettuce.png", Sprite.prototype.sit_still, Sprite.prototype.ignore_click));
        this.turtle = new Sprite(50, 50, "blue_robot.png", Sprite.prototype.go_toward_destination, Sprite.prototype.set_destination);
        this.sprites.push(this.turtle);
        id_to_sprite[g_id] = this.turtle;
    }
    Model.prototype.update = function () {
        for (var _i = 0, _a = this.sprites; _i < _a.length; _i++) {
            var sprite = _a[_i];
            sprite.update();
        }
    };
    Model.prototype.onclick = function (x, y) {
        // for (const sprite of this.sprites) {
        // 	sprite.onclick(x, y);
        // }
        this.turtle.onclick(x, y);
    };
    Model.prototype.move = function (dx, dy) {
        this.turtle.move(dx, dy);
    };
    return Model;
}());
var View = /** @class */ (function () {
    function View(model) {
        this.canvas = document.getElementById("myCanvas");
        this.model = model;
        var turtle = new Image();
        turtle.src = "blue_robot.png";
    }
    View.prototype.update = function () {
        var ctx = this.canvas.getContext("2d");
        ctx.clearRect(0, 0, 1000, 500);
        for (var _i = 0, _a = this.model.sprites; _i < _a.length; _i++) {
            var sprite = _a[_i];
            ctx.drawImage(sprite.image, sprite.x - sprite.image.width / 2, sprite.y - sprite.image.height);
        }
    };
    return View;
}());
var Controller = /** @class */ (function () {
    function Controller(model, view) {
        this.key_right = false;
        this.key_left = false;
        this.key_up = false;
        this.key_down = false;
        this.last_updates_request_time = 0;
        this.model = model;
        this.view = view;
        var self = this;
        view.canvas.addEventListener("click", function (event) { self.onClick(event); });
        document.addEventListener('keydown', function (event) { self.keyDown(event); }, false);
        document.addEventListener('keyup', function (event) { self.keyUp(event); }, false);
    }
    Controller.prototype.onClick = function (event) {
        var x = event.pageX - this.view.canvas.offsetLeft;
        var y = event.pageY - this.view.canvas.offsetTop;
        this.model.onclick(x, y);
        httpPost('radio', {
            id: g_id,
            action: 'userclicked',
            x: x,
            y: y,
        }, this.onAcknowledgeClick);
    };
    Controller.prototype.keyDown = function (event) {
        if (event.keyCode == 39)
            this.key_right = true;
        else if (event.keyCode == 37)
            this.key_left = true;
        else if (event.keyCode == 38)
            this.key_up = true;
        else if (event.keyCode == 40)
            this.key_down = true;
    };
    Controller.prototype.keyUp = function (event) {
        if (event.keyCode == 39)
            this.key_right = false;
        else if (event.keyCode == 37)
            this.key_left = false;
        else if (event.keyCode == 38)
            this.key_up = false;
        else if (event.keyCode == 40)
            this.key_down = false;
    };
    Controller.prototype.onAcknowledgeClick = function (ob) {
        console.log("Response to move: ".concat(JSON.stringify(ob)));
    };
    Controller.prototype.on_receive_updates = function (ob) {
        console.log("ob = ".concat(JSON.stringify(ob)));
        //ob = {"updates": [["id" , x, posY], ["id" , posX, posY], ["id" , posX, posY]]}
        for (var i = 0; i < ob.updates.length; i++) {
            var update = ob.updates[i];
            var id = update.id;
            var x = update.x;
            var y = update.y;
            var s = id_to_sprite[id];
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
    };
    Controller.prototype.request_update = function () {
        var _this = this;
        var payload = {
            action: "needupdate",
            id: g_id
        };
        httpPost("radio", payload, function (ob) { return _this.on_receive_updates(ob); });
    };
    Controller.prototype.update = function () {
        this.last_updates_request_time++;
        var dx = 0;
        var dy = 0;
        var speed = this.model.turtle.speed;
        if (this.key_right)
            dx += speed;
        if (this.key_left)
            dx -= speed;
        if (this.key_up)
            dy -= speed;
        if (this.key_down)
            dy += speed;
        if (dx != 0 || dy != 0)
            this.model.move(dx, dy);
        var time = Date.now();
        if (time - this.last_updates_request_time >= 1000) {
            this.last_updates_request_time = time;
            this.request_update();
        }
    };
    return Controller;
}());
var Game = /** @class */ (function () {
    function Game() {
        this.model = new Model();
        this.view = new View(this.model);
        this.controller = new Controller(this.model, this.view);
    }
    Game.prototype.onTimer = function () {
        this.controller.update();
        this.model.update();
        this.view.update();
    };
    return Game;
}());
var game = new Game();
var timer = setInterval(function () { game.onTimer(); }, 40);
