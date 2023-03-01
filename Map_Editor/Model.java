// Tommy Ngo
// 2/27
// Assignment 3: Map Editor

import java.util.ArrayList;

class Model
{
	ArrayList<Tile> tiles;

	Model()
	{
		tiles = new ArrayList<Tile>();
	}

	public void addTile(int mouseX, int mouseY)
	{
		boolean foundTile = false;
		for(int i = 0; i < tiles.size(); i++)
		{
			if(tiles.get(i).tileCheck(mouseX, mouseY))
			{
				// Debug statement to verify tileCheck works
				//System.out.println("Clicking on tile");
	
				tiles.remove(i);
				i = tiles.size();
				foundTile = true;
				break;
			}
		}
		if(!foundTile)
		{
			// Debug statement to verify tileCheck works
			//System.out.println("No tile here");

			int snapX = mouseX - mouseX % 50;
			int snapY = mouseY - mouseY % 50;
			tiles.add(new Tile (snapX, snapY));
		}
		
		
	}
	public void update()
	{
		
	}

	Json marshal()
	{
		Json ob = Json.newObject();
		Json tmpList = Json.newList();
		ob.add("tiles", tmpList);
		for(int i = 0; i < tiles.size(); i++)
			tmpList.add(tiles.get(i).marshal());
		return ob;
	}

	void unmarshal(Json ob)
	{
		tiles = new ArrayList<Tile>();
		Json tmpList = ob.get("tiles");
		for (int i = 0; i < tmpList.size(); i++)
		{
			tiles.add(new Tile(tmpList.get(i)));
		}

	}

}