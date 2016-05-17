#include "lessonorganiser.h"
#include <regex>
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
	
	std::vector<std::string> outputfromregex1 = datesearch(htmlinput, std::basic_regex<char>("\\btitle[=]\".*\\n.*\\n\\d{1,2}/\\d{1,2}-\\d{4}\\s\\d{2}:\\d{2}\\s\\btil\\s\\d{2}[:]\\d{2}[\\n]\\bHold:.*\\n.*\\n.*"));
	// matches following:
	//title = "Ændret!
	//Grundforløbsopsamling
	//18 / 5 - 2016 12:00 til 12 : 45
	//Hold : 2 BI Camilla
	//Elever : Frederik A.Lindvig Frøshøj(1q 03), Hjalte Sorgenfrei Mac Dalland(xx 01), Julian Modesto Hauvn Beltran del Alisal(1q 02), Marcus Hou Vangsaae Friis(1q 01)
	//Lærer : Julie Nørgaard Hostrup(jun)
	//Lokale : 36 Biologi">

	std::vector<std::string> outputfromregex2 = datesearch(htmlinput, std::basic_regex<char>("\\btitle[=]\".*\\n\\d{1,2}/\\d{1,2}-\\d{4}\\s\\d{2}:\\d{2}\\s\\btil\\s\\d{2}[:]\\d{2}[\\n]\\bHold:.*\\n.*\\n.*"));
	//matches following:
	//title = "Ændret!
	//20 / 5 - 2016 12:00 til 12 : 45
	//Hold : 1q BI
	//Lærer : Sidse Holten - Rossing(sihr)
	//Lokale : 382

	std::vector<std::string> outputfromregex3 = datesearch(htmlinput, std::basic_regex<char>("\\btitle[=]\"\\d{1,2}/\\d{1,2}-\\d{4}\\s\\d{2}:\\d{2}\\s\\btil\\s\\d{2}[:]\\d{2}[\\n]\\bHold:.*\\n.*\\n.*"));
	//matches the following:
	//title = "20/5-2016 12:45 til 13:30
	//Hold: 1q BI
	//Lærer : Sidse Holten - Rossing(sihr)
	//Lokale : 382
	
	std::vector<Datestruct> lessons = stringtodatestruct(outputfromregex3, "%[^\"]\"%[^/]/%[^-]-%s%[^:]:%s");
	for (std::vector<std::string>::iterator it = outputfromregex3.begin(); it != outputfromregex3.end(); ++it) {
		Datestruct tempdate = dateformaterstd(*it);
		lessons.push_back(tempdate);
		std::cout << tempdate.year << std::endl;
	}
	return lessons;
}
