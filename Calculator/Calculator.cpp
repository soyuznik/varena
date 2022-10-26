
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

int NumDigits(int x)
{
    x = abs(x);
    return (x < 10 ? 1 :
        (x < 100 ? 2 :
            (x < 1000 ? 3 :
                (x < 10000 ? 4 :
                    (x < 100000 ? 5 :
                        (x < 1000000 ? 6 :
                            (x < 10000000 ? 7 :
                                (x < 100000000 ? 8 :
                                    (x < 1000000000 ? 9 :
                                        10)))))))));
}
int controlNumber(unsigned long long n)
{
    const int Base = 10;
    int digit = n % Base;
    while ((n /= Base) && (n % Base == digit));
    return n == 0;
}
int main()
{
    ifstream in("calculator.in");
    int nr;
    {string number;
    in >> number; nr = stoi(number); }
    in.close();
    unsigned long long number = 0;
    bool found = false;
    for (int i = 1; i <= 100000; i++) {
        number += nr;
        if(controlNumber(number)){
            found = true;
            break;
        }
    }
    int digits = NumDigits(number);
    while (number >= 10)
        number /= 10;
    freopen("calculator.out", "w", stdout);
    if (!found) {
        std::cout << "Impossible";
    }
    else std::cout << number << " " << digits;



}

