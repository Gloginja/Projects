#pragma once
#include <string>

class Time 
{

	int hours;
	int minutes;
	double seconds;

public:

	Time();

	Time(int, int, double);
	~Time();

	std::string toString();

	int getHours() {
		return this->hours;
	}
	int getMinutes() {
		return this->minutes;
	}
	double getSeconds() {
		return this->seconds;
	}

	void setHours(int _hours) {
		this->hours = _hours;
	}
	void setMinutes(int _minutes) {
		this->minutes = _minutes;
	}
	void setSeconds(double _seconds) {
		this->seconds = _seconds;
	}
	double getTimeInSeconds();

	void setTimeWithSeconds(double seconds);

	std::string getWhole(double num);

	std::string getDecimal3(double num);
};
