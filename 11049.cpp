#include <iostream>

#define INF 2147483647
using namespace std;

int N;

int num[505];

unsigned int dp[505][505];

void printMat(){
  for(int i = 0 ; i < N + 1; i++){
    cout << num[i] << " ";
  }
}

// idx of matrix
unsigned int solve(int start, int end){

  //cout << "s : "<< start << " " << end << "\n";
  
  if(dp[start][end]){
    return dp[start][end];
  }
  
  if(end - start == 1){
    dp[start][end] = num[start] * num[end] * num[end + 1] ;
    //cout << "[1]end : "<< start << " " << end << " "  << dp[start][end]<< "\n";
    return dp[start][end];
  }

  if(end - start == 0){
    return 0;
  }

  dp[start][end] = INF;
  for(int i = start; i < end; i++) {
    dp[start][end] = min(dp[start][end], solve(start, i) + solve(i + 1, end) + num[start] * num[i + 1] * num[end + 1]);
    //cout << "middle : [" << start << " " << i << " "<<  end << "] : \n" ;
    //cout << dp[start][i] << " + ";
    //cout << dp[i + 1][end] << " + ";
    //cout << num[start] * num[i + 1]  * num[end + 1] << " = " << dp[start][end]<< "\n";
  }
  //cout << "["<< start << "] [" << end << "]  :"  << dp[start][end]<< "\n";
  return dp[start][end];
}

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  cin >> N;

  for(int i = 0 ; i < N ; i++){
    int n1, n2;
    cin >> n1 >> n2;

    num[i] = n1;
    num[i + 1] = n2;
  }

  
  cout << solve(0, N - 1) << "\n";
  return 0;
}
