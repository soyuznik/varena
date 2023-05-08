#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n ;
    cin>> n;
    std::vector<std::string> names;
    for(int i = 0; i < n ; i++){
        int number = 1;
        std::string name;
        std::string init_name;
        cin >> name; init_name = name;////------------
        recheck:
        if(binary_search(names.begin(), names.end(), name)){
            name = init_name + to_string(number);
            number++;
            goto recheck;
        }
        else {
            names.push_back(name); number = 1;
            if(init_name == name){
              std::cout << "OK\n";
            }
            else{
              cout << name << "\n";
            }
        }
    }




    return 0;
}
