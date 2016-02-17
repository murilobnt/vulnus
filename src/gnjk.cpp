#include <SFML/Graphics.hpp>
#include "Game.h"

/*int main()
{
    sf::RenderWindow window(sf::VideoMode(640, 480), "SFML works!");
    Game game(640, 480, "BUNDA");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(shape);
        window.display();
    }

    return 0;
}*/

int main(){
	Game game(640, 480, "GNJK");
	//sf::CircleShape shape(100.f);
    //shape.setFillColor(sf::Color::Green);
    //game.addShape(shape);

    game.gameStart();
    return 0;
}
