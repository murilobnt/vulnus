#ifndef _INGAMETIME_HPP_
#define _INGAMETIME_HPP_

#include <SFML/Graphics.hpp>

#include "entities/clock/generictimehandler.hpp"
#include "structures/inttostring.hpp"
#include "structures/colorgetter.hpp"
#include "enums/daytime.hpp"

class InGameTime {
private:
	sf::Text text;
	sf::Font font;

	sf::Sprite filter;
	sf::RenderTexture renderTexture;

	short timeReseter;

	short minutes;
	short hours;
	short timeIncreaser;

	GenericTimeHandler timeCycle;
	bool mode12;

	bool am;
	DayTime dayTime;

	void setTimeText(std::string hours, std::string minutes);
	void changeDayTime();
	void dayTimeChange();
public:
	InGameTime(bool mode12 = false);
	sf::Text& getText();
	GenericTimeHandler& getTimeHandler();
	void updateTime();

	void set12Mode();
	void set24Mode();

	void setTime(short hours, short minutes);

	DayTime getDayTime();
	sf::Sprite& getFilter();

	void clearRenderTexture();

};

#endif