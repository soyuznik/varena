// Palindrom.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
using namespace std;


int main()
{
	ifstream fileR("palindrom.in");
	string line;
	std::getline(fileR, line);
	std::getline(fileR, line);
	fileR.close();
	std::cout << line << std::endl;
	for (int i = 0; i < line.size() / 2; i++) {
		
		if (line[i] != line[line.size() - i]) {
			line.insert(line.size() - i, 1, line[i]);
			std::cout << i << " it :    " << line << std::endl;
		}
	}
	std::cout << line << std::endl;
}

