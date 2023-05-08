#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;


int main()
{
    ifstream in("nnr.in");
    std::freopen("nnr.out", "w", stdout);
    int num_t = 0;
    in >> num_t;
    //////
    for (int i = 0; i < num_t; i++) {
        int num_cifre = 0;
        in >> num_cifre;
        std::vector<unsigned long> cifre;
        for (int j = 0; j < num_cifre; j++) {
            unsigned long num;
            in >> num;
            cifre.push_back(num);
        }
        /// do smth... /// de schimbat doar 40 puncte /??
        std::sort(cifre.begin(), cifre.end());
        if (std::adjacent_find(cifre.begin(), cifre.end()) != cifre.end()){
            std::cout << "NU\n";
        }
        else {
            std::cout << "DA\n";
        }
    }
}

