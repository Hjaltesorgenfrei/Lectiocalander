#include "regularexsearch.h"
#include <iostream>
#include <string>
#include <boost/regex.hpp>
#include <vector>
#include "dateformater.h"
#include "datestruct.h" 

std::vector<Datestruct> datesearch(std::string htmlinput)
{
	boost::regex expression("(\\btitle[=]\")(.{1,50}\\n)?(\\d{1,2}/\\d{1,2}-\\d{4}\\s\\d{2}:\\d{2}\\s\\btil\\s\\d{2}[:]\\d{2})\\n(\\bHold:.*?\\n.*?\\n.*?)\\n");
	std::vector<Datestruct> lektionsdata;
	try {
		boost::match_results<std::string::const_iterator> match;
		std::string::const_iterator start = htmlinput.begin();
		while (boost::regex_search(start, htmlinput.cend(), match, expression))
		{
			std::cout << "Sub-match 1 : " << match[1] << '\n' << "Sub-match 2 : " << match[2] << '\n' << "Sub-match 3 : " << match[3] << '\n' << "Sub-match 4 : " << match[4] << '\n' << "Found in full match: " << match[0] << '\n'; // match one is date
			Datestruct temp = dateformater(match[3]);
			temp.note = match[2] + match[4];
			lektionsdata.push_back(temp);
			start = match[0].second;
		}
	}
	catch (boost::bad_expression & ex)
	{
		std::cout << ex.what();
	}
	return lektionsdata; // returns the found data.
}
