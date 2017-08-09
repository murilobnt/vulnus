#ifndef _INGAMETIME_HPP_
#define _INGAMETIME_HPP_

#include <SFML/Graphics.hpp>

#include "generics/controlableentity.hpp"
#include "entities/clock/generictimehandler.hpp"
#include "structures/inttostring.hpp"
#include "structures/colorgetter.hpp"
#include "structures/weekcontainer.hpp"
#include "structures/backgroundcolorcontainer.hpp"
#include "structures/filtercolorcontainer.hpp"
#include "enums/daytime.hpp"

#define TIMECYCLE 5.f
#define INITIALH 6
#define INITIALM 0

class InGameTime : public ControlableEntity {
private:
	sf::Text text;
	sf::Font font;

	sf::Sprite filter;
	sf::RenderTexture renderTexture;

	FilterColorContainer filterCC;
	BackgroundColorContainer bgCC;

	short timeReseter;

	short minutes;
	short hours;
	short timeIncreaser;

	GenericTimeHandler timeCycle;

	bool mode12;
	bool am;

	DayTime dayTime;
	WeekContainer weekContainer;	

	bool hasGameBg;
	sf::Sprite* gameBackground;

	void setTimeText(std::string hours, std::string minutes);
	void changeDayTime();
	void dayTimeChange();

	void init(bool mode12, bool hasGameBg);

public:
	InGameTime(bool mode12 = false);
	InGameTime(sf::Sprite* gameBackground, bool mode12 = false);
	sf::Text& getText();
	GenericTimeHandler& getTimeHandler();
	void updateTime();

	void set12Mode();
	void set24Mode();

	void setTime(short hours, short minutes);
	void setGameBackground(sf::Sprite* gameBackground);

	DayTime getDayTime();
	sf::Sprite& getFilter();

	void clearRenderTexture();
	
	ColorContainer& getFilterCC();
	ColorContainer& getBgCC();

	void controlEntity(sf::Keyboard::Key key, bool release);
};

#endif