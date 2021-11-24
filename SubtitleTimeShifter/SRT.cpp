#include "SRT.h"
#include <regex>


SRT::SRT(string path)
{
	this->setFilePath(path);
	this->list = new List<SRTComponent*>();
	this->fhandle = new fstream();
}


void SRT::loadFile()
{
	this->fhandle->open(filePath, fstream::in);
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
		string hours;
		string minutes;
		string seconds;
		getline(*fhandle, tmp);
		if (regex_search(tmp, sm, regex("(.*):(.*):(.*) --> (.*):(.*):(.*)")))
		{
			hours = sm[1].str();
			minutes = sm[2].str();
			seconds = sm[3].str();
			seconds[2] = '.';
			tmpBegin = new Time(stoi(hours), stoi(minutes), stod(seconds));
			hours = sm[4].str();
			minutes = sm[5].str();
			seconds = sm[6].str();
			seconds[2] = '.';
			tmpEnd = new Time(stoi(hours), stoi(minutes), stod(seconds));
		}
		
		getline(*fhandle, tmp);
		tmpText = tmp + '\n';
		while (1)
		{
			getline(*fhandle, tmp);
			if (tmp == "" || fhandle->eof()) break;
			tmpText += tmp + '\n';
		}
		tmpText += '\n';
		SRTComponent* tmpCmp = new SRTComponent(tmpId, *tmpBegin, *tmpEnd, tmpText);
		list->append(tmpCmp);
	}
	this->fhandle->close();
}

void SRT::saveFile()
{
	this->fhandle->open("test.srt", fstream::out);
	string tmp;
	while (list->getCount())
	{
		tmp = "";
		SRTComponent* tmpCmp = list->popFront();
		tmp = to_string(tmpCmp->getID()) + "\n" + tmpCmp->getBegin().toString() + " --> " + tmpCmp->getEnd().toString() + "\n" + tmpCmp->getText();
		*(this->fhandle) << tmp;
	}
	this->fhandle->close();
}