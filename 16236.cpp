//0924 -0947pm
#include <iostream>
#include <queue>
#include <string.h>

#define pii pair < int, int >
#define piii pair < pii, int >
#define IMP make_pair(-1, -1)
#define MX 10000

using namespace std;

int dy[4] = {-1, 0, 0, 1};
int dx[4] = {0, -1, 1 ,0};

int N;

priority_queue < pii > pq;

int map[25][25];
bool visited[25][25];

vector < pii > fishes[10]; // with size less than 10
pii shark;
int shark_size = 2;
int fishes_eaten = 0; // number of fishes eaten with size is current size
int tot_fishes_eaten = 0;  // number of fishes eaten
int num_fishes = 0; // number of total fishes

void printMap(){
  for(int i = 0 ; i < N ; i++){
    for(int j = 0 ; j < N ; j++){
      if(i == shark.first && j == shark.second)
        cout << 9 << " ";
      else
        cout << map[i][j] << " ";
    }
    cout << "\n";
  }
}
piii bfs_search(pii coord){
  int min_dist = MX;
  int min_x = -1;
  int min_y = -1;
  
  queue < piii > q;

  q.push(make_pair(coord, 0));

  while(!q.empty()){
    int y = q.front().first.first;
    int x = q.front().first.second;
    int d = q.front().second;
    q.pop();

    //cout <<" bfs : " <<  y << " " << x << " " << d << " " << min_dist << "\n";
    
    visited[y][x] = true;

    if(map[y][x] != 0 && map[y][x] < shark_size && min_dist >= d){
      if(min_dist == MX){
        min_dist = d;
        min_x = x;
        min_y = y;
      }else if(min_y > y){ 
        min_dist = d;
        min_x = x;
        min_y = y;
      }else if(min_y == y){
        if(min_x > x){
          min_dist = d;
          min_x = x;
          min_y = y;
        }
      }
    }


    for(int i = 0; i < 4; i++){
      int nexty = y + dy[i];
      int nextx = x + dx[i];

      if(nextx < 0 || nextx >= N || nexty < 0 || nexty >= N )
        continue;
      
      if(visited[nexty][nextx])
        continue;

      if(map[nexty][nextx] > shark_size)
        continue;
      

      q.push(make_pair(make_pair(nexty,nextx), d + 1));
      visited[nexty][nextx] = true;
    }
  }
  return make_pair(make_pair(min_y, min_x), min_dist);
}
int main(){
  cin >> N;

  for(int i = 0; i < N; i++){
    for(int j = 0; j < N; j++){
      cin >> map[i][j];
      if(map[i][j] == 0)
        continue;
      if(map[i][j] == 9){
        shark = make_pair(i, j);
        map[i][j] = 0;
      } else{
        //fishes[map[i][j]].push_back(make_pair(i, j));
        num_fishes++;
      }
    }
  }

  /*
  for(int i = 0 ; i < fishes[i].size(); i++){
    pq.push()
  }
  */

  int total_dist = 0 ;

  while(1){
    if(tot_fishes_eaten == num_fishes)
      break;

    memset(visited, 0, sizeof(visited));
    piii res = bfs_search(shark);
    
    int fish_x = res.first.second;
    int fish_y = res.first.first;
    
    //cout << "going for "<< map[fish_y][fish_x] << " (" << fish_y << ", " << fish_x << ") dist : " << res.second << "\n";

    if(res.first == IMP)
      break;

    total_dist += res.second;
    shark = make_pair(fish_y, fish_x);

    tot_fishes_eaten++;
    fishes_eaten++;
    if(fishes_eaten == shark_size){
      shark_size++;
      fishes_eaten = 0;
      //cout << "shark size : "<<shark_size << "\n";
    }
    map[fish_y][fish_x] = 0;
    
    //printMap();
  }
  cout << total_dist;

  return 0;
}
