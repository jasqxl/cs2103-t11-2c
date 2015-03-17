#include "UserInterface.h"

//first word is file name and test driver
int main(int argc, char *argv[]) {

	UserInterface runListful;

	runListful.homeScreen();

	runListful.runProgram(argv);

	return 0;
}