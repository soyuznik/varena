#include <bits/stdc++.h>

using namespace std;

int main()
{
    int participanti;
    cin >> participanti;
    std::vector<string> voturi;
    for(int i = 0; i < participanti; i++){
        string line;
        std::getline(std::cin , line);
        if( std::tolower(line)== "luni" || std::tolower(line)== "marti" || std::tolower(line)== "miercuri" ||              std::tolower(line)== "joi"
           std::tolower(line)== "vineri" || std::tolower(line)== "sambata" || std::tolower(line)== "duminica"){
        voturi.push_back(std::tolower(line));
        }
        else{
            continue;
        }
    }
    std::vector<int> zile;
    zile.push_back(std::count(voturi.begin(), voturi.end() , "luni"));
    zile.push_back(std::count(voturi.begin(), voturi.end() , "marti"));
    zile.push_back(std::count(voturi.begin(), voturi.end() , "miercuri"));
    zile.push_back(std::count(voturi.begin(), voturi.end() , "joi"));
    zile.push_back(std::count(voturi.begin(), voturi.end() , "vineri"));
    zile.push_back(std::count(voturi.begin(), voturi.end() , "sambata"));
    zile.push_back(std::count(voturi.begin(), voturi.end() , "duminica"));
    int lolmax = 0;
    int curr = -1;
    for(int i = 0; i < zile.size(); i++){
        if(zile[i] > lolmax){
            lolmax = zile[i];
            curr = i;
        }
    }
    std::cout << i;






    return 0;
}
