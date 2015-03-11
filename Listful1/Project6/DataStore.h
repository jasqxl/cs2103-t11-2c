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
		int startTime;
		int endTime;
		int day;
		int month;
		int year;
		std::string impt; //importance
		std::string category;
	};

	std::vector <Entries> dataBase;

	std::ofstream writeFile;

	std::ifstream readFile;

	std::vector <Entries>::iterator dataIter;

	Entries tempEntry;

public:
	
	DataStore();
<<<<<<< HEAD
	std::string getDataString(std::vector <Entries>::iterator, int = 0);
	void updateFile(std::string &);
	void entryType(int, std::string, int, int ,int, int, int, std::string, std::string);
	int countDigit(int);

	std::vector <Entries>::iterator getDataIter() {
		return dataIter;
	}
	Entries getEntry() {
		return tempEntry;
	}
	std::vector <Entries> getDataBase() {
		return dataBase;
=======
	void inputCommand();
	int checkCommand();
	void executeCommand();

	vector <Entries>  DataStore::getDataBase() {
	return dataBase;
>>>>>>> a10767f6b2d7003748f1886b6c098e5337a7789d
	}

};

#endif