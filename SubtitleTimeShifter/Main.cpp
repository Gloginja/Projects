#include <iostream>
#include "SRT.h"
#include <regex>
using namespace std;

int main() {

	//List<int>Lista();
	SRT* test = new SRT("primer.srt");
	test->loadFile();


	return 0;
}