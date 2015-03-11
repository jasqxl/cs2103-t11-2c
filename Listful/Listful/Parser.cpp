#include <iostream>
#include <string>
#include <sstream>
#include "Parser.h"

Parser::~Parser(void){
}

std::string Parser::getUserCommand(){
	std::string userCommand;
	std::cin >> userCommand;
	std::cin.ignore();
	
	return userCommand;
}

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

std::string Parser::userTime(std::string userInput){
	std::string userTime = userInput.substr(userInput.find_first_of(".,?!")+14, 9);

	return userTime;
}

std::string Parser::userPriority(std::string userInput){
	std::string userPriority = userInput.substr(userInput.find_first_of(".,?!")+25, userInput.size());

	return userPriority;
}