#include <iostream>
#include <vector>
#define INF 1e15
#define pii pair< int, int >
#define ppii pair < int , pii > // weight , u, v

using namespace std;
// O(VE)

//int mat[505][505];
long long dist[505];
int N, M; 

vector < ppii> edges;

int main(){
  cin >> N >> M;
  int S = 1;

  for(int i = 1 ; i <= N; i++){
    dist[i] = INF;
  }

  for(int i = 0; i < M; i++){
    int u, v, w;
    cin >> u >> v >> w;
    edges.push_back(make_pair(w, make_pair(u,v)));
  }
  dist[S]=0;

  for(int i = 0 ; i < N - 1;i++){
    for(int j = 0 ; j < edges.size(); j++){
      int w = edges[j].first;
      int u = edges[j].second.first;
      int v = edges[j].second.second;
      if (dist[u] != INF && dist[u] + w < dist[v]){
        dist[v] = dist[u] + w;
      }
    }
  }
  
  //for(int i = 1 ; i <= N; i++){
  //  cout << dist[i] << " ";
  //}

  for(int j = 0 ; j < edges.size(); j++){
    int w = edges[j].first;
    int u = edges[j].second.first;
    int v = edges[j].second.second;
    if (dist[u] != INF && dist[u] + w < dist[v]){
      cout << "-1" ;
      return 0;
    }
  }
  for(int i = 2; i <= N; i++){
    if(dist[i] == INF)
      cout << "-1" << "\n";
    else
      cout << dist[i] << "\n";
  }
  return 0;
}
