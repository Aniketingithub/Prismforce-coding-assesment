#include <iostream>
#include <map>
#include <vector>
#include <utility>

using namespace std;

int n, p, a, b;
int dp[12][12][12];

int DP(int n, vector<int> v, int i, int P, int A, int B) {
   if (i == n) {
      return P;
   }
   if(dp[i][A][B] != -1) return dp[i][A][B];
   // cout << i << " " << v[i] << " " <<  P << " " << A << " " << B << "\n";
   if(v[i] > P) {
      if(A) {
         if(i == 2 || i == 6) {
            v[i + 1] += v[i];
         }
         dp[i + 1][A][B] = max(dp[i + 1][A][B], DP(n, v, i + 1, P, A - 1, B));
      }
      if(B) {
         dp[i][A][B] = max(dp[i][A][B], DP(n, v, i, p, A, B - 1));
      }
      return dp[i][A][B];
   } else {
      dp[i + 1][A][B] = max(dp[i + 1][A][B], DP(n, v, i + 1, P - v[i], A, B));
      return dp[i + 1][A][B];
   }
}

int main(){
   cin >> n >> p >> a >> b;
   vector<int> v(n);
   for(int i = 0; i < n; ++i) {
      cin >> v[i];
      if(i == 2 || i == 6) v[i] += (v[i] / 2);
   }
   for(int i = 0; i <= 11; ++i) {
      for(int j = 0; j <= a; ++j) {
         for(int k = 0; k <= b; ++k) {
            dp[i][j][k] = -1;
         }
      }
   }
   int ans = DP(n, v, 0, p, a, b);
   for(int j = 0; j <= a; ++j) {
      for(int k = 0; k <= b; ++k) {
         if(dp[n][j][k] >= 0) {
            cout << "YES";
            return 0;
         }
      }
   }
   cout << "NO";
}
