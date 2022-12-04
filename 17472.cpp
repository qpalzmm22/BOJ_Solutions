#include <iostream>
#include <queue>
#define MX 100

#define pii pair < int, int > 

int dy[4] ={-1, 0 ,1 , 0};
int dx[4] ={0, -1 ,0 , 1};

using namespace std;

int N, M;
deque < pii > dq;

int map[15][15];
int groups[20][20];

vector < pii > adj [20];
bool visited[20];

int group = 0;
// next y, x
void travel(int dir, int origGroup, int dist, int y, int x){

  // encounter wall
  if(y < 0 || y >= N || x < 0 || x >= M)
    return ;

  if(groups[y][x] != 0 && groups[y][x] != origGroup)
    if(dist >= 2){
      //cout << "newlandfound : " << dir << " " << origGroup << " "<< dist << " " << y  << " "<< x  << "\n"; 
      adj[origGroup].push_back(make_pair(dist ,groups[y][x]));
      adj[groups[y][x]].push_back(make_pair(dist ,origGroup));
    }

  int nexty = y + dy[dir];
  int nextx = x + dx[dir];
  if(!groups[y][x])
    travel(dir, origGroup, dist+1, nexty, nextx);
}

void printgroupsMap(){
  cout << "------groups------\n";
  for(int i = 0; i < N; i++){
    for(int j = 0; j < M ; j++){
      cout << groups[i][j] << " ";
    }
    cout << "\n";
  }
}

// i to j iterate groups => land first == same
// while dx, dy if new 
// solve MST after then
int main(){

  cin >> N >> M;

  for(int i = 0; i < N; i++){
    for(int j = 0; j < M; j++){
      cin >> map[i][j];
      if(map[i][j])
        dq.push_back(make_pair(i, j));
    }
  }

  while(!dq.empty()){
    int y = dq.front().first;
    int x = dq.front().second;
    dq.pop_front();
    
    if(groups[y][x])
      continue;

    bool newgroup = true;
    for(int i = 0 ; i < 4; i++){
      int nextx = x + dx[i];
      int nexty = y + dy[i];

      if(nextx < 0 || nexty < 0 || nextx >= M || nexty >= N)
        continue;
    
      if(groups[nexty][nextx]){
        newgroup = false;
      }

      if(map[nexty][nextx]){
        dq.push_front(make_pair(nexty,nextx));
      }
    }
    // This works becuz new groups are always surrounded by 0s in the beginning
    // and filling up the groups in bfs manner
    if(newgroup)
      group++;
    
    groups[y][x] = group;

    //printgroupsMap();
  }
  ////cout << "groups : "<<group << "\n";


  for(int i = 0 ; i < N; i++){
    for(int j = 0 ; j < M; j++){
      if(!map[i][j])
        continue;

      for(int k = 0 ; k < 4; k++){
        int nexty = i + dy[k];
        int nextx = j + dx[k];

        if(nextx < 0 || nexty < 0 || nextx >= M || nexty >= N)
          continue;

        // 0 : no way to new land
        travel(k, groups[i][j], 0, nexty, nextx);
        //printDistsMat();
      }
    }
  }

  // Prims algo
  int sum = 0;

  priority_queue < pii, vector< pii >, greater < pii > > pq;
  pq.push(make_pair(0,1)); // cost, node

  while(!pq.empty()){
    int cost = pq.top().first;
    int node = pq.top().second;
    pq.pop();

    if(visited[node])
      continue;

    //cout << "pq : " << node << " " << cost  << "\n";
    visited[node] = true;
    sum += cost;

    for(int i = 0; i < adj[node].size(); i++){
      pq.push(adj[node][i]);
    }
  }

  for(int i = 1; i <= group; i++){
    if(!visited[i]){
      cout << -1;
      return 0;
    }
  }
  cout << sum ;

  return 0;
}
