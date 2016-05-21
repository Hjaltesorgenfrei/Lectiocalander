#include "dateformater.h"
#include <stdio.h>
#include "datestruct.h"
#include <string>
#include <iostream>

// Input: 9/5-2016 10:45 til 11:30

Datestruct dateformater(std::string input)
{
	Datestruct temp_date = {};
	int result = sscanf(input.c_str(), "%d/%d-%d %d:%d til %d:%d", 
		&temp_date.day, &temp_date.month, &temp_date.year, &temp_date.hour, &temp_date.minute ,&temp_date.hourafter, &temp_date.minuteafter);
	//looks for first digits, in this case the day
	//then it skips the "/" and gets the next digits, which is the month
	//then it skips the "-" and gets the next digits, which is the year
	//then it skips the " " and gets the next digits, which is the hour that the lesson starts at
	//then it skips the ":" and gets the next digits, which is the minute that the lesson starts at
	//then it skips the " til " and gets the next digits, which is the hour that the lesson ends at
	//then it skips the ":" and gets the next digits, which is the minute that the lesson ends at
	return temp_date;
}