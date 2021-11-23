#pragma once
#include <string>
#include "Time.h"


using namespace std;



class SRTComponent 
{
	int id;
	Time begin;
	Time end;
	string text;

 public:

	 SRTComponent();

	 SRTComponent(int, Time, Time, string);

	 int getID() {
		 return this->id;
	 }

	 Time getBegin() {
		 return this->begin;
	 }

	 Time getEnd() {
		 return this->end;
	 }

	 string getText() {
		 return this->text;
	 }

	 void setID(int _id) {
		 this->id = _id;
	 }

	 void setBegin(Time _begin) {
		 this->begin = _begin;
	 }

	 void setEnd(Time _end) {
		 this->end = _end;
	 }

	 void setText(string _text) {
		 this->text = _text;
	 }


};
