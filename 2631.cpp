#include <iostream>

using namespace std;

int N, result;
int num[205];
int dp[205];

int main(){

  cin.tie(0);
  ios_base::sync_with_stdio(false);

  cin >> N;
  for(int i = 1; i <= N; i++){
    cin >> num[i];
  }

  result = 0;
  for(int i = 1; i <= N; i++){
    dp[i] = 1;
    for(int j = 1; j < i ; j++){ // for all numbers idx smaller, 
      if(num[j] < num[i] && dp[i] <= dp[j]){
        //cout  << num[i] << "[" << dp[i] << "] " << num[j] << "[" << dp[j] << "]\n";
        dp[i]++;
      }
    }
    result = max(result, dp[i]);
  }
  cout << N - result;
  return 0;
}
