#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <string>
#include <conio.h>
#include <time.h>
#include <string.h>
#include <fstream>
#include <sstream>
using namespace std;

int main() {
	ifstream file;
	file.open("data.csv");
	cout<<file.is_open();
	return 0;
}