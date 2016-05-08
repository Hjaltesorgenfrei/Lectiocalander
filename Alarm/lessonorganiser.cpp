#include "lessonorganiser.h"
#include <regex>
#include <string>
#include "datestruct.h"
#include "regularexsearch.h"
#include <vector>
#include "dateformater.h"

std::vector<std::string> slessonorgansiser(std::string htmlinput)
{
	std::vector<std::string> outputfromregex1 = datesearch(htmlinput, std::basic_regex<char> ("\\btitle[=]\".*?\\n?.*?\\n?\\d{1,2}/\\d{1,2}-\\d{4}\\s\\d{2}:\\d{2}\\s\\btil\\s\\d{2}[:]\\d{2}[\\n]\\bHold:.*\\n.*\\n.*"));
	return outputfromregex1;
}
