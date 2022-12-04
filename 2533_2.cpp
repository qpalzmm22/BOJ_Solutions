#include <iostream>
#include <string.h>
#include <vector>

using namespace std;


int N;
vector<int> adj[1000005];

int dp[2][1000005]; // least amount we need 

int dfs(int curnode, int prevnode, bool select){
  if(dp[select][curnode] != -1)
    return dp[select][curnode];

  dp[select][curnode] = 0;
  for(int i = 0; i < adj[curnode].size(); i++){
    int nextnode = adj[curnode][i];
    if(nextnode == prevnode) continue;

    if(select){
      dp[select][curnode] += min(dfs(nextnode, curnode, 0), dfs(nextnode, curnode, 1)) ;
    } else{
      dp[select][curnode] += dfs(nextnode, curnode, 1);
    }
  }
  if(select)
    dp[select][curnode]++;

  return dp[select][curnode];
}

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);

  cin >> N;
  
  for(int i= 0 ; i < N - 1; i++){
    int u, v ;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  memset(dp, -1, sizeof(dp));

  cout << min(dfs(1, 0, 0), dfs(1, 0, 1));

  return 0;
}
