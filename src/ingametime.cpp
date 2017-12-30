#include "structures/ingametime.hpp"

void InGameTime::setTimeText(std::string hours, std::string minutes){
	if(this->hours < 10)
		hours = "0" + hours;

	if(this->minutes == 0)
		minutes = "0" + minutes;

	if(mode12){
		std::string period;

		if(am)
			period = "AM";
		else
			period = "PM";

		text.setString(weekContainer.getDofwText() + "\n" + hours + ":" + minutes + " " + period);
	} else {
		text.setString(weekContainer.getDofwText() + "\n" + hours + ":" + minutes);
	}
}

void InGameTime::changeDayTime(){
	if(!mode12){
		if(hours >= 6 && hours < 12){
			dayTime = MORNING;
		} else if(hours >= 12 && hours < 18){
			dayTime = AFTERNOON;
		} else if(hours >= 18 && hours < 22){
			dayTime = EVENING;
		} else {
			dayTime = NIGHT;
		}
	} else {
		if(am){
			if(hours >= 6){
				dayTime = MORNING;
			} else {
				dayTime = NIGHT;
			}
		} else {
			if(hours >= 0 && hours < 6){
				dayTime = AFTERNOON;
			} else if(hours >= 6 && hours < 10){
				dayTime = EVENING;
			} else {
				dayTime = NIGHT;
			}
		}
	}

	if(hasGameBg)
		gameBackground->setColor(ColorGetter::GetBackgroundFilterColorToDayTime(dayTime));
	
	filter.setColor(ColorGetter::GetScreenFilterColorToDayTime(dayTime));
}

void InGameTime::dayTimeChange(){
	bool changed = false;

	if(!mode12){
		if(hours == 6){
			dayTime = MORNING;
			changed = true;
		}
		if(hours == 12){
			dayTime = AFTERNOON;
			changed = true;
		}
		if(hours == 18){
			dayTime = EVENING;
			changed = true;
		}
		if(hours == 22){
			dayTime = NIGHT;
			changed = true;
		}
	} else {
		if(!am){
			if(hours == 0){
				dayTime = AFTERNOON;
				changed = true;
			}
			if(hours == 6){
				dayTime = EVENING;
				changed = true;
			}
			if(hours == 10){
				dayTime = NIGHT;
				changed = true;
			}
		} else {
			if(hours == 6){
				dayTime = MORNING;
				changed = true;
			}
		}
	}

	if(changed){
		if(hasGameBg)
			bgCC.setTransitionTo(dayTime);

		filterCC.setTransitionTo(dayTime);
	}
}

void InGameTime::init(bool mode12, bool hasGameBg){
	this->hasGameBg = hasGameBg;

	renderTexture.create(GAMEWIDTH, GAMEHEIGHT);
	filter = sf::Sprite(renderTexture.getTexture());

	this->font.loadFromFile("fonts/Ubuntu-C.tff");

	this->text = sf::Text(std::string(""), font);
	this->text.setColor(sf::Color::Blue);
	this->text.setPosition(sf::Vector2f(400, 300));
	this->text.setCharacterSize(20);
	this->hours = INITIALH;
	this->minutes = INITIALM;

	this->mode12 = mode12;

	if(mode12){
		this->timeReseter = 12;
		if(this->hours >= timeReseter){
			am = false;
		} else {
			am = true;
		}
		this->hours = this->hours % this->timeReseter;
		this->hours = (this->hours % this->timeReseter == 0) ? 0 : this->hours;
	}
	else{
		this->timeReseter = 24;
	}

	changeDayTime();
	setTimeText(IntToString::IntToString(hours), IntToString::IntToString(minutes*10));
}

InGameTime::InGameTime(bool mode12) : 
timeCycle(sf::seconds(TIMECYCLE)),
filterCC(&this->filter),
bgCC(this->gameBackground)
{
	init(mode12, false);
}

InGameTime::InGameTime(sf::Sprite* gameBackground, bool mode12) : 
timeCycle(sf::seconds(TIMECYCLE)),
filterCC(&this->filter),
bgCC(gameBackground)
{
	this->gameBackground = gameBackground;
	init(mode12, true);
}

sf::Text& InGameTime::getText(){
	return this->text;
}

GenericTimeHandler& InGameTime::getTimeHandler(){
	return this->timeCycle;
}

void InGameTime::updateTime(){
	minutes++;
	if(minutes % 6 == 0){
		minutes = 0;
		hours++;

		if(mode12){
			if(hours % timeReseter == 0){
				if(!am){
					weekContainer.incrementDofw();
				}
				am = !am;
			}
		} else {
			if(hours % timeReseter == 0){
				weekContainer.incrementDofw();
			}
		}

		hours = (hours % timeReseter == 0) ? 0 : hours;

		dayTimeChange();
	}

	setTimeText(IntToString::IntToString(hours), IntToString::IntToString(minutes*10));
}

void InGameTime::set12Mode(){
	this->mode12 = true;
	this->timeReseter = 12;
	if(hours >= 12){
		am = false;
	}
}

void InGameTime::set24Mode(){
	this->mode12 = false;

	if(!am)
		hours += 12;

	this->timeReseter = 24;
}

void InGameTime::setTime(short hours, short minutes){
	this->hours = hours;
	this->minutes = minutes;
}

void InGameTime::setGameBackground(sf::Sprite* gameBackground){
	this->gameBackground = gameBackground;
}

DayTime InGameTime::getDayTime(){
	return this->dayTime;
}

sf::Sprite& InGameTime::getFilter(){
	return this->filter;
}

void InGameTime::clearRenderTexture(){
	renderTexture.clear(sf::Color::White);
	renderTexture.display();
}

ColorContainer& InGameTime::getFilterCC(){
	return this->filterCC;
}

ColorContainer& InGameTime::getBgCC(){
	return this->bgCC;
}

void InGameTime::controlEntity(sf::Keyboard::Key key, bool release){
	switch(key){
		case sf::Keyboard::Num1:
			this->timeCycle.setFps(sf::seconds(5.f));
		break;
		case sf::Keyboard::Num2:
			this->timeCycle.setFps(sf::seconds(2.f));
		break;
		case sf::Keyboard::Num3:
			this->timeCycle.setFps(sf::seconds(0.3f));
		break;
	}
}