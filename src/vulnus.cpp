#include <SFML/Graphics.hpp>
#include "heart/vulnus.hpp"
#include "const/config.hpp"

int main(){
	Game game(GAMEWIDTH, GAMEHEIGHT, "Vulnus");
	game.gameStart();
	return 0;
}
