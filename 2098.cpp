// solve with dp. Pope

#include <iostream>

#define INF 2e9

using namespace std;

int visited[20];

int W[20][20];
int dp[20][1 << 18];
int N;

// visited = 16 bit
int dfs(int node, int visited){
  //cout << "node : " << node << " visited :" << visited  << " \n";

  if(visited == (1 << N) - 1){
    
    //cout << ">> node : " << node << " visited :" << visited  << " \n";
    if(W[node][0] == 0)
      return INF;
    else 
      return W[node][0]; // way to 1
  }

  if(dp[node][visited] != INF)
    return dp[node][visited];

  for(int i = 0; i < N; i++){
    
    if( (visited | (1 << i)) == visited) continue;

    if( W[node][i] == 0) continue;

    dp[node][visited] = min(dp[node][visited], W[node][i] + dfs(i, visited | (1 << i)));
  }
  return dp[node][visited];
}

int main(){
  cin >> N;
  

  // change it to adj list cuz i'm familiar with this
  for(int i = 0; i < N; i++){
    for(int j = 0 ; j < N; j++){
      cin >> W[i][j];
    }
  }
  
  for(int i = 0 ; i < N; i++){
    for(int j = 0; j < (1 << 17) ; j++){
      dp[i][j] = INF;
    }
  }

  cout << dfs(0, 1);
  
  return 0;
}
