#include "regularexsearch.h"
#include <iostream>
#include <string>
#include <boost/regex.hpp>
#include <vector>
#include "dateformater.h"
#include "datestruct.h" 

std::vector<Datestruct> datesearch(std::string htmlinput)
{
	boost::regex expression("(\\btitle[=]\")(.{1,50}\\n)?(\\d{1,2}/\\d{1,2}-\\d{4}\\s\\d{2}:\\d{2}\\s\\btil\\s\\d{2}[:]\\d{2})\\n(\\bHold:.*?\\n.*?\\n.*?)?\\n");
	std::vector<Datestruct> lektionsdata;
	boost::match_results<std::string::const_iterator> match;
	std::string::const_iterator start = htmlinput.begin();
	while (boost::regex_search(start, htmlinput.cend(), match, expression)) 
	{
//		Line for testing if output is correct
//		std::cout << "Sub-match 1 : " << match[1] << '\n' << "Sub-match 2 : " << match[2] << '\n' << "Sub-match 3 : " << match[3] << '\n' << "Sub-match 4 : " << match[4] << '\n' << "Found in full match: " << match[0] << '\n'; // match one is date
		Datestruct temp = dateformater(match[3]); //sends the date data to be formatted
		temp.note = match[2] + match[4]; //adds the two notes together
		lektionsdata.push_back(temp); //put the Datestruct into a vector
		start = match[0].second; //goes to the next match
	}
	return lektionsdata; // returns the found data.
}
