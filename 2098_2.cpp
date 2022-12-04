#include <iostream>
#define INF 1e9

using namespace std;

int N;
int W[20][20];

int dp[20][1<<18];

int dfs(int u, int mask, int start){
  
  // all the values that are not u == v have values greater than 0
  // so this works without initialization
  if(dp[u][mask] != INF + 1)
    return dp[u][mask] ;

  if(mask == (1 << N)-1)
    return W[u][start];

  dp[u][mask] = INF;
  for(int i = 0 ; i < N; i++){
    if(mask & 1 << i) continue;
    int val = dfs(i, mask | (1 << i), start);
    dp[u][mask] = min(dp[u][mask], val + W[u][i]);
  }

  //cout << u << " " << mask << " " << dp[u][mask] <<  "\n";
  return dp[u][mask];
}
// TSP
int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);

  cin >> N;

  for(int i = 0; i < N ; i++){
    for(int j = 0 ; j < (1 << N ); j++){
      dp[i][j] = INF + 1;
    }
  }

  for(int i = 0 ; i < N; i++){
    for(int j = 0 ; j < N; j++){
      cin >> W[i][j];
      if(W[i][j] == 0)
        W[i][j] = INF;
    }
  }
  // can start from anywhere becuase the optimal answer will be same for all
  // points
  cout << dfs(0,1,0);

  return 0;
}
