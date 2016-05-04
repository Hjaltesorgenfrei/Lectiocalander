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
//

#include <stdio.h>
#include <iostream>
#include <string>
#include <fstream>
#include <regex>
#include <curl/curl.h>
#include <ctime>
#include <regex>
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
	std::vector<std::string> lektionsdata = datesearch(lectiodata); // Gets lessondata from the regex.
	std::cout << "antal lektioner: " << int(lektionsdata.size()) << std::endl; 
	system("pause");
	std::cin.ignore();
	return 0;
}