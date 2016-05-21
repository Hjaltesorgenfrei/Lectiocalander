/*
Made by Hjalte Sorgenfrei Mac Dalland
Hjaltesorgenfrei@gmail.com
Signed 2016/02/03
Version 0.60

This is a program which takes lesson data about time and date from lectio.dk. Then puts it into a struct to hold all the data.
It then uses it to upload "stuff" into calanders/ output Icalander files.

only input currently is a url to a site containing a schedule, be that a class or a pupil
*/

//TODO
//Create a GUI in qt
//
//Figure out googles API, this might involve getting two factor authentication to work

#include <stdio.h>
#include <iostream>
#include <string>
#include <curl/curl.h>
#include <boost/regex.hpp>
#include <vector>

#include "curlwebsite.h"
#include "datestruct.h"
#include "dateformater.h"
#include "regularexsearch.h"
	//current regex: (\\btitle[=]\")(.{1,50}\\n)?(\\d{1,2}/\\d{1,2}-\\d{4}\\s\\d{2}:\\d{2}\\s\\btil\\s\\d{2}[:]\\d{2})\\n(\\bHold:.*?\\n.*?\\n.*?)?\\n")

int main()
{
	std::string inputurl;
	std::cin >> inputurl; //get url from user. - Maybe from ini file later
	std::string lectiodata = curlwebsite(inputurl); //gets the html of the site which was provided url from
	std::vector<Datestruct> lektionsdata = datesearch(lectiodata); //sends the html to regex which formats the data and sends back a vector of Datestructs
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