// solve with dp. Pope

#include <iostream>

#define INF 1e17

using namespace std;

//int visited[20];

int W[20][20];
long long dp[20][1 << 20];
int N;

// visited = 16 bit
long long dfs(int node, long long  visited){
  cout << "node : " << node << " visited :";
  printf("%lld(%llx)\n", visited, visited);
  
  if(visited == ((1 << N)  - 1)){
    
    //cout << ">> node : " << node << " visited :" << visited  << " \n";
    if(W[node][0] == 0){
      return INF;
    }
    else {
      return W[node][0]; // way to 1
    }
  }

  if(dp[node][visited] != INF)
    return dp[node][visited];

  for(int i = 0; i < N; i++){
    
    if( (visited | (1 << i)) == visited) continue; // visited

    if( W[node][i] == 0) continue; // unreachable
    //if( = dps(i, visited | (1 << i)) == INF) continue;

    dp[node][visited] = min(dp[node][visited], W[node][i] + dfs(i, visited | (1 << i)));
  }
  //cout << "dp[";
  //printf("%d(%x)] = %d ]\n", visited, visited, dp[visited]);
  return dp[node][visited];
}

int main(){
  
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> N;
  
  for(int i = 0; i < N; i++){
    for(int j = 0 ; j < N; j++){
      cin >> W[i][j];
    }
  }
  for(int i = 0; i < N; i++){
    for(int j = 0; j < (1 << N) ; j++){
      dp[i][j] = INF;
    }
  }
  // All the minimum distance would be same becuase it's TSP problem.
  cout << dfs(0, 1);

  return 0;
}
