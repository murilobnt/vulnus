#ifndef _WEEKCONTAINER_HPP_
#define _WEEKCONTAINER_HPP_

#include "enums/dayoftheweek.hpp"
#include <string>
#include <iostream>

class WeekContainer {
private:
	int currentDofw;
	DayOfTheWeek dofw;

public:
	WeekContainer();
	WeekContainer(DayOfTheWeek);

	void incrementDofw();
	void setDofw(DayOfTheWeek);

	DayOfTheWeek getDofw();
	std::string getDofwText();
};

#endif