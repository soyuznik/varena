
#include <iostream>
#include <string>
#include <fstream>
#define MAX 100000


int multiply(int x, int res[], int res_size);

int cfactorial(int n)
{
    int res[MAX];
    res[0] = 1;
    int res_size = 1;
    for (int x = 2; x <= n; x++)
        res_size = multiply(x, res, res_size);

    int count = 0;
    for (int i = res_size - 1; i >= 0; i--) {
        if (res[i] == 0) { count++; }
    }
    return count;
}


int multiply(int x, int res[], int res_size)
{
    int carry = 0; 

    
    for (int i = 0; i < res_size; i++) {
        int prod = res[i] * x + carry;
        res[i] = prod % 10;
        carry = prod / 10;
    }

  
    while (carry) {
        res[res_size] = carry % 10;
        carry = carry / 10;
        res_size++;
    }
    return res_size;
}

int main()
{
    int zeros;
    {
    std::ifstream fileR("fact1.in");
    std::string line;
    std::getline(fileR, line);
    fileR.close();
    zeros = stoi(line);
    }
    int fact = 1;
    while (true) {
        if (cfactorial(fact) == zeros) {
            break;
        }
        else {
            fact++;
        }
    }
    std::ofstream fileW("fact1.out");
    fileW << fact;
    fileW.close();
}

