#include "Clear.h"

Clear::Clear() {}

void Clear::clearFile(std::string &fileName, DataStore data) {
	if (data.getDataBase().size() == 0) {
		std::cout << "File is currently empty.\n";
		return;
	}

	data.getDataBase().clear();
	data.updateFile(fileName);

	std::cout << "File has been cleared successfully.\n";
	//sprintf_s(messageToUser, MESSAGE_CLEAR.c_str(), fileName.c_str());
	//output(messageToUser);
}
