// Tommy Ngo
// 2/27
// Assignment 3: Map Editor

public class Tile 
{
    int x;
    int y;
    final static int w = 50;
    final static int h = 50;
    
    Tile(int x, int y)
    {
        this.x = x;
        this.y = y;
    }

    // Unmarshaling constructor
    Tile(Json ob)
    {
        x = (int)ob.getLong("x");
        y = (int)ob.getLong("y");
    }

    public boolean tileCheck (int mouseX, int mouseY)
    {
        if (mouseX >= x && mouseX <= x+w && mouseY >= y && mouseY <= y+h)
            return true;
        else
            return false;
    }

    Json marshal()
    {
        Json ob = Json.newObject();
        ob.add("x", x);
        ob.add("y", y);
        return ob;
    }

}
