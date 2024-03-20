#include <iostream>
#include <vector>

using namespace std;

int V;
vector<int> adj[1000005];
int dp[2][1000005];

int solve(int node, int prev, int cur){
  if(dp[cur][node] != -1)
    return dp[cur][node];

  dp[cur][node] = 0;
  
  if(cur == 1) dp[cur][node]++;
  
  for(int i = 0 ; i < adj[node].size(); i++){
    int nextNode = adj[node][i];

    if(prev == nextNode) continue;

    if(cur){
      dp[cur][node] += min(solve(nextNode, node, 1), solve(nextNode, node, 0));
    }else {
      dp[cur][node] += solve(nextNode, node, 1);
    }
  }
  return dp[cur][node];
}

int main(){

  cin.tie(0);
  ios_base::sync_with_stdio(0);

  cin >> V;

  for(int i = 0 ; i < V-1 ; i++){
    int a, b;
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  for(int i = 0 ; i < 2; i++){
    for(int j = 1 ; j <= V; j++){
      dp[i][j] = -1;
    }
  }

  cout << min(solve(1,0,0), solve(1,0,1));
  

  return 0;
}
