#pragma once
#include <string>
#include "List.h"
#include "SRTComponent.h"
#include <fstream>
using namespace std;


class SRT 
{
	string filePath;
	double secondsShift;
	List<SRTComponent*>* list;
	ifstream* fhandle;
 public:

	 SRT(string);

	 void loadFile();

	 void shift();

	 void saveFile();

	 string getFilePath()
	 {
		 return this->filePath;
	 }

	 double getShift()
	 {
		 return this->secondsShift;
	 }

	 List<SRTComponent*>* getList()
	 {
		 return this->list;
	 }

	 void setFilePath(string _path)
	 {
		 this->filePath = _path;
	 }

	 void setShift(double _shift)
	 {
		 this->secondsShift = _shift;
	 }
};
