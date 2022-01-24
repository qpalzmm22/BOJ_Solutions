#include <iostream>
#include <vector>
#include <queue>

#define GRN 1
#define RED 0

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

int costmap[2][55][55]; // 1 for green, 0 for red


void resetcostmap(){
  for(int k = 0 ; k < 2; k++){
    for(int i = 0; i < N; i++){
      for(int j = 0; j < M; j++){
        costmap[k][i][j] = -1;
      }
    }
  }
}
void printrmap(){
  cout << "-- gmap --\n";
  for(int i = 0; i < N; i++){
    for(int j = 0; j < M; j++){
      cout << costmap[GRN][i][j] << " ";
    }
    cout << "\n";
  }
}

void printgmap(){
  cout << "-- rmap --\n";
  for(int i = 0; i < N; i++){
    for(int j = 0; j < M; j++){
      cout << costmap[RED][i][j] << " ";
    }
    cout << "\n";
  }
}
int bfs(int (&g_arr)[10], int (&r_arr)[10]){
  priority_queue <pair<int, pii > > q;
  for(int i = 0; i < G; i++){
    q.push(make_pair(GRN,seed[g_arr[i]]));
    costmap[GRN][seed[g_arr[i]].first][seed[g_arr[i]].second] = 0;
  }
  for(int i = 0; i < R; i++){
    q.push(make_pair(RED, seed[r_arr[i]]));
    costmap[RED][seed[r_arr[i]].first][seed[r_arr[i]].second] = 0;
  }

  int flowers = 0;
  queue<pair< int, pii > > nq;
  int prev = 0;
  int cnum = 0;

  while(!q.empty()){
    int color = q.top().first;
    int y = q.top().second.first;
    int x = q.top().second.second;
    int cnum = costmap[color][y][x];
    
    q.pop();
    

    for(int i = 0 ; i < 4; i++){
      int uy = y + dy[i];
      int ux = x + dx[i];

      if(uy < 0 || ux < 0 || uy >= N || ux >= M)
        continue;

      if(map[uy][ux] == 0) // lake
        continue;
      
      if(costmap[color][uy][ux] != -1)
        continue;

      costmap[color][uy][ux] = costmap[color][y][x] + 1;
      nq.push(make_pair(color, make_pair(uy,ux)));
    }
    if(q.empty()){
      while(!nq.empty()){
        int color = nq.front().first;
        int uy = nq.front().second.first;
        int ux = nq.front().second.second;
        nq.pop();
      
        if(costmap[RED][uy][ux] == costmap[GRN][uy][ux])
          flowers++;

        if(costmap[(color+1)%2][uy][ux] == -1 ) 
          q.push(make_pair(color, make_pair(uy, ux)));
      }
    }
  }

  return flowers / 2;
}

int g_dfs(int g_indth, int num){
  //cout << ">g_dfs " << g_indth << " num : " << num << "\n";
  int maxf = 0;
  if(num == G){
    resetcostmap();
    int ret = bfs(gq, rq);
    //printrmap();
    //printgmap();
    return ret;
  }
  for(int i = g_indth; i < seed.size(); i++){
    if(used[i])
      continue;
    
    gq[num] = i;

    maxf = max(maxf, g_dfs(i + 1, num + 1));
  }
  return maxf;
}

int r_dfs(int g_indth, int num){
  int maxf = 0;
  if(num == R){
    return g_dfs(0,0);
  }
  for(int i = g_indth; i < seed.size(); i++){
    
    rq[num] = i;
  
    used[i] = 1;
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
