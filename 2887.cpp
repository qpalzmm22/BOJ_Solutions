// First Thought :: Get minimum spanning tree with prim's algorithm O(n^2) =>
// too big...
// pick one node and get the least distance. repeat it ultil all
// nodes are connected
//
// tip : use priority queue...=> but how..?


// Used quick sorting O(3VlgV)
// Used MST finding with KRuskal => O(V-1) => since it's pq
// Used Union Find with path compression, ranks = > O(a(n)) ~= O(1) 
// total => O(3VlgV + a(n)(V-1)) = O(VlgV)
#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <stdlib.h>

#define pii pair < int, int > // between what idx and what idx
#define pipii pair < int, pii > // weight

using namespace std;

//#define tiii tuple<int,int,int> 

int N;

pii xs[100005];
pii ys[100005];
pii zs[100005];
//vector< tuple <int, int, int > > coords;

int p[100005];
int r[100005];

bool lesspipii(pipii a, pipii b){
  return a.first < b.first;
}

priority_queue < pipii , vector<pipii> , greater<pipii> > pq; // diff, index

void printArr(){
  // ---------
  for(int i = 0 ; i < N; i++){
    cout << xs[i].first << " " << ys[i].first << " " << zs[i].first << "\n";
  }
}

int find(int a){
  if(p[a] == a)
    return a;
  else
    return p[a] = find(p[a]);
}
// unionize b to a
void uni(int a, int b){
  int u = find(a);
  int v = find(b);

  if( u == v )
    return;

  if(r[u] > r[v])
    swap(u, v);
  
  p[u] = v;
  
  if(r[u] == r[v]) r[v]++;
}

int main(){

  cin >> N;
  int x, y, z;

  for(int i = 0 ; i < N; i++){
    cin >> x >> y >> z;
    xs[i].first = x;
    ys[i].first = y;
    zs[i].first = z;
    xs[i].second = ys[i].second = zs[i].second = i;
  }

  for(int i = 0 ; i < N; i++){
    p[i] = i;
  }

  sort(xs, xs+N);
  sort(ys, ys+N);
  sort(zs, zs+N);
  //printArr();

  // compare i - i + 1  and push it to pq.
  for(int i = 0 ; i < N-1; i++){
    pq.push(make_pair(xs[i + 1].first -  xs[i].first, make_pair(xs[i+1].second , xs[i].second)));
    pq.push(make_pair(ys[i + 1].first -  ys[i].first, make_pair(ys[i+1].second , ys[i].second)));
    pq.push(make_pair(zs[i + 1].first -  zs[i].first, make_pair(zs[i+1].second , zs[i].second)));
  }

  // from pq pop and get MST
  long long total_dist = 0;
  int poped = 0;
  while(!pq.empty()){
    if(poped == N-1){
      break;
    }
    pipii elem = pq.top();
    int dist = elem.first;
    int n1 = elem.second.first;
    int n2 = elem.second.second;
    pq.pop();

    if(find(n1) == find(n2))
      continue;

    //cout << dist << " (" << n1 << " " << n2 << ")\n";

    uni(n1, n2);
    total_dist += dist;
    poped++;
    //cout << dist <<"\n";
  }

  //cout << "ans : "<<dist <<"\n";
  cout << total_dist <<"\n";

  return 0;
}
