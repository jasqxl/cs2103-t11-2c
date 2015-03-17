#ifndef SORT_H
#define SORT_H

#include "DataStore.h"

class Sort
{
	private:
	enum subCategory {
		SUBJECT, TIME, DATE, IMPT, CATEGORY, INVALID
	};

	int category;
public:
	
	int determineCategory(std::string);
	void Switch(int &, int &, DataStore &);
	void sort(DataStore &, std::string);
};

#endif