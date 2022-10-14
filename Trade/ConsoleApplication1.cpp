#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

class Negustor {
public:
	int minINT = 0;
	int maxINT = 0;
	int initP = 0;
	Negustor(int a, int b, int p, std::vector<int>& oraa) {
		minINT = a;
		maxINT = b;
		initP = p;
		for (int i = 0; i < oraa.size(); i++) {
			int costp = cost(i);
			if (costp == -1) continue;
			if (oraa[i] < costp) {
				oraa[i] = costp;
			}
		}
	}
	int cost(int index) {
		if (index < minINT || index > maxINT) return -1;
		return (index - minINT) + initP;
	}
};

int main()
{
	ifstream fileR("trade.in");
	std::string line;
	int Mnegust, Noras;
	std::vector<int> ora;
	{
		int linec = 0;
		while (std::getline(fileR, line)) {
			linec++;
			if (linec == 1) {
				std::stringstream str(line);
				string s1, s2;
				str >> s1;
				str >> s2;
				Noras = stoi(s1);
				ora = std::vector<int>(Noras);
				continue;
			}
			std::stringstream str(line);
			string s1, s2, s3;
			str >> s1;
			str >> s2;
			str >> s3;
			Negustor n(stoi(s1) - 1, stoi(s2) - 1, stoi(s3), ora);
		}
		fileR.close();
	}
	//-------------------------------------------------------------------
	ofstream fileW("trade.out");
	for (int i = 0; i < ora.size(); i++) {
		fileW << ora[i] << " ";
	}
	fileW.close();
}