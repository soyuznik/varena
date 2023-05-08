#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

int main()
{
    std::string line;
    std::vector<double> medii;
    getline(std::cin , line);
    int max_i = stoi(line);
    for(int i = 0; i < max_i ; i++){
        getline(std::cin , line);
        double val = stod(line);
        if(val < 2 || val > 10){
            cout << "Error";
            return 0;
        }
        medii.push_back(val);
    }
    int cmmElev = 0;
    int index;
    for(int i = 0 ; i < medii.size(); i++){
        if(cmmElev < medii[i]){
            cmmElev = medii[i];
            index = i;
        }
    }
    for(int i = 0 ; i < medii.size(); i++){
        if((cmmElev) < medii[i]){
            cout << i + 1 << " ";
        }
    }
    cout << std::endl;
    cout << (medii[index] * 200) << " lei";
    return 0;
}
