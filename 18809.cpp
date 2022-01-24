#include <iostream>
#include <vector>
#include <queue>

#define pii pair<int, int>

using namespace std;

int N, M, G, R;
int map[55][55];

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, -1, 0, 1};

int used[10]; //seed place
vector<pii > seed;
int rq[10];
int gq[10];

int gmap[55][55];
int rmap[55][55];

void resetgmap(){
  for(int i = 0; i < N; i++){
    for(int j = 0; j < M; j++){
      gmap[i][j] = -1;
    }
  }
}

void resetrmap(){
  for(int i = 0; i < N; i++){
    for(int j = 0; j < M; j++){
      rmap[i][j] = -1;
    }
  }
}
void printrmap(){
  cout << "-- rmap --\n";
  for(int i = 0; i < N; i++){
    for(int j = 0; j < M; j++){
      cout << rmap[i][j] << " ";
    }
    cout << "\n";
  }
}

void printgmap(){
  cout << "-- gmap --\n";
  for(int i = 0; i < N; i++){
    for(int j = 0; j < M; j++){
      cout << gmap[i][j] << " ";
    }
    cout << "\n";
  }
}
int g_bfs(int (&g_arr)[10]){
  queue<pii > g_q;
  for(int i = 0; i < G; i++){
    g_q.push(seed[g_arr[i]]);
    gmap[seed[g_arr[i]].first][seed[g_arr[i]].second] = 0;
  }

  int flowers = 0;
  while(!g_q.empty()){
    int y = g_q.front().first;
    int x = g_q.front().second;
    //cout << "g_bfs " << y << " : " << x << "\n";
    g_q.pop();

    //if (gmap[y][x] != -1)
      //continue;

    for(int i = 0 ; i < 4; i++){
      int uy = y + dy[i];
      int ux = x + dx[i];

      if(uy < 0 || ux < 0 || uy >= N || ux >= M)
        continue;

      if(map[uy][ux] == 0) // lake
        continue;

      //cout << "gbfs [ " << uy << ", " << ux << "]\n";
      if(gmap[uy][ux] == -1 && rmap[uy][ux] == gmap[y][x] + 1){
        gmap[uy][ux] = gmap[y][x] + 1;
        flowers++;
      } else if(rmap[uy][ux] > gmap[y][x] + 1 && gmap[uy][ux] == -1){
        gmap[uy][ux] = gmap[y][x] + 1;
        g_q.push(make_pair(uy, ux));
      }
    }
  }
  return flowers;
}

void r_bfs(int (&r_arr)[10]){
  queue<pii > r_q;
  for(int i = 0; i < R; i++){
    r_q.push(seed[r_arr[i]]);
    rmap[seed[r_arr[i]].first][seed[r_arr[i]].second] = 0;
  }

  while(!r_q.empty()){
    int y = r_q.front().first;
    int x = r_q.front().second;
    //cout << "r_bfs " << y << " : " << x << "\n";
    r_q.pop();

    //if (rmap[y][x] != -1)
    //  continue;

    for(int i = 0 ; i < 4; i++){
      int uy = y + dy[i];
      int ux = x + dx[i];

      if(uy < 0 || ux < 0 || uy >= N || ux >= M)
        continue;

      if(map[uy][ux] == 0) // lake
        continue;
      
      if(rmap[uy][ux] != -1)
        continue;
      //cout << "rbfs [ " << uy << ", " << ux << "]\n";
      rmap[uy][ux] = rmap[y][x] + 1;
      r_q.push(make_pair(uy, ux));
      //printrmap();
    }
  }
}

int g_dfs(int g_indth, int num){
  //cout << ">g_dfs " << g_indth << " num : " << num << "\n";
  int maxf = 0;
  if(num == G){
    resetgmap();
    int ret = g_bfs(gq);
    printgmap();
    cout << ret << "\n";
    return ret;
  }
  for(int i = g_indth; i < seed.size(); i++){
    if(used[i])
      continue;
    
    //cout << "g_dfs " << seed[i].first << " : " << seed[i].second << "\n";
    gq[num] = i;

    maxf = max(maxf, g_dfs(i + 1, num + 1));
  }
  return maxf;
}

int r_dfs(int g_indth, int num){
  //cout << ">r_dfs " << g_indth << " num : " << num << "\n";
  int maxf = 0;
  if(num == R){
    resetrmap();
    r_bfs(rq);
    printrmap();
    return g_dfs(0, 0);
  }
  for(int i = g_indth; i < seed.size(); i++){
    

    rq[num] = i;
  
    used[i] = 1;
    //cout << "[i]" << i  << "[num ] : " << num << "\n";
    //cout << "r_dfs " << seed[i].first << " : " << seed[i].second << "\n";
    maxf = max(maxf, r_dfs(i + 1, num + 1));
    used[i] = 0;

  }
  //cout << "maxf : " << maxf << "\n";
  return maxf;
}

int main(){
  cin >> N >> M >> G >> R;
  for(int i = 0; i < N; i++){
    for(int j = 0; j < M; j++){
      cin >> map[i][j];
      if(map[i][j] == 2)
        seed.push_back(make_pair(i,j));
    }
  }
  int maxf = 0;
  cout << r_dfs(0, 0);
  return 0;
}
