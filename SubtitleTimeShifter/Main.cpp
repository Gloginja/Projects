#include <iostream>
#include "SRT.h"
#include <regex>
#include <fstream>
using namespace std;

int main() {

	//List<int>Lista();
	SRT* test = new SRT("primer.srt");
	test->loadFile();
	//FILE* lol = fopen("primer.srt","r");
	test->saveFile();
	//cout << stof("4.323");
	return 0;
}