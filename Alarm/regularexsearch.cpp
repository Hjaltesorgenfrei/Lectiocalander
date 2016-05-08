<<<<<<< HEAD
#include "regularexsearch.h"
#include <iostream>
#include <string>
#include <regex>
#include <vector>

std::vector<std::string> datesearch(std::string htmlinput, std::regex expression)
{
	std::vector<std::string> lektionsdata;
	std::smatch m;  //currently takes about 5 seconds to run.
	while (std::regex_search(htmlinput, m, expression)) {
		for (auto x : m) {					 // while there is matches to the regex.
			lektionsdata.push_back(x);		 // put the data into the a vector 
			std::cout << x << std::endl << std::endl;		 // and cout it for debugging.
		}
		htmlinput = m.suffix().str(); // not entirely sure what this line does, but it works :D
	}
	return lektionsdata; // returns the found data.
}

=======
#include "regularexsearch.h"
#include <iostream>
#include <string>
#include <regex>
#include <vector>

std::vector<std::string> datesearch(std::string htmlinput)
{
	std::vector<std::string> lektionsdata;
	std::smatch m;
	std::regex e("\\btitle[=]\".*?\\n?.*?\\n?\\d{1,2}/\\d{1,2}-\\d{4}\\s\\d{2}:\\d{2}\\s\\btil\\s\\d{2}[:]\\d{2}[\\n]\\bHold:.*\\n.*\\n.*");   //currently takes about 5 seconds to run.
	while (std::regex_search(htmlinput, m, e)) { // while there is matches to the regex.
		for (auto x : m) {						 // put the data into the a vector 
			lektionsdata.push_back(x);			 // and cout it for debugging.
			std::cout << x << std::endl << std::endl;
		}
		htmlinput = m.suffix().str(); // not entirely sure what this line does, but it works :D
	}
	return lektionsdata; // returns the found data.
}

>>>>>>> 951037755ba25e4dd3a6b0b405c0395e047f2ac6
