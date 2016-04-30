#pragma once
#include <string>

struct datestruct
{
	int year;
	int month;
	int day;
	int hour;
	int minutes;
	bool changed;
	std::string teacher;
	std::string note;
	std::string lokale; // might need to be changed as there is more then one room on some lections
};