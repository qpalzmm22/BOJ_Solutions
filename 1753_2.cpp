#include <iostream>
#include <queue>

#define INF 1e9

#define pii pair < int , int >
using namespace std;

priority_queue < pii > pq;
int V, E;
int S;
int dist[20005];

vector< pii > adj[20005];

void setDist(){
  for(int i = 1; i <= V ;i++){
    dist[i] = INF;
  }
}

void dijkstra(int start){
  
  dist[start] = 0;
  pq.push(make_pair(0,start));

  while(!pq.empty()){
    int xv1cost = -1 * pq.top().first ;
    int v1 = pq.top().second;
    pq.pop();

    for(int i = 0 ; i < adj[v1].size(); i++){
      int v2 = adj[v1][i].second;
      int v1v2cost = adj[v1][i].first;

      if(dist[v2] > xv1cost + v1v2cost){
        dist[v2] = xv1cost + v1v2cost;
        pq.push(make_pair(-1*dist[v2], v2));
      }
    }
  }
}

int main()
{
  cin >> V >> E; 
  cin >> S;
  for(int i = 0 ; i < E; i++){
    int u,v,w;
    cin >> u >> v >> w;
    adj[u].push_back(make_pair(w,v));
  }
  
  setDist();
  dijkstra(S);

  for(int i = 1; i <= V ; i++){
    if(dist[i] == INF)
      cout << "INF\n";
    else
      cout << dist[i] << "\n";
  }
  
  return 0;
}
