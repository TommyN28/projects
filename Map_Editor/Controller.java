// Tommy Ngo
// 2/27
// Assignment 3: Map Editor

import java.awt.event.MouseListener;
import java.awt.event.MouseEvent;
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;
import java.awt.event.KeyListener;
import java.awt.event.KeyEvent;

class Controller implements ActionListener, MouseListener, KeyListener
{
	View view;
	Model model;

	boolean keyLeft;
	boolean keyRight;
	boolean keyUp;
	boolean keyDown;

	Controller(Model m)
	{
		model = m;
	}

	public void actionPerformed(ActionEvent e)
	{
		
	}

	void setView(View v)
	{
    	view = v;
	}
	
	public void mousePressed(MouseEvent e)
	{
		model.addTile(e.getX() + view.scrollPosX, e.getY() + view.scrollPosY);
	}

	public void mouseReleased(MouseEvent e) {	 }
	public void mouseEntered(MouseEvent e) {    }
	public void mouseExited(MouseEvent e) {    }
	public void mouseClicked(MouseEvent e) {    }

	public void keyPressed(KeyEvent e)
	{
		switch(e.getKeyCode())
		{
			case KeyEvent.VK_RIGHT: keyRight = true; break;
			case KeyEvent.VK_LEFT: keyLeft = true; break;
			case KeyEvent.VK_UP: keyUp = true; break;
			case KeyEvent.VK_DOWN: keyDown = true; break;
		}
	}

	public void keyReleased(KeyEvent e)
	{
		switch(e.getKeyCode())
		{
			case KeyEvent.VK_RIGHT: keyRight = false; break;
			case KeyEvent.VK_LEFT: keyLeft = false; break;
			case KeyEvent.VK_UP: keyUp = false; break;
			case KeyEvent.VK_DOWN: keyDown = false; break;
			
			// Quit program if user presses escape key
			case KeyEvent.VK_ESCAPE: System.exit(0);
		}

		char c = Character.toLowerCase(e.getKeyChar());

		// Quit program if user presses q key
		if (c =='q')
			System.exit(0);
		
		// --------------------------------------------------
		// Keys for scrolling left/right, up/down the window from room to room
		// --------------------------------------------------
		if(c == 'd')
		{
			if(view.scrollPosX < 700)
			{
				view.scrollPosX += 700;
				//Debug statements to check for funtionality
				//System.out.println("scrolling right");
				//System.out.println("scrollPosX = " + view.scrollPosX);
				//System.out.println("scrollPosY = " + view.scrollPosY);
			}
		}
		if(c == 'a')
		{	
			if(view.scrollPosX > 0)
			{
				view.scrollPosX -= 700;
				//Debug statements to check for funtionality
				//System.out.println("scrolling left");
				//System.out.println("scrollPosX = " + view.scrollPosX);
				//System.out.println("scrollPosY = " + view.scrollPosY);
			}
		}
		if(c == 'x')
		{
			if(view.scrollPosY < 500)
			{
				view.scrollPosY += 500;
				//Debug statements to check for funtionality
				//System.out.println("scrolling down");
				//System.out.println("scrollPosX = " + view.scrollPosX);
				//System.out.println("scrollPosY = " + view.scrollPosY);
			}
		}
		if(c == 'w')
		{
			if(view.scrollPosY > 0)
			{
				view.scrollPosY -= 500;
				//Debug statements to check for funtionality
				//System.out.println("scrolling up");
				//System.out.println("scrollPosX = " + view.scrollPosX);
				//System.out.println("scrollPosY = " + view.scrollPosY);
			}
		}
		
		// --------------------------------------------------
		// Keys to save/load tiles to/from map.json
		// --------------------------------------------------
		if (c == 's')
		{
			Json saveObject = model.marshal();
			saveObject.save("map.json");
			System.out.println("Tiles saved to map");
		}
		if(c == 'l')
		{
			Json j = Json.load("map.json");
			model.unmarshal(j);
			System.out.println("Tiles loaded from map");
		}

	}

	public void keyTyped(KeyEvent e)
	{
	}

	void update()
	{
		
	}
}
