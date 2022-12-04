#include <iostream>
#define REM 10007
using namespace std;

int dp[1005];
int N;

int solve(int n){
  if(dp[n])
    return dp[n];
  
  if(n == 1)
    return 1;
  if(n == 2)
    return 3;

  return dp[n] = (solve(n - 1) + 2 * solve(n-2) ) % REM ;
}

int main(){
  cin >> N;
  cout << solve(N);
  return 0;
}
