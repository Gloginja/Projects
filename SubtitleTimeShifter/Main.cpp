#include <iostream>
#include "SRT.h"
#include <regex>
#include <fstream>
using namespace std;

int main() {

	//List<int>Lista();
	SRT* test = new SRT("primer.srt",-1);
	test->loadFile();
	test->shift();
	test->saveFile();
	
	return 0;
}