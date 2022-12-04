#include <iostream>

using namespace std;

int dp[105][105][105];

string A, B, C;

int solve(){
  for(int i = 1 ; i <= A.size(); i++){
    for(int j = 1 ; j <= B.size(); j++){
      for(int k = 1 ; k <= C.size(); k++){
        if(A[i-1] == B[j-1] && B[j-1] == C[k-1]){
          dp[i][j][k] = dp[i-1][j-1][k-1] + 1;
        } else {
          dp[i][j][k] = max(dp[i-1][j][k], max(dp[i][j-1][k], dp[i][j][k-1]));
        }
      }
    }
  }
  return dp[A.size()][B.size()][C.size()];
}

void printDP(){

  for(int i = 1 ; i <= A.size(); i++){
    for(int j = 1 ; j <= B.size(); j++){
      for(int k = 1 ; k <= C.size(); k++){
        cout << dp[i][j][k] << " ";
      }
      cout << "\n";
    }
    cout << "\n---\n";
  }
}

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(false);


  cin >> A >> B >> C;

  cout << solve();
  //printDP();
  return 0;
}
