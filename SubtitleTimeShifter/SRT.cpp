#include "SRT.h"
#include <regex>


SRT::SRT(string path)
{
	this->setFilePath(path);
	this->list = new List<SRTComponent*>();
	this->fhandle = nullptr;
}


void SRT::loadFile()
{
	this->fhandle->open(filePath);
	string tmp;
	int tmpId;
	Time* tmpBegin = nullptr;
	Time* tmpEnd = nullptr;
	string tmpText = "";
	while (!fhandle->eof())
	{
		getline(*fhandle, tmp);
		tmpId = stoi(tmp);
		smatch sm;
		if (regex_search(tmp, sm, regex("(.*):(.*):(.*) --> (.*):(.*):(.*)")))
		{
			tmpBegin = new Time(stoi(sm[0]), stoi(sm[1]), stod(sm[2]));
			tmpEnd = new Time(stoi(sm[3]), stoi(sm[4]), stod(sm[5]));
		}
		
		getline(*fhandle, tmp);
		tmpText = tmp;
		while (tmp != "")
		{
			getline(*fhandle, tmp);
			tmpText += tmp;
		}

		SRTComponent* tmpCmp = new SRTComponent(tmpId, *tmpBegin, *tmpEnd, tmpText);
		list->append(tmpCmp);
	}
}