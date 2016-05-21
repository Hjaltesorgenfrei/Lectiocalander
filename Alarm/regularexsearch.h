#pragma once
#include <string>
#include <boost/regex.hpp>

std::vector<std::string> datesearch(std::string htmlinput, boost::regex expression);