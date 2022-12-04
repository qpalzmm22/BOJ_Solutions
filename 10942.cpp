#include <iostream>

using namespace std;

int N, M;
int num[100005];
bool dp[2005][2005];


void printDP(){
  for(int i = 0 ; i < N; i++){
    for(int j = 0 ; j < N; j++){
      cout << dp[i][j] << " ";
    }
    cout << "\n";
  }
}

void solve(){
  //i = start;
  //j = end;
  
  // Deals with 1, 2 characters palindromes
  for(int i = 0; i < N; i++){
    dp[i][i] = true;
    if(i + 1 < N && num[i] == num[i+1])
      dp[i][i+1] = true;
  }
  //printDP();
  
  // i : range
  // j : start
  // k : end
  int k;
  for(int i = 2; i < N; i++){
    for(int j = 0; i + j < N; j++){
      k = i + j;
      if(dp[j+1][k-1] && num[j] == num[k])
        dp[j][k] = true;
    }
  }
  //printDP();
  
}


int main(){
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  cin >> N;
  for(int i = 0; i < N; i++){
    cin >> num[i];
  }
  
  solve();


  cin >> M;
  for(int i = 0; i < M; i++){
    int S, E;
    cin >> S >> E;
    cout << dp[S-1][E-1] << "\n";
  }

  return 0;
}
