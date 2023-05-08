#include <bits/stdc++.h>

using namespace std;
/*

6
1 0 1 0 1 0
1 1 1 1 0 1
1 1 0 1 1 1
1 0 1 1 0 1
1 1 1 1 1 0
1 1 1 0 1 1
m a i f o o
o a c s s a
a p t n r f
p o a e d o
t a v a e a
f s r t u t


*/
int n;
std::vector<std::vector<int>> rotates(std::vector<std::vector<int>> data){
    for (int i = 0; i < n; i += 1) {
    for (int j = i+1; j < n; j += 1) {
        swap(data[i][j], data[j][i]);
    }
    }
    for (int i = 0; i < n; i += 1) {
    for (int j = 0; j < n/2; j += 1) {
        swap(data[i][j], data[i][n-1-j]);
    }
}
}

int main()
{

    cin >> n;
    std::vector<std::vector<int>> paletN(n ,std::vector<int>(n));
    std::vector<std::vector<std::string>> paletL(n ,std::vector<std::string>(n));
    for(int y = 0; y < n; y++){
        for(int x = 0; x < n; x++){
            int num;
            cin >> num;
            paletN[x][y] = num;
        }
    }
    for(int y = 0; y < n; y++){
        for(int x = 0; x < n; x++){
            std::string l;
            cin >> l;
            paletL[x][y] = l;
        }
    }
    for(int t = 0; t < 4; t++){
        if(t!=0){
            paletN = rotates(paletN);
        }
        for(int y = 0; y < n; y++){
           for(int x = 0; x < n; x++){

               if(paletN[x][y] == 0){
                   std::cout << paletL[x][y];
            }
        }
    }


    }
    return 0;
}
