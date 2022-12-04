#include <iostream>
#include <string.h>
#include <algorithm>

using namespace std;

int dy[4] = {0, -1, 0 , 1};
int dx[4] = {-1, 0 , 1, 0};
int N , M;

int p[2505];
int rooms[2505];

int map[55][55];
bool visited[55][55];

int find(int a){
  if(p[a] < 0)
    return a;
  return find(p[a]);
}

void uni(int a, int b){
  int u = find(a);
  int v = find(b);

  if(u == v)
    return;

  if(p[u] > p[v])
    swap(u, v);

  if(p[v] == p[u])
    p[u]--;
  p[v] = u;

}


int dfs(int y, int x){
  int rooms = 1;
  visited[y][x] = true;

  for(int i = 0; i < 4; i++){
    
    if((1 << i) & map[y][x]) continue;
    
    int nexty = y + dy[i];
    int nextx = x + dx[i];
    
    if(visited[nexty][nextx]) continue;
    
    uni(y*M + x, nexty*M + nextx);
    rooms += dfs(nexty, nextx);
  }
  return rooms;
}

int solve(int y, int x){
  int max_1_rooms = 0;
  for(int i = 0; i < 4; i++){
    if((1 << i) & map[y][x]){
      int nexty = y + dy[i];
      int nextx = x + dx[i];
      
      if(nextx < 0 || nexty < 0 || nextx >= M || nexty >= N)
        continue;

      int u = find(y*M+x);
      int v = find(nexty*M + nextx);
      if( u == v ) continue;

      max_1_rooms = max(max_1_rooms, rooms[u] + rooms[v]);
    }
  }

  return max_1_rooms;
}

int main(){
  cin >> M >> N;

  memset(p, -1, sizeof(p));

  for(int i = 0 ; i < N ; i++){
    for(int j = 0 ; j < M ; j++){
      cin >> map[i][j];
    }
  }

  int group_num = 0;
  int max_rooms = 0;
  // N^2
  for(int i = 0 ; i < N ; i++){
    for(int j = 0 ; j < M ; j++){
      if(visited[i][j]) continue;
      rooms[i*M+j] = dfs(i, j);
      max_rooms = max(max_rooms, rooms[i*M+j]);
      group_num++;
    }
  }

  int max_1_rooms = 0;
  for(int i = 0 ; i < N ; i++){
    for(int j = 0 ; j < M ; j++){
      max_1_rooms = max(max_1_rooms, solve(i, j));
    }
  }

  cout << group_num << "\n";
  cout << max_rooms << "\n";
  cout << max_1_rooms << "\n";

  return 0;
}
