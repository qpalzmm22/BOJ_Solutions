#include <iostream>
#include <string.h>
#include <queue>
#define pii pair < int, int >
#define pipii pair < int, pii >

using namespace std;

int N, M;

priority_queue < pipii > pq;

int p[100005];

int find(int a){
  if(p[a] < 0)
    return a;
  return p[a] = find(p[a]);
}

void uni(int a, int b){
  int u = find(a);
  int v = find(b);

  if(u == v)
    return;

  if(p[u] > p[v])
    swap(u, v);
  p[v] = u;

  if(p[u] == p[v])
    p[u]--;
}


// apply prims algo with up to E - 2 edges
int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);

  cin >> N >> M;
  
  memset(p, -1, sizeof(int) * (N+1));

  for(int i = 0 ; i < M ; i++){
    int u, v, w;
    cin >> u >> v >> w;

    pq.push(make_pair(-1 * w, make_pair(u, v)));
  }

  int i = 0;
  int total_w = 0;
  while(!pq.empty() && i < N - 2){
    

    int w = -1 * pq.top().first;
    int u = pq.top().second.first;
    int v = pq.top().second.second;
    pq.pop();
    
    if(find(u) == find(v))
      continue;

    total_w += w;
    i++;
    uni(u, v);

  }
  cout << total_w;

  return 0;
}
