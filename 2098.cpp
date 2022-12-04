// solve with dp. Pope

#include <iostream>

#define INF 0 //2e15
#define MX 2e15

using namespace std;

//int visited[20];

int W[20][20];
long long dp[18][1 << 18];
int N;

// visited = 16 bit
long long dfs(int node, long long visited){
  //cout << "node : " << node << " visited :";
  //printf("%d(%x)\n", visited, visited);
  
  // visited all the nodes
  if(visited == ((1 << N)  - 1)){

    //cout << ">> last node : " << node << " visited :" << visited  << " \n";
    return W[node][0]; // way to 1
  }

  if(dp[node][visited] != 0)
    return dp[node][visited];

  dp[node][visited] = MX;

  for(int i = 0; i < N; i++){
    
    if( W[node][i] == 0) continue; // unreachable
    
    if( (visited | (1 << i)) == visited) continue; // visited
    
    long long val = dfs(i , visited | (1 << i));
    
    if(val == 0) continue; // if it's blocked, don't go this way 
  
    dp[node][visited] = min(dp[node][visited], W[node][i] + val);
    //printf("(%d , %d), %lld(%llx) = %lld \n", node ,i, visited, visited, dp[node][visited]);
  }
  //cout << "dp[";
  return dp[node][visited];
}

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  cin >> N;
  
  for(int i = 0; i < N; i++){
    for(int j = 0 ; j < N; j++){
      cin >> W[i][j];
    }
  }
  // All the minimum distance would be same becuase it's TSP problem.
  cout << dfs(0, 1);

  return 0;
}
