#include <bits/stdc++.h>

using namespace std;

int main()
{
    ifstream in("reteta.in");
    std::string line;
    std::getline(in , line);
    std::cout << line;

    //--------------------------------------------------------
    int timp = 0;

    std::string val = "";
    for(int i = 0; i < line.size(); i++){
            if(line[i] == ")"){
                val = line.substr(i , line.find(" " , i));
            }
            std::cout << val;
    }



    return 0;
}
