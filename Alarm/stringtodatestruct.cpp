#include "stringtodatestruct.h"
#include "dateformater.h"
#include <iostream>

std::vector<Datestruct> stringtodatestruct(std::vector<std::string> unformattedlessons, char *formatter)
{
	std::vector<Datestruct> lessons;
	for (std::vector<std::string>::iterator it = unformattedlessons.begin(); it != unformattedlessons.end(); it ++) {
		Datestruct tempdate = dateformater(*it, formatter);
		lessons.push_back(tempdate);
		std::cout << tempdate.year << std::endl;
	}
	return lessons;
}
