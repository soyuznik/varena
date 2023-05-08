#include <bits/stdc++.h>

using namespace std;

int main()
{
    int perechi , vecin;
    cin >> perechi;
    cin >> vecin;
    //---------------------
    int max_v = perechi * 2;
    std::vector<int> primR;
    std::deque<int> doiR;
    for(int i = 1; i <= max_v; i++ ){
        if(i % 2){
            doiR.push_front(i);
        }
        else{
            primR.push_back(i);
        }
    }
    int raspuns;
    for(int i = 0; i < primR.size(); i++){
        if(primR[i] == vecin){
            raspuns = doiR[i];
        }
        if(doiR[i] == vecin){
            raspuns = primR[i];
        }
    }
    cout << raspuns;

    return 0;
}
