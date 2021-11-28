#include "Time.h"
#include <regex>


using namespace std;

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

string Time::toString()
{
	string tmp = "";
	if (this->getHours() < 10) tmp += '0' + to_string(getHours()) + ':'; else tmp += to_string(getHours()) + ':';
	if (this->getMinutes() < 10) tmp += '0' + to_string(getMinutes()) + ':'; else tmp += to_string(getMinutes()) + ':';
	if (this->getSeconds() < 10)
		tmp += '0' + this->getWhole(getSeconds()) + ',' + this->getDecimal3(getSeconds()); 
	else 
		tmp += this->getWhole(getSeconds()) + ',' + this->getDecimal3(getSeconds());

	return tmp;
}

string Time::getWhole(double num)
{
	smatch sm;
	string tmp = to_string(this->seconds);
	if (regex_search(tmp, sm, regex("(.*)\\.(.*)")))
	{
		return sm[1].str();
	}
	else return "error";

}

string Time::getDecimal3(double num)
{
	smatch sm;
	string tmp = to_string(this->seconds);
	if (regex_search(tmp, sm, regex("(.*)\\.(.*)")))
	{
		tmp = sm[2].str();
		tmp.resize(tmp.length() - 3);
		return tmp;
	}
	else return "error";
}

double Time::getTimeInSeconds()
{
	return getHours()*3600 + getMinutes() * 60 + getSeconds();
}

void Time::setTimeWithSeconds(double num)
{
	setHours((int)num / 3600);
	num -= getHours() * 3600;
	setMinutes((int)num / 60);
	num -= getMinutes() * 60;
	setSeconds(num);
}
