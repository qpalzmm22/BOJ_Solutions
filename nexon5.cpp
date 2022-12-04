#include <iostream>

using namespace std;

int dp[100005];
int N;

int solve(int n){
  if(dp[n])
    return dp[n];
  
  if(n == 1)
    return 2;
  if(n == 2)
    return 9;

  return dp[n] = (2 * solve(n - 1) + 9 * solve(n-2)) - 4 ;
}

int main(){
  cin >> N;
  cout << solve(N);
  return 0;
}
