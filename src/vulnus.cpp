#include <SFML/Graphics.hpp>
#include "game.hpp"

int main(){
	Game game(640, 480, "Vulnus");
	game.gameStart();
	return 0;
}
