#include <stdio.h>
#include <iostream>
#include <string>
#include <fstream>
#include <regex>
#include <curl/curl.h>
#include <ctime>

#include "curlwebsite.h"
#include "datestruct.h"
#include "dateformater.h"
	//"7/12-2015 09:00";
	//current regex \d{1,2}["/"]\d{1,2}[-]\d{4}\s


std::string contents; //declares the string for all of the file; i need it later.

int main()
{

	//datestruct output = dateformater(datoinput); //creates a struct with the input from sscanf
	//cout << output.year << "-" << output.month << "/" << output.day << endl;
	std::string inputurl;
	std::cin >> inputurl;
	std::string writer = curlwebsite(inputurl);
	std::cout << writer << std::endl;
	system("pause");
	std::cin.ignore();
	return 0;
}