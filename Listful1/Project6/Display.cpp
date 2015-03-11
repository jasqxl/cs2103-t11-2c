#include "Display.h"

Display::Display() {}

int Display::determineCategory(std::string command) {
	if (command == "day") {
		return subDateCategory::DAY;
	}
	else if (command == "month") {
		return subDateCategory::MONTH;
	}
	else {
		return subDateCategory::INVALID;
	}
}
	
void Display::displayContent(std::string &fileName, DataStore data, std::string command, int date) {
	if (data.getDataBase().size() == 0) {
		std::cout << "File is currently empty.\n";
		return;
	}

	category = determineCategory(command);

	switch (category) {
		case DAY:
			for (data.getDataIter() = data.getDataBase().begin(); data.getDataIter() != data.getDataBase().end(); data.getDataIter()++) {
				if ((*(data.getDataIter())).day == date) {
					std::cout << data.getDataString(data.getDataIter()) << '\n';
				}
			}
			break;

		case MONTH:
			for (data.getDataIter() = data.getDataBase().begin(); data.getDataIter() != data.getDataBase().end(); data.getDataIter()++) {
				if ((*(data.getDataIter())).month == date) {
					std::cout << data.getDataString(data.getDataIter()) << '\n';
				}
			}
			break;
	
		default:
			for (data.getDataIter() = data.getDataBase().begin(); data.getDataIter() != data.getDataBase().end(); data.getDataIter()++) {
				std::cout << data.getDataString(data.getDataIter()) << '\n';
			}
			//std::cout << "Display cannot be sorted according to the wanted category.\n";
			break;
	}
}