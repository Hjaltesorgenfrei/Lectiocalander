#include "regularexsearch.h"
#include <iostream>
#include <string>
#include <boost/regex.hpp>
#include <vector>

std::vector<std::string> datesearch(std::string htmlinput, boost::regex expression)
{
	std::vector<std::string> lektionsdata;
	try {
		boost::match_results<std::string::const_iterator> what;
		std::string::const_iterator start = htmlinput.begin();
		while (boost::regex_search(start, htmlinput.cend(), what, expression))
		{
			std::cout << "Sub-match : " << what[1] << " found in full match: " << what[0] << '\n'; // match one is date
			lektionsdata.push_back(what[0]);
			start = what[0].second;
		}
	}
	catch (boost::bad_expression & ex)
	{
		std::cout << ex.what();
	}
	return lektionsdata; // returns the found data.
}
