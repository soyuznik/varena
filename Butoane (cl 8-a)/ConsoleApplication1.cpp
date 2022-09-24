// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <chrono>
using namespace std;
class Button {
public:
	int value = 0;
	int presses = 0;
	static bool are_equal(std::vector<Button*> v) {
		int value = v[0]->value;
		for (int i = 0; i < v.size(); i++) {
			if (!(value == v[i]->value)) {
				return false;
			}
		}
		return true;

	}
	static void find_highest(std::vector<Button*> b , int* hig, int* index) {
		int highest = 0;
		int ind = 0;
		for (int i = 0; i < b.size(); i++) {
			if (highest < b[i]->value) {
				highest = b[i]->value;
				ind = i;

			}
		}
		*hig = highest;
		*index = ind;
		return;
	}
	Button(int m_val) { value = m_val; }
	void press(Button* pred_B, Button* succ_B) {
		presses++;
		if (pred_B == NULL) {
			succ_B->value++;
			value--;
			return;
		}
		else if (succ_B == NULL) {
			pred_B->value++;
			value--;
			return;
		}
		else {
			pred_B->value++;
			succ_B->value++;
			value -= 2;
		}
	}
};
int main()
{
	chrono::steady_clock sc;   // create an object of `steady_clock` class
	auto start = sc.now();     // start timer
	//-----------------------
	ifstream fileR("./butoane.in");
	std::string text;
	std::getline(fileR, text);
	int nr_butoane = stoi(text);
	std::getline(fileR, text);
	fileR.close();
	stringstream s(text);
	std::vector<Button*> b;
	for (int i = 0; i < nr_butoane; i++) {
		string tok;
		s >> tok;
		Button* but = new Button(stoi(tok));
		b.push_back(but);
	}
	int highest = 0;
	int index_hig = 0;
	while (!(Button::are_equal(b))) {
		Button::find_highest(b, &highest, &index_hig);
		Button* pred;
		Button* succ;
	    if (index_hig == 0) { pred = NULL; succ = b[index_hig + 1];}
	    else if (index_hig == b.size() -1) { succ = NULL; pred = b[index_hig - 1];}
		else { succ = b[index_hig + 1]; pred = b[index_hig - 1];}

		b[index_hig]->press( pred, succ);

	}
	ofstream fileW("butoane.out");
	for (int i = 0; i < b.size(); i++) {
		fileW << b[i]->presses << std::endl;
	}
	fileW.close();


	auto end = sc.now();       // end timer (starting & ending is done by measuring the time at the moment the process started & ended respectively)
	auto time_span = static_cast<chrono::duration<double>>(end - start);   // measure time span between start & end
	cout << "Operation took: " << time_span.count() * 1000 << " miliseconds !!!";
}

