#include<time.h>

double GenerateRandomNum() {
	//srand(time(0));  //for further randomness
	double randomNum = rand() / 32767.0;
	return randomNum;
	//return 0.5; // for test
}