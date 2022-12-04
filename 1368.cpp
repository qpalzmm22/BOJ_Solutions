#include <iostream>
#include <queue>
#include <algorithm>
#define pii pair< int, int >
#define pipii pair< int, pii >

using namespace std;

priority_queue< pipii > pq;
int N;

int p[305];

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
  if(p[u] == p[v])
    p[u]--;
  p[v] = u;
}
int main(){
  cin >> N;

  for(int i = 0 ; i <= N ; i++){
    p[i] = -1;
  }
  
  for(int i = 1 ; i <= N ; i++){
    int w;
    cin >> w;
    pq.push(make_pair(-1 * w, make_pair(0, i)));
  }

  for(int i = 1 ; i <= N; i++){
    for(int j = 1 ;j  <= N ; j++){
      int w;
      cin >> w;
      if(i == j)
        continue;
      pq.push(make_pair(-1 * w, make_pair(i, j)));
    }
  }
  
  int total = 0;
  while(!pq.empty()){
    int w = -1 * pq.top().first;
    int v1 = pq.top().second.first;
    int v2 = pq.top().second.second;
    pq.pop();

    if(find(v1) == find(v2))
      continue;

    uni(v1, v2);
    total += w;
    
  }

  cout << total;

  return 0;
}
