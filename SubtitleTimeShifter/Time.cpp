#include "Time.h"
#include <iostream>
Time::Time(int _hours, int _minutes, double _seconds) 
{
	setHours(_hours);
	setMinutes(_minutes);
	setSeconds(_seconds);

}

Time::Time() 
{
}

Time::~Time() 
{
}

std::string Time::toString()
{
	std::string tmp = "";
	if (this->getHours() < 10) tmp += '0' + std::to_string(getHours()) + ':'; else tmp += std::to_string(getHours()) + ':';
	if (this->getMinutes() < 10) tmp += '0' + std::to_string(getMinutes()) + ':'; else tmp += std::to_string(getMinutes()) + ':';
	if (this->getSeconds() < 10) tmp += '0' + std::to_string(getSeconds()); else tmp += std::to_string(getSeconds());

	return tmp;
}