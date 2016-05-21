#include "dateformater.h"
#include <stdio.h>
#include "datestruct.h"
#include <string>
#include <iostream>

//  9/5-2016 10:45 til 11:30
char tilgarbage[5];
int result;

Datestruct dateformater(std::string input)
{
	Datestruct temp_date = {};
	result = sscanf(input.c_str(), "%d/%d-%d %d:%d til %d:%d", &temp_date.day, &temp_date.month, &temp_date.year, &temp_date.hour, &temp_date.minute ,&temp_date.hourafter, &temp_date.minuteafter); //looks for first " then / then - then : and puts them into char arrays
	std::cout << temp_date.hourafter << std::endl;
	return temp_date;
}
