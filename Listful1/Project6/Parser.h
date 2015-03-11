#ifndef PARSER_H
#define PARSER_H

#include <fstream>
#include <vector>
#include <string>
#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <sstream>
#include <vector>
#include <iomanip>

class Parser {
	private:
		int commandIndex;
		int index;
		std::string userInput;
		std::string userDate;
		std::string userTime;
	
	public:
		~Parser(void);

		Parser();

		int getIndex() {
			std::cin >> index;
			return index;
		};

		void determineCommand(DataStore, std::string, int, int &);

		std::string getDelete();

		std::string getDisplay();

		std::string getEditCat();
		int editDay();
		int editMonth();
		int editYear();
		int editSTime();
		int editETime();

		//Subject
		std::string userContent();

		//Date
		void date();
		int dateDay();
		int dateMonth();
		int dateYear();

		//Time
		void time();
		int startTime();
		int endTime();

		//Impt
		std::string userPriority();

		//Category
		std::string userCat();

		void testParser();
};
#endif