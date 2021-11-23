#pragma once


class Time 
{

	int hours;
	int minutes;
	double seconds;

public:

	Time();

	Time(int, int, double);
	~Time();

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


};
