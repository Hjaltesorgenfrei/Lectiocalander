#include "regularexsearch.h"
#include <iostream>
#include <string>
#include <regex>
#include <vector>

std::vector<std::string> datesearch(std::string htmlinput)
{
	std::vector<std::string> lektionsdata;
	std::smatch m;
	std::regex e("\\btitle[=]\".*?\\n?.*?\\n?\\d{1,2}/\\d{1,2}-\\d{4}\\s\\d{2}:\\d{2}\\s\\btil\\s\\d{2}[:]\\d{2}[\\n]\\bHold:.*\\n.*\\n.*");   // matches words beginning by "sub"
	while (std::regex_search(htmlinput, m, e)) {
		for (auto x : m) {
			lektionsdata.push_back(x);
			std::cout << x << std::endl << std::endl;
		}
		htmlinput = m.suffix().str();
	}
	return lektionsdata;
}
