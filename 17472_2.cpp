#include <iostream>
#include <queue>

#define INF 100
#define UNF make_pair(-1, -1)

#define pii pair < int, int >
#define pipii pair < int, pii >

using namespace std;

int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};

int p[100];

priority_queue < pipii > pq;

int N, M;
int map[20][20];
int dist[20][20];
int group[20][20];
int g = 1;

int find(int a){
  if(p[a] < 0)
    return a;
  return p[a] = find(p[a]);
}

// use dfs or bfs
void traversal(int y, int x, int g){
  queue < pii > q;
  q.push(make_pair(y, x));
  group[y][x] = g;
  while(!q.empty()){
    int newy = q.front().first;
    int newx = q.front().second;
    q.pop();
    
    //cout << newy << " " << newx << "\n";

    for(int i = 0; i < 4; i++){
      int nextx = newx + dx[i];
      int nexty = newy + dy[i];

      if(nextx < 0 || nexty < 0 || nextx >= M || nexty >= N)
        continue;

      if(!map[nexty][nextx] || group[nexty][nextx])
        continue;

      q.push(make_pair(nexty, nextx));
      group[nexty][nextx] = g;
    }
  }
}

pii swim_across(int y, int x, int dir, int orig_group, int distance){
  int nexty = y + dy[dir];
  int nextx = x + dx[dir];

  if(nexty < 0 || nextx < 0 || nextx >= M || nexty >= N || group[nexty][nextx] == orig_group)
    return UNF;
  
  if(map[nexty][nextx] && group[nexty][nextx] != orig_group)
    return make_pair(distance, group[nexty][nextx]);

  return swim_across(nexty, nextx, dir, orig_group, distance+1);
}

void uni(int a, int b){
  int u = find(a);
  int v = find(b);

  if(find(a) == find(b))
    return;

  if(p[u] > p[v])
    swap(u, v);

  if(p[u] == p[v])
    p[u]--;
  p[v] = u;
}

void printDist(){
  for(int i = 1 ; i < g ; i++){
    for(int j = 1 ; j < g ; j++){
      cout << dist[i][j] << " ";
    }
    cout << "\n";
  }
}

void printGroup(){
  for(int i = 0 ; i < N ; i++){
    for(int j = 0 ; j < M ; j++){
      cout << group[i][j] << " ";
    }
    cout << "\n";
  }
}

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);

  cin >> N >> M;
  
  for(int i = 0; i < N; i++){
    for(int j = 0 ; j < M ; j++){
      cin >> map[i][j];
    }
  }
  for(int i = 0; i < N; i++){
    for(int j = 0 ; j < M ; j++){
      if(map[i][j] && !group[i][j]){
        traversal(i, j, g);
        g++;
      }  
    }
  }
  for(int i = 1 ; i < g; i++){
    p[i] = -1;
  }

  for(int i = 1 ; i < g; i++){
    for(int j = 1 ; j < g; j++){
      if(i == j) continue;
      dist[i][j] = INF;
    }
  }

  //printGroup();
  for(int i = 0; i < N; i++){
    for(int j = 0 ; j < M ; j++){
      int orig_group = group[i][j];
      if(map[i][j]){
        for(int k = 0; k < 4; k++){
          pii land = swim_across(i, j, k, orig_group, 0);
          if(land == UNF || land.first < 2)
            continue;
          else{
            dist[orig_group][land.second] = min(dist[orig_group][land.second], land.first);
          }
        }
      }
    }
  }

  //printDist();

  for(int i = 1 ; i < g; i++){
    for(int j = 1 ; j < g; j++){
      if(i == j  || dist[i][j] == INF) continue;
      pq.push(make_pair(-1 * dist[i][j], make_pair(i, j)));
    }
  }

  int total_dist = 0 ;
  
  int connected_group = 1;

  while(!pq.empty()){
    int w = -1 * pq.top().first;
    int v1 = pq.top().second.first;
    int v2 = pq.top().second.second;
    pq.pop();

    if(find(v1) == find(v2))
      continue;

    uni(v1, v2);
    total_dist += w;
    connected_group++;
    //cout << "uni : " << v1 << " " << v2 << " " << w <<  "\n";
  }
  
  //cout << "con g : " << connected_group  << " " << g - 1 <<  "\n";

  if(connected_group != g - 1)
    cout << -1;
  else
    cout << total_dist ;

}
