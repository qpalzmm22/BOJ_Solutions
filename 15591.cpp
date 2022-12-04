#include <iostream>
#include <vector>
#define INF 2e9
#define pii pair < int, int >
using namespace std;
int N, Q;

vector < pii > adj[5005];
int usado[5005][5005];

void dfs(int start, int prev, int cur, int min_val){
  //cout << start << " " << prev << " " << cur << " " << min_val << "\n";
  for(int i = 0 ; i < adj[cur].size(); i++){
    int v = adj[cur][i].first;
    int w = adj[cur][i].second;
    if(prev == v)
      continue;

    //cout << cur << " " << v << " " << w << "\n";
    
    int val = min(min_val, w);

    usado[start][v] = val;
    dfs(start, cur, v, val);
  }
}

void printUsado(){
  cout << "usado : \n";
  for(int i = 1; i <= N; i++){
    for(int j = 1; j <= N; j++){
      cout << usado[i][j] << " ";
    }
    cout << "\n";
  }
}
int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cin >> N >> Q;
  
  for(int i = 0; i < N -1 ; i++){
    int u, v, w;
    cin >> u >> v >> w;
    adj[u].push_back(make_pair(v, w));
    adj[v].push_back(make_pair(u, w));
  }

  // N * N
  for(int i = 1 ; i <= N; i++){
    dfs(i, 0, i, INF);
  }
  //printUsado();
 // Q * N = > N^2 = 2N^2
  for(int i = 0; i < Q; i++){
    int k, v2;
    cin >> k >> v2;
    int count = 0 ;
    for(int j = 1 ; j <= N; j++){
      if(usado[v2][j] >= k)
        count++;
    }
    cout << count << "\n";
  }

  return 0;
}
