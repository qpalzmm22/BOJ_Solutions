#include <iostream>
#include <vector>

using namespace std;

int T, N, K;
int D[1005];
int W;

int memoi[1005];

void resetMemoi(){
  for(int i = 1; i <= N; i++){
    memoi[i] = -1;
  }
}

int dfs(int node, vector<short> (& adj)[1005]){

  //cout << "dfs : " << node << "\n";
    
  if(memoi[node] != -1){
    return memoi[node];
  }

  int maxVal = 0;
  for(int i = 0; i < adj[node].size(); i++){
    int prev = adj[node][i];
    maxVal = max(dfs(prev, adj), maxVal);
  }

  memoi[node] = maxVal + D[node];
  return memoi[node];
}

//void clearVec(){
//  for(int i = 0; i < N; i++){
//    adj[i].clear();
//    vector<short>().swap(adj[i]);
//  }
//}

int main(){
  cin >> T;

  while(T--){
    vector<short> adj[1005];
    cin >> N >> K;

    for(int i = 1; i <= N; i++){
      cin >> D[i];
    }
    
    for(int i = 0; i < K; i++){
      int from, to;
      cin >> from >> to;

      adj[to].push_back(from);
    }
    cin >> W;

    resetMemoi();
    cout << dfs(W, adj)<< "\n";
    //clearVec();
  }

  return 0;
}
