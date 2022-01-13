// 1. use dijkstra for N times.
// 2. use floyd..?
#include <iostream>
#include <queue>

#define pii pair<int, int>
#define INF 1e9

using namespace std;

vector<pii > adj[105]; // cost , v

int dist[105];
int items[105];

void dijkstra(int n){
  priority_queue<pii > pq;
  pq.push(make_pair(0, n));
  dist[n] = 0;

  while(!pq.empty()){
    int nv2cost = -pq.top().first;
    int v2 = pq.top().second;
    pq.pop();

    if(nv2cost > dist[v2])
      continue;

    for(int i = 0; i < adj[v2].size(); i++){
      int v2v3cost = adj[v2][i].first;
      int v3 = adj[v2][i].second;
      
      if(dist[v3] > v2v3cost + nv2cost){
        dist[v3] = v2v3cost + nv2cost;
        pq.push(make_pair(-dist[v3], v3));
      }
    }
  }
}

void resetDist(int n){
  for(int i = 1 ; i <= n; i++){
    dist[i] = INF;
  }
}

int calcItems(int n, int m){
  int totitem = 0;
  for(int i = 1 ; i <= n; i++){
    if(dist[i] <= m){
      totitem += items[i];
//     cout << i <<" <= " << dist[i] << "\n";
    }
  }
  return totitem;
}

int main(){
  int n, m, r;

  cin >> n >> m >> r;
  for(int i = 1; i <= n; i++) cin >> items[i] ;
  
  while(r--){
    int v1, v2, v1v2cost;
    cin >> v1 >> v2 >> v1v2cost;
    adj[v1].push_back(make_pair(v1v2cost, v2));
    adj[v2].push_back(make_pair(v1v2cost, v1));
  }

  int maxItem = 0;
  
  for(int i = 1; i <= n; i++){
    resetDist(n);
    dijkstra(i);
    maxItem = max(calcItems(n, m), maxItem);
  }

  cout << maxItem;

  return 0;
}
