#ifndef DATASTORE_H
#define DATASTORE_H

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <algorithm>
#include <sstream>
#include <fstream>

class DataStore {

private:
	struct Entries {
		int index;
		std::string subject;
		int day;
		int month;
		int year;
		int startTime;
		int endTime;
		std::string impt; //importance
		std::string category;
	};

	std::vector <Entries> dataBase;

//	std::ifstream readFile;

	std::vector <Entries>::iterator dataIter;

	Entries tempEntry;

public:
	
	DataStore() {};

	std::string getDataString(std::vector <Entries>::iterator, int = 0);
	void updateFile(std::string &);
	void entryType(int &, std::string &, int &, int &, int &, int &, int &, std::string &, std::string &);
	int countDigit(int &);

	std::vector <Entries>::iterator getDataIter() {
		return dataIter;
	}

	Entries getEntry() {
		return tempEntry;
	}

	std::vector <Entries> getDataBase() {
		return dataBase;
	}

	void inputCommand();
	int checkCommand();
	void executeCommand();
	
};

#endif