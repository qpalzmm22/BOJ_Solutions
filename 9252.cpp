#include <iostream>
#include <string>
#include <vector>
#include <tuple>

#define pii pair < int, int >


// Use KMP algorithm ==> wrong
// Maybe two pointer might do? ==> wrong?
// Use 2d dp <= maybe 
//
using namespace std;

string A, B;
vector<char> ans;

int dp[1005][1005];
//ppii solve(){
void solve(){
  for(int i = 1 ; i <= A.size(); i++){
    for(int j = 1 ; j <= B.size(); j++){
      if(A[i-1] == B[j-1]){
        dp[i][j] = dp[i-1][j-1] + 1;
      } else{
        dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
      }
    }
  }
}

void backtrack(int i, int j){

  int val = dp[i][j];
  if(!dp[i][j]){
    //cout << dp[i][j];
    return ;
  }
  if(A[i-1] == B[j-1]){
    backtrack(i-1, j-1);
    cout << A[i-1];
  }else {
    dp[i-1][j] > dp[i][j-1] ? backtrack(i-1, j) : backtrack(i, j-1);
  }
}

void printDP(){
  for(int i = 0 ; i <= A.size(); i++){
    for(int j = 0 ; j <= B.size(); j++){
      cout << dp[i][j] << " ";
    }
    cout << "\n";
  }
}

int main(){

  cin >> A >> B;
  
  solve();

  //cout << get<0>(ans) << "\n";
  //cout << get<1>(ans);
  //printDP();
  cout << dp[A.size()][B.size()] << "\n";
  backtrack(A.size(), B.size());

  return 0;
}
