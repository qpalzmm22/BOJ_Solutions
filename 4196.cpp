#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

int T;

bool visited[100005];
vector <int> adj[100005];
vector <int> rev_adj[100005];
stack <int> s;

void reset(int n){
  // reset
  for(int i = 1 ; i <= n ; i++){
    adj[i].clear();
    rev_adj[i].clear();
  }
}

void dfs(int v){
  visited[v] = true;
  for(int i = 0 ; i < adj[v].size(); i++){
    int u = adj[v][i];

    if(visited[u]) continue;

    dfs(u);
  }
  s.push(v);
}

void rev_dfs(int v, int idx){
  cout << ">"<< v << " ";
  visited[v] = true;
  for(int i = 0 ; i < rev_adj[v].size(); i++){
    int u = rev_adj[v][i];
    if(visited[u]) continue;

    rev_dfs(u, idx);
  }
  
}

// SCC => dfs and push in stack, dfs 
// ottoke ottoke...
int main(){
  cin >> T;
  while(T--){
    int V, E;
    cin >> V >> E;
    
    for(int i = 0; i < E; i++){
      int u, v;
      cin >> u >> v;
      adj[u].push_back(v);
      rev_adj[v].push_back(u);
    }

    for(int i = 1 ; i <= V; i++){
      if(visited[i]) continue;

      dfs(i);
    }

    memset(visited, 0, sizeof(visited));

    int idx = 1;
    while(!s.empty()){
      int v = s.top();
      s.pop();

      if(visited[v]) continue;

      rev_dfs(v,idx);
      idx++;
    }

    cout << total << "\n";
    reset(V);
  }

  return 0;
}
