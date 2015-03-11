#include "Parser.h"
#include "UserInterface.h"
#include "Add.h"
#include "Clear.h"
#include "DataStore.h"
#include "Delete.h"
#include "Display.h"
#include "Edit.h"

Parser::~Parser(void){
}

Parser::Parser() {
	getline(std::cin, userInput);
	Add add();
	Display display();
	Delete remove();
	Edit edit();
}

/*std::string Parser::getUserCommand(){
	std::string userCommand;
	std::cin >> userCommand;
	std::cin.ignore();
	
	return userCommand;
}*/

void Parser::determineCommand(DataStore data, std::string fileName, int command, int &fileSize){
	switch (command){
			case 1:
				fileSize++;
				add.addContent(fileName, fileSize, userContent(), startTime(), endTime(), dateDay(), dateMonth(), dateYear(), userPriority(), userCat());
				break;
			case 2:
				display.displayContent(fileName, data, getDisplay(), index);
				break;
			case 3:
				remove.deleteContent(fileName, data, getDelete(), index):
				break;
			case 4:
				if (isDate) {
					edit.editContent(fileName, data, getEditCat(), getIndex(), userContent(), editDay(), editMonth(), editYear());
				}
				else {
					edit.editContent(fileName, data, getEditCat(), getIndex(), userContent(), editSTime(), editETime());
				}
				break;
			case 5:
				break;
			case 6:
				break;
			default:
				std::cout << "Invalid command.\n";
				std::cin >> command;
		}
}

std::string Parser::userContent(){
	std::string userContent = userInput.substr(0, userInput.find_first_of(".,?!"));

	return userContent;
}

bool isDate() {
	size_t found;

	found = userInput.find("-");
	if (found != std::string::npos) {
		return false;
	}

	return true;
}

std::string Parser::getDelete() {
	std::string deleteStr;
	std::cin >> deleteStr;
	return deleteStr;
}

std::string Parser::getDisplay() {
	std::string displayStr;
	std::cin >> displayStr;
	return displayStr;
}

std::string Parser::getEditCat() {
	std::string cat;
	std::cin >> cat;
	return cat;
}

int Parser::editDay(){
	std::string userDateDay = userInput.substr(0, 2);
	int dateDay = atoi(userDateDay.c_str());
	return dateDay;
}

int Parser::editMonth(){
	std::string userDateMonth = userInput.substr(3, 2);
	int dateMonth = atoi(userDateMonth.c_str());
	return dateMonth;
}

int Parser::editYear(){
	std::string userDateYear = userInput.substr(6, 4);
	int dateYear = atoi(userDateYear.c_str());
	
	return dateYear;
}

int Parser::editSTime(){
	std::string userStartTime;
	int startTime;

	userStartTime = userInput.substr(0, 4);
	startTime = atoi(userStartTime.c_str());
	
	return startTime;
}

int Parser::editETime(){
	std::string userEndTime;
	int endTime;

	userEndTime = userInput.substr(userTime.find_first_of("-")+1, 4);
	endTime = endTime = atoi(userEndTime.c_str());

	return endTime;
}

void Parser::date(){
	userDate = userInput.substr(userInput.find_first_of(".,?!")+2,10);
}

int Parser::dateDay(){
	std::string userDateDay = userDate.substr(0, 2);
	int dateDay = atoi(userDateDay.c_str());
	return dateDay;
}

int Parser::dateMonth(){
	std::string userDateMonth = userDate.substr(3, 2);
	int dateMonth = atoi(userDateMonth.c_str());
	return dateMonth;
}

int Parser::dateYear(){
	std::string userDateYear = userDate.substr(6, 4);
	int dateYear = atoi(userDateYear.c_str());
	
	return dateYear;
}

void Parser::time(){
	userTime = userInput.substr(userInput.find_first_of(".,?!")+14, 9);
}

int Parser::startTime(){
	std::string userStartTime;
	int startTime;

	userStartTime = userTime.substr(0, 4);
	startTime = atoi(userStartTime.c_str());
	
	return startTime;
}

int Parser::endTime(){
	std::string userEndTime;
	int endTime;

	userEndTime = userTime.substr(userTime.find_first_of("-")+1, 4);
	endTime = endTime = atoi(userEndTime.c_str());

	return endTime;
}

std::string Parser::userPriority(){
	int lengthPriority = userInput.size() - userInput.find_last_of(" ");
	std::string userPriority = userInput.substr(userInput.find_first_of(".,?!")+25, lengthPriority);

	return userPriority;
}

std::string Parser::userCat(std::string userInput){
	std::string userCat = userInput.substr(userInput.find_last_of(" "), userInput.size());

	return userCat;
}

void Parser::testParser(){
	std::string text = getUserInput();
	std::cout << "Day = " << dateDay(userDate(text)) << std::endl;
	std::cout << "month = " << dateMonth(userDate(text)) << std::endl;
	std::cout << "year = " << dateYear(userDate(text)) << std::endl;
	std::cout << "user content = " << userContent(text) << std::endl;
	std::cout << "user date = " << userDate(text) << std::endl;
	std::cout << "user time = " << userTime(text) << std::endl;
	std::cout << "user priority = " << userPriority(text) << std::endl;
	std::cout << "start time = " << startTime(userTime(text)) << std::endl;
	std::cout << "end time = " << endTime(userTime(text)) << std::endl;
}