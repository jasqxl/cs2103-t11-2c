#include "Delete.h"

int Delete::getContentIndex(DataStore data, std::string subject) {
	std::size_t found;
	
	for (int index = 0; index != data.getDataBase().size(); index++) {
		found = data.getDataBase()[index].subject.find(subject);
		if (subject == data.getDataBase()[index].subject || found != std::string::npos) {
			return index;
		}
	}
}

void Delete::deleteContent(std::string &fileName, DataStore data, std::string subject, int index) {
	std::string emptyStr;
	emptyStr.clear();

	if (data.getDataBase().size() == 0) {
		std::cout << "File is currently empty.\n";
		return;
	}

	//To check if the index number the user wants to delete is valid
	if (index != 0 && index > data.getDataBase().size()) {
		std::cout << "Index of entry to delete is invalid.\n";
		return;
	}
	else if (subject != emptyStr) {
		index = getContentIndex(data, subject) + 1;
	}

	std::string text = (data.getDataBase())[index - 1].subject;
	data.getDataBase().erase(data.getDataBase().begin() + index - 1);
	data.updateFile(fileName);
	std::cout << "Entry of index " << index << " successfully deleted.\n";
	//sprintf_s(messageToUser, MESSAGE_DELETE.c_str(), fileName.c_str(), text.c_str());
	//output(messageToUser);

	if (data.getDataBase().empty()) {
		std::cout << "Last entry of is file deleted.\n";
		//sprintf_s(messageToUser, MESSAGE_CLEAR.c_str(), fileName.c_str());
		//output(messageToUser);
	}
}