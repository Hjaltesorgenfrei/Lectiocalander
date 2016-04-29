#include "regularexsearch.h"
#include <iostream>
#include <string>
#include <regex>

std::smatch datesearch(std::string htmlinput, int regexversion)
{
	std::regex expression;
	if (regexversion == 1)	//for version with title= followed by numbers 
		std::regex expression = ("\btitle[=]\"\d{1,2}[/]\d{1,2}[-]\d{4}\s\d{2}[:]\d{2}\s\btil\s\d{2}[:]\d{2}[\n]\bHold:\s\d\D\s\D{2}[\n]\bL�rer: (.*\n)(.+(?=\"))"); 
	/* Matches lines like this one, including whitespaces
	title="25/4-2016 09:00 til 09:45
	Hold: 1p DA
	L�rer: Niels Lundsh�j Regnarsen (snlr)
	Lokale: 251
	*/
	if (regexversion == 2) //for version with title=�ndret or anything else. on that line then followed by a new line.
		std::regex expression = ("\btitle[=]\"(.*\n)\d{1,2}[/]\d{1,2}[-]\d{4}\s\d{2}[:]\d{2}\s\btil\s\d{2}[:]\d{2}[\n]\bHold:\s\d\D\s\D{2}[\n]\bL�rer: (.*\n)(.*\n)");
	/* Matches lines like this one, including whitespaces
	title="�ndret!
	25/4-2016 10:00 til 10:45
	Hold: 1p EN
	L�rer: Remo Emil Steen (rest)
	Lokale: 251
	*/
	std::smatch matches;
	std::regex_search(htmlinput, matches, expression);
	return matches;
}
