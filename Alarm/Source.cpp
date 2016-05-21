/*
Made by Hjalte Sorgenfrei Mac Dalland
Hjaltesorgenfrei@gmail.com
Signed 2016/02/03
A program which takes lesson data about time and date. Then puts it into a struct to hold all the data.
I then use it to upload "stuff" into calanders/ output Icalander files.
*/

//TODO
//Maybe change the regular search and remove the "?"s as it makes it hard to format the data. Could be done by creating mutilpe regular expressions and put them in a vector each. - Might help with performance as well.
//
//Change from standard Regex to Boost Regex and see if their is a significant speed boost.
//
//Remove "?" from the regex as much as possible and make it multiple regex searches to make the date formatable and run faster.

#include <stdio.h>
#include <iostream>
#include <string>
#include <fstream>
#include <regex>
#include <curl/curl.h>
#include <ctime>
#include <boost/regex.hpp>
#include <vector>

#include "curlwebsite.h"
#include "datestruct.h"
#include "dateformater.h"
#include "regularexsearch.h"
	// current sscanf search output: "7/12-2015 09:00";
	//current regex: ("\\btitle[=]\".*?\\n?.*?\\n?\\d{1,2}/\\d{1,2}-\\d{4}\\s\\d{2}:\\d{2}\\s\\btil\\s\\d{2}[:]\\d{2}[\\n]\\bHold:.*\\n.*\\n.*")

int main()
{
	std::string inputurl;
	std::cin >> inputurl; //get url from user. - Maybe from file later
	std::string lectiodata = curlwebsite(inputurl); //gets the html of the provided site.
	std::vector<Datestruct> lektionsdata = datesearch(lectiodata); // Gets lessondata slessonorganiser which takes string.
	std::cout << "antal lektioner: " << int(lektionsdata.size()) << std::endl;
	for (int i = 0; i <= 100; i++) {
		int caller;
		std::cin >> caller;
		std::cout << "Note: " << lektionsdata[caller].note << std::endl;
		std::cout << "Time: " << lektionsdata[caller].hour << ":" << lektionsdata[caller].minute << " til " << lektionsdata[caller].hourafter << ":" << lektionsdata[caller].minuteafter << std::endl;
		std::cout << "Date: " << lektionsdata[caller].day << "-" << lektionsdata[caller].month << "/" << lektionsdata[caller].year << std::endl;
	}
	system("pause");
	return 0;
}