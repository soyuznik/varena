#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <map>
using namespace std;

string fractionToDecimal() {
    int remainder;
    string x = "";
    double dividend;
    {
        double numerator, denominator; // 1 6 //
        cin >> numerator >> denominator;
        if (numerator == 0) return "0";
        if (numerator < 0 && denominator > 0 || numerator > 0 && denominator < 0) x.push_back('-');
        dividend = labs(denominator);
        remainder = labs(numerator) % labs(denominator);
        x += to_string(labs(numerator) / labs(denominator));
    }
    if (remainder == 0) {
        return x;
    }
    x += '.';
    map <int, int> m;
    while (remainder != 0) {
        if (m.find(remainder) != m.end()) {
            x.insert(x.begin() + m[remainder], '(');
            x.push_back(')');
            break;
        }
        else {
            m[remainder] = x.size();
            remainder *= 10;
            x.push_back((remainder / dividend) + '0');
            remainder %= (int)dividend;
        }
    }
    return x;
}
int main()
{
    freopen("fractie.in", "r", stdin);
    freopen("fractie.out", "w", stdout);
    std::cout << fractionToDecimal() << std::endl;
}
