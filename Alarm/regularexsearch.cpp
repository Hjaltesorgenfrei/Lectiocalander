#include "regularexsearch.h"
#include <iostream>
#include <string>
#include <regex>
#include <vector>

std::vector<std::string> datesearch(std::string htmlinput, std::regex expression)
{
	std::vector<std::string> lektionsdata;
	std::smatch m;  //currently takes about 15 seconds to run.
	while (std::regex_search(htmlinput, m, expression)) { 
		for (auto x : m) {					 // while there is matches to the regex.
			lektionsdata.push_back(x);		 // put the data into the a vector 
			std::cout << x << std::endl << std::endl;		 // and cout it for debugging.
		}
		htmlinput = m.suffix().str(); // not entirely sure what this line does, but it works :D
	}
	return lektionsdata; // returns the found data.
}