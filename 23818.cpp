#include <iostream>
#include <vector>
#include <map>

#define pii pair <int, int>

using namespace std;

int N, M, K;

vector < pii > adj[100005];
// Group
//
int relationship[100005];
int visited[100005];
bool is_error[100005];

void dfs(int u, int prev, int g_num){
  
  visited[u] = g_num;

  for(int i = 0 ; i < adj[u].size(); i++){
    int v = adj[u][i].first;
    int rela = adj[u][i].second; // 0 : friend, 1 : enemy
  
    if(v == prev) continue;

    if(visited[v]){
      if(rela == 0 && (relationship[u] != relationship[v])) is_error[g_num] = true;
      if(rela == 1 && (relationship[u] == relationship[v])) is_error[g_num] = true;
      continue;
    }

    if(rela == 0){
      relationship[v] = relationship[u];
    }else {
      relationship[v] = 1 - relationship[u];
    }

    dfs(v, u, g_num);
  }

}

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cin >> N >> M >> K;

  for(int i = 0; i < M; i++){
    int t, a, b;
    cin >> t >> a >> b;
    adj[a].push_back(make_pair(b, t));
    adj[b].push_back(make_pair(a, t));
  }

  int group_num = 1;
  for(int i = 1; i <= N; i++){
    if(visited[i]) continue;
    dfs(i,0, group_num);
    group_num++;
  }

  for(int i = 0 ; i < K; i++){
    int a, b;
    cin >> a >> b;

    if(visited[a] != visited[b]){
      cout << "Unknown\n";
    }else if(is_error[visited[a]]){
      cout << "Error\n";
    }else if(relationship[a] == relationship[b]){
      cout << "Friend\n";
    }else if(relationship[a] != relationship[b]){
      cout << "Enemy\n";
    }
  }
  return 0;
}
