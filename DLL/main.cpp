#include <iostream>
#include "square.h"

using namespace std;

int main() {
	long num;
	cout << "\n\nEnter a number: ";
	cin >> num;
	cout << "The square of " << num << " is " << square(num) << "\n\n";
}

//compile dll   g++ -shared -Os -s -o square.dll square.cpp

//run  g++ -o main.exe -Os -s -L. main.cpp -lsquare