from typing import Mapping, Any, List, Dict, Tuple
import os
from http_daemon import delay_open_url, serve_pages

class Player():
        def __init__ (self, id:str) -> None:
                self.id = id
                self.x = 0
                self.y = 0
                self.what_i_know = 0

players: Dict[str, Player] = {}
history: List[Player] = []

def find_player(id):
    for i in range(len(players)):
        if id == players[i]:
            return players[i]

def update(payload: Mapping[str, Any]) -> Mapping[str, Any]:
    
    action = payload["action"]
    if action == "userclicked":
        player = find_player(payload["id"])
        player.x = payload["x"]
        player.y = payload["y"]
        history.append(player)
        return {
            'message': 'done',
        }
    elif action == "needupdate":
        player = find_player(payload["id"])
        remaining_history = history[player.what_i_know:]
        player.what_i_know = len(history)
        updates = List[Dict[str, int, int]] = []
        for i in range(len(remaining_history)):
            player = remaining_history[i]
            updates.append({"id":player.id, "x":player.x, "y":player.y})
        return {
            "updates": updates
        }
    # else:
    #     raise ValueError("Bad action")
    print(f'update was called with {payload}')
    
    

def main() -> None:
    # Get set up
    os.chdir(os.path.join(os.path.dirname(__file__), '../front_end'))

    # Serve pages
    port = 8987
    delay_open_url(f'http://127.0.0.1:{port}/game.html', .1)
    serve_pages(port, {
        'radio': update,
    })

if __name__ == "__main__":
    main()
