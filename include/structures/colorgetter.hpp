#ifndef _COLORGETTER_HPP_
#define _COLORGETTER_HPP_

#include <SFML/Graphics.hpp>

#include "enums/daytime.hpp"

namespace ColorGetter{
	sf::Color GetScreenFilterColorToDayTime(DayTime Period);
};

#endif