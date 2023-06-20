#include <iostream>
#include <map>
#include <vector>
#include <utility>

using namespace std;

int abhimanyuPower, skips, regenerates;
int dp[12][12][12];

int DP(vector<int> monster, int i, int P, int A, int B) {
   if (i == 11) {
      return P;
   }
   if(dp[i][A][B] != -1) return dp[i][A][B];
   if(monster[i] > P) {
      if(A) {
         if(i == 2 || i == 6) {
            monster[i + 1] += monster[i];
         }
         dp[i + 1][A][B] = max(dp[i + 1][A][B], DP(monster, i + 1, P, A - 1, B));
      }
      if(B) {
         dp[i][A][B] = max(dp[i][A][B], DP(monster, i, abhimanyuPower, A, B - 1));
      }
      return dp[i][A][B];
   } else {
      dp[i + 1][A][B] = max(dp[i + 1][A][B], DP(monster, i + 1, P - monster[i], A, B));
      return dp[i + 1][A][B];
   }
}

int main(){
   cin >> abhimanyuPower >> skips >> regenerates;
   vector<int> monster(11);
   for(int i = 0; i < 11; ++i) {
      cin >> monster[i];
      if(i == 2 || i == 6) monster[i] += (monster[i] / 2);
   }
   for(int i = 0; i <= 11; ++i) {
      for(int j = 0; j <= skips; ++j) {
         for(int k = 0; k <= regenerates; ++k) {
            dp[i][j][k] = -1;
         }
      }
   }
   int ans = DP(monster, 0, abhimanyuPower, skips, regenerates);
   for(int j = 0; j <= skips; ++j) {
      for(int k = 0; k <= regenerates; ++k) {
         if(dp[11][j][k] >= 0) {
            cout << "YES";
            return 0;
         }
      }
   }
   cout << "NO";
}
