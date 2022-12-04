#include <iostream>

// Fisrt Thought : seems like knapsack problem. but with optimization
// least cost to get M memory
// 
using namespace std;

int N, M;
int mem[105];
int cost[105];

int MCOST = 0;
int dp[105][10005]; // idx == cost, value = maxMass

// m == max Weight
int solve(int m){

  // For one element
  //
  //for(int i = 0 ; i < N; i++){
  //  dp[0][cost[i]] = max(dp[cost[0][i]], mem[i]);
  //}

  for(int i = 1; i <= N; i++){
    for(int j = 0; j <= 10000; j++){
      //int idx = i - 1;
      if(j >= cost[i - 1])
        dp[i][j] = max(dp[i - 1][j - cost[i - 1]] + mem[i - 1], dp[i - 1][j]);
      dp[i][j] = max(dp[i][j], dp[i - 1][j]);
    }
  }
  int ans;
  for(int i = 0 ; i <= 10000; i++){
    if(dp[N][i] >= M){
      ans = i;
      break;
    }
      
  }
  return ans;
}


void printDP(){
  
  for(int i = 0 ; i <= N; i++){
    for(int j = 0 ; j <= MCOST; j++){
      cout << dp[i][j] << " ";
    }
    cout << "\n";
  }
}
int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  cin >> N >> M;

  for(int i = 0; i < N ; i++){
    cin >> mem[i];
    
  }

  for(int i = 0; i < N ; i++){
    cin >> cost[i];
    MCOST += cost[i];
  }

  cout << solve(M);
  //printDP();
  return 0;
}
