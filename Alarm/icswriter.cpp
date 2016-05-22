#include "icswriter.h"
#include <vector>
#include "datestruct.h"
#include <vector>
#include <fstream>
#include <iostream>

int writetoics(std::vector<Datestruct> &dates) {
	std::ofstream outputfile("lectiolektioner.ics");
	if (outputfile.is_open()) {
		for (int it = 0, compare = dates.size(); it < compare; it++) {
			//initialize the date before and after to the year. 
			std::string datetimebefore = std::to_string(dates[it].year);
			std::string datetimeafter = std::to_string(dates[it].year);

			//adds the month to both
			if (dates[it].month < 10) {
				datetimebefore + "0" + std::to_string(dates[it].month);
				datetimeafter + "0" + std::to_string(dates[it].month);
			}
			else { 
				datetimebefore + std::to_string(dates[it].month); 
				datetimeafter + std::to_string(dates[it].month);
			}
			
			//adds the day to both
			if (dates[it].day < 10) {
				datetimebefore + "0" + std::to_string(dates[it].day);
				datetimeafter + "0" + std::to_string(dates[it].day);
			}
			else { 
				datetimebefore + std::to_string(dates[it].day);
				datetimeafter + std::to_string(dates[it].day);
			}

			//adds a T to both
			datetimebefore + "T";
			datetimeafter + "T";

			//adds hour to both.
			if (dates[it].hour < 10)
				datetimebefore + "0" + std::to_string(dates[it].hour);
			else { datetimebefore + std::to_string(dates[it].hour); }
			if (dates[it].hourafter < 10)
				datetimeafter + "0" + std::to_string(dates[it].hourafter);
			else { datetimeafter + std::to_string(dates[it].hourafter); }

			//adds minutes and seconds to both
			if (dates[it].minute = 0)
				datetimebefore + "0000";
			else if (dates[it].minute < 10 && dates[it].minute != 0) { datetimebefore + "0" + std::to_string(dates[it].hour) + "00"; }
			else { datetimebefore + std::to_string(dates[it].hour) + "00"; }
			if (dates[it].minuteafter = 0)
				datetimeafter + "0" + std::to_string(dates[it].minuteafter);
			else if (dates[it].minuteafter < 10 && dates[it].minuteafter != 0) { datetimeafter + "0" + std::to_string(dates[it].hour) + "00"; }
			else { datetimeafter + std::to_string(dates[it].minuteafter); }
			std::cout << "Lektion 1" << it << std::endl;
			std::cout << "Time before: " << datetimebefore << std::endl;
			std::cout << "Time after: " << datetimeafter << std::endl;
			std::cout << std::endl;
			
		}
		return 0;
	}
	else { return 1; }
}