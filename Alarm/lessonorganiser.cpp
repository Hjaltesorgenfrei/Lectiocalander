#include "lessonorganiser.h"
#include <boost/regex.hpp>
#include <string>
#include "datestruct.h"
#include "regularexsearch.h"
#include <vector>
#include "dateformater.h"
#include <iostream>
#include "stringtodatestruct.h"

std::vector<Datestruct> slessonorgansiser(std::string htmlinput)
{
	//std::vector<std::string> outputfromregex2 = datesearch(htmlinput, std::basic_regex<char> ("\\btitle[=]\".*?\\n?.*?\\n?\\d{1,2}/\\d{1,2}-\\d{4}\\s\\d{2}:\\d{2}\\s\\btil\\s\\d{2}[:]\\d{2}[\\n]\\bHold:.*\\n.*\\n.*")); 
	//base regex should in theory match all the possible lessons.
	
//	std::vector<std::string> outputfromregex1 = datesearch(htmlinput, boost::basic_regex<char>("\\btitle[=]\".*\\n.*\\n\\d{1,2}/\\d{1,2}-\\d{4}\\s\\d{2}:\\d{2}\\s\\btil\\s\\d{2}[:]\\d{2}[\\n]\\bHold:.*\\n.*\\n.*"));
	// matches following:
	//title = "Ændret!
	//Grundforløbsopsamling
	//18 / 5 - 2016 12:00 til 12 : 45
	//Hold : 2 BI Camilla
	//Elever : Frederik A.Lindvig Frøshøj(1q 03), Hjalte Sorgenfrei Mac Dalland(xx 01), Julian Modesto Hauvn Beltran del Alisal(1q 02), Marcus Hou Vangsaae Friis(1q 01)
	//Lærer : Julie Nørgaard Hostrup(jun)
	//Lokale : 36 Biologi">

//	std::vector<std::string> outputfromregex2 = datesearch(htmlinput, boost::basic_regex<char>("\\btitle[=]\".*\\n\\d{1,2}/\\d{1,2}-\\d{4}\\s\\d{2}:\\d{2}\\s\\btil\\s\\d{2}[:]\\d{2}[\\n]\\bHold:.*\\n.*\\n.*"));
	//matches following:
	//title = "Ændret!
	//20 / 5 - 2016 12:00 til 12 : 45
	//Hold : 1q BI
	//Lærer : Sidse Holten - Rossing(sihr)
	//Lokale : 382

	std::vector<std::string> outputfromregex3 = datesearch(htmlinput, boost::basic_regex<char>("(\\btitle[=]\")(.{1,50}\\n)?(\\d{1,2}/\\d{1,2}-\\d{4}\\s\\d{2}:\\d{2}\\s\\btil\\s\\d{2}[:]\\d{2})\\n(\\bHold:.*?\\n.*?\\n.*?)\\n"));
	//matches the following:
	//title = "Ændret!						| Group 1 until the character " then the rest is also group 2
	//Grundforløbsopsamling					| Group 2
	//20/5-2016 12:45 til 13:30				| Group 3	
	//Hold: 1q BI							| Group 4
	//Lærer : Sidse Holten - Rossing(sihr)	| Group 4
	//Lokale : 382							| Group 4

	std::cout << outputfromregex3.size() << outputfromregex3[2] << std::endl;
	std::vector<Datestruct> lessons = stringtodatestruct(outputfromregex3, "%[^/]/%[^-]-%s%[^:]:%s");
	return lessons;
}
