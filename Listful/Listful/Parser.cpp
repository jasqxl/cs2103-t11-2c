#include <iostream>
#include <cstdlib>
#include <string>
#include <sstream>
#include "Parser.h"
#include "UserInterface.h"

Parser::~Parser(void){
}

/*std::string Parser::getUserCommand(){
	std::string userCommand;
	std::cin >> userCommand;
	std::cin.ignore();
	
	return userCommand;
}*/

std::string Parser::getUserInput(){
	std::string userInput;
	std::getline(std::cin,userInput);

	return userInput;
}

std::string Parser::userContent(std::string userInput){
	std::string userContent = userInput.substr(0, userInput.find_first_of(".,?!"));

	return userContent;
}

std::string Parser::userDate(std::string userInput){
	std::string userDate = userInput.substr(userInput.find_first_of(".,?!")+2,10);

	return userDate;
}

int Parser::dateDay(std::string userDate){
	std::string userDateDay = userDate.substr(0, 2);
	int dateDay = atoi(userDateDay.c_str());
	return dateDay;
}

int Parser::dateMonth(std::string userDate){
	std::string userDateMonth = userDate.substr(3, 2);
	int dateMonth = atoi(userDateMonth.c_str());
	return dateMonth;
}

int Parser::dateYear(std::string userDate){
	std::string userDateYear = userDate.substr(6, 4);
	int dateYear = atoi(userDateYear.c_str());
	
	return dateYear;
}

std::string Parser::userTime(std::string userInput){
	std::string userTime = userInput.substr(userInput.find_first_of(".,?!")+14, 9);

	return userTime;
}

int Parser::startTime(std::string userTime){
	std::string userStartTime;
	int startTime;

	userStartTime = userTime.substr(0, 4);
	startTime = atoi(userStartTime.c_str());
	
	return startTime;
}

int Parser::endTime(std::string userTime){
	std::string userEndTime;
	int endTime;

	userEndTime = userTime.substr(userTime.find_first_of("-")+1, 4);
	endTime = endTime = atoi(userEndTime.c_str());

	return endTime;
}

std::string Parser::userPriority(std::string userInput){
	std::string userPriority = userInput.substr(userInput.find_first_of(".,?!")+25, userInput.size());

	return userPriority;
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