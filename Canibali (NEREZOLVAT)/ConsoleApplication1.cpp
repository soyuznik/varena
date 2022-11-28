include <fstream>
#include <sstream>
#include <string>
#include <algorithm>
#include <iostream>
#include <vector>
//https://www.varena.ro/problema/canibali
 
using namespace std;
#define print(x) std::cout << x << std::endl;
 
class Canibal{
public:
	double v;//viteza
	double r;//rezistenta
	double f;// forta
	double a;// valoarea
	Canibal(double v_ , double r_ , double f_ , double a_){
		v = v_;
		r = r_;
		f = f_;
		a = a_;
	}
	int Puterea(){
		return v + r + f + a;
	}
};
 
 
bool comparaValorile(Canibal &a, Canibal &b)
{
    return a.Puterea() < b.Puterea();
}
 
int main()
{
	std::vector<Canibal> canibali; //viteza
	///---------------------------------------
	ifstream fileR("./canibali.in");
	string text;
	std::getline(fileR , text);
	int nr_canibali = atoi(text.c_str());;
	while (std::getline(fileR , text)){
		stringstream ln(text);
		double v , r, f, a;
		ln >> a; 
		ln >> f; 
		ln >> r; 
		ln >> v; 
		canibali.push_back(Canibal(v , r, f, a));
	}
	fileR.close();
	std::sort(canibali.begin(), canibali.end() , comparaValorile);
	///--------------------------------------------
	for(int i = 0; i < canibali.size(); i++){
		int should_eat = 0;
		if(canibali[i].v >= canibali[i + 1].v){
			should_eat++;
		}
		if(canibali[i].r >= canibali[i + 1].r){
			should_eat++;
		}
		if(canibali[i].f >= canibali[i + 1].f){
			should_eat++;
		}
		if(canibali[i].a >= canibali[i + 1].a){
			should_eat++;
		}
		if(!(should_eat % 2)){
			canibali.erase(canibali.begin() + i);
		}
		
	}
	ofstream fileW("./canibali.out");
	fileW << canibali.size() + 1;
	fileW.close();
}
