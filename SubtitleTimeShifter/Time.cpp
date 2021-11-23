#include "Time.h"
#include <iostream>
Time::Time(int _hours, int _minutes, double _seconds) {
	setHours(_hours);
	setMinutes(_minutes);
	setSeconds(_seconds);

}

Time::Time() {
	
}

Time::~Time() {
	
}