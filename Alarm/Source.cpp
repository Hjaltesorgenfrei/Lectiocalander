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
#define _CRT_SECURE_NO_WARNINGS 

//current regex \d{1,2}["/"]\d{1,2}[-]\d{4}\s

using namespace std;

std::string contents; //declares the string for all of the file; i need it later.



int main()
{
	const char *datoinput = "7/12-2015 09:00";
	datestruct output = dateformater(datoinput);
	cout << output.year << "-" << output.month << "/" << output.day << endl;
	//curlwebsite("www.example.com");
	cin.ignore();
	return 0;
}

