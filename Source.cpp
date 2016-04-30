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


std::string contents; //declares the string for all of the file; i need it later.

int main()
{
	//datestruct output = dateformater(datoinput); //creates a struct with the input from sscanf
	//cout << output.year << "-" << output.month << "/" << output.day << endl;
	std::string inputurl;
	std::cin >> inputurl;
	std::string lectiodata = curlwebsite(inputurl);
	//std::cout << lectiodata << std::endl;
	//std::smatch results = datesearch(lectiodata);
	std::vector<std::string> lektionsdata = datesearch(lectiodata);
	std::cout << "antal lektioner: " << int(lektionsdata.size()) << std::endl;
	system("pause");
	std::cin.ignore();
	return 0;
}