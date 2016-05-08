#include "dateformater.h"
#include <stdio.h>
#include "datestruct.h"
#include <string>

char dage[10]; //temporay variables for the sscanf
char maaneder[10];
char aar[10];
char timer[10];
char minutter[10];
int result;
std::string trashcan1;

datestruct dateformaterstd(const char *input)
{
	result = sscanf(input, "%[^\"]\"%[^/]/%[^-]-%s%[^:]:%s", trashcan1, dage, maaneder, aar, timer, minutter); //looks for first " then / then - then : and puts them into char arrays
	datestruct temp_date = {};
	temp_date.year = atoi(aar); //converts the char * to an integer.g
	temp_date.month = atoi(maaneder); 
	temp_date.day = atoi(dage); 
	temp_date.hour = atoi(timer);
	temp_date.minutes = atoi(minutter); 
	return temp_date;
}