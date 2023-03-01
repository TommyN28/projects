// Tommy Ngo
// 2/27
// Assignment 3: Map Editor

import javax.swing.JPanel;
import java.awt.Graphics;
import java.awt.image.BufferedImage;
import javax.imageio.ImageIO;
import java.io.IOException;
import java.io.File;
import java.awt.Color;

class View extends JPanel
{
	BufferedImage tile_image;
	Model model;
	int roomX;
	int roomY;
	int scrollPosX = 0;
	int scrollPosY = 0;

	View(Controller c, Model m)
	{
		model = m;
		c.setView(this);
		
		try
		{
			this.tile_image = ImageIO.read(new File("tile.jpg"));
		}
		catch(Exception e) 
		{
			e.printStackTrace(System.err);
			System.exit(1);
		}
	}

	public void paintComponent(Graphics g)
	{
		g.setColor(new Color(128, 255, 255));
		g.fillRect(0, 0, this.getWidth(), this.getHeight());
		for(int i = 0; i < model.tiles.size(); i++)
		{
			Tile t = model.tiles.get(i);
			g.drawImage(tile_image, t.x - scrollPosX, t.y - scrollPosY, null);
		}
	}
}
