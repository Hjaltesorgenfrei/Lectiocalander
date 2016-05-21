#include "dateformater.h"
#include <stdio.h>
#include "datestruct.h"
#include <string>
#include <iostream>

char dage[10]; //temporay variables for the sscanf
char maaneder[10];
char aar[10];
char timer[10];
char minutter[10];
char timerefter[10];
char minutterefter[10];
int result;
std::string trashcan1;

Datestruct dateformater(std::string input)
{
	result = sscanf(input.c_str(), "%[^/]/%[^-]-%s%[^:]:[^ til ]%[^:]:%s", dage, maaneder, aar, timer, minutter, timerefter, minutterefter); //looks for first " then / then - then : and puts them into char arrays
	Datestruct temp_date = {};
	temp_date.year = atoi(aar); //converts the char * to an integer.
	temp_date.month = atoi(maaneder);
	temp_date.day = atoi(dage);
	temp_date.hour = atoi(timer);
	temp_date.minute = atoi(minutter);
	temp_date.hourafter = atoi(timerefter);
	temp_date.minuteafter = atoi(minutterefter);
	return temp_date;
}
