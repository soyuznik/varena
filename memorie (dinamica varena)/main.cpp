#include <bits/stdc++.h>

using namespace std;




std::vector<int> nums;
std::vector<std::vector<int>> dp;


int distinct(int x , int y){
    if(x==y){return 1;}
    if(dp[x][y] != 0){
         return dp[x][y];
    }
    std::set<int> ses(nums.data() + x - 1 ,  nums.data() + y);
    dp[x][y] = ses.size();
    return dp[x][y];
}

int main()
{
   /*
   8 4
   7 43 7 21 35 7 7 7
   2 7
   3 5
   6 8
   2 2
   */
   freopen("memorie.in", "r", stdin);
   //freopen("memorie.out", "w", stdout);
   int n , q;
   dp = std::vector<std::vector<int>>(n , std::vector<int>(n));
   cin >> n >> q;
   for(int i = 0; i < n; i++){
      int num;
      cin >> num;
      nums.push_back(num);
   }
   for(int i = 0; i < q; i++){
      int x , y;
      cin >> x >> y;
      std::cout << distinct(x , y) << "\n";
   }
}
