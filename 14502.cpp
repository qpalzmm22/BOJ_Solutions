// use brute force... becuase N, M, is small enough, number of pillar is
// constant, and number of virus doesn't exceed 8. O(8 bfs* M N)
// Mayber look for ways to improve bfs??

#include <iostream>
#include <queue>

#define pii pair<int, int>

using namespace std;

int N, M;
int origmap[8][8];
int virCount = 0;
pii origvir[10];
int map[8][8];

vector<pii > room;
pii obst[3]; // possoble wall

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, -1, 0, 1};

int bfs(pii vir){
  int viruses = 0;
  queue<pii > q;
  q.push(vir);

  while(!q.empty()){
    int y = q.front().first;
    int x = q.front().second;
    q.pop();
    viruses++;

    for(int i = 0; i < 4; i++){
      int vy = y + dy[i];
      int vx = x + dx[i];
      
      if(vx < 0 || vy < 0 || vy >= N || vx >= M)
        continue;
      
      if( map[vy][vx] == 1 || map[vy][vx] == 2 )
        continue;


      map[vy][vx] = 2;
      q.push(make_pair(vy, vx));
    }
  }
  return viruses;
}

void initMap(){
  for(int i = 0; i < N; i++){
    for(int j = 0 ; j < M; j++){
      map[i][j] = origmap[i][j];
    }
  }
  for(int i = 0; i < 3; i++){
    map[obst[i].first][obst[i].second] = 1;
  }
}

void printMap(){
  for(int i = 0; i < N; i++){
    for(int j = 0 ; j < M; j++){
      cout << map[i][j] << " "; 
    }
    cout << "\n";
  }
}
int main(){
  cin >> N >> M;
  for(int i = 0; i < 8; i++){
    for(int j = 0; j < 8; j++){
      if(i < N && j < M){
        cin >> origmap[i][j];

        if(origmap[i][j] == 2){
          origvir[virCount] = make_pair(i, j);
          virCount++;
        }
        if(origmap[i][j] == 0){
          room.push_back(make_pair(i, j));
        }

      }else{
        origmap[i][j] = 1; // cover with walls if not part of map
      }
    }
  }
  
  
  int minVir = 65;
  for(int p1 = 0 ; p1 < room.size(); p1++){
    obst[0] = room[p1];
    for(int p2 = p1 + 1 ; p2 < room.size(); p2++){
      obst[1] = room[p2];
      for(int p3 = p2 + 1 ; p3 < room.size(); p3++){
        obst[2] = room[p3];

        int totVir = 0;
        initMap();

        for(int i = 0 ; i < virCount; i++){
          totVir += bfs(origvir[i]);
        }

        if(minVir > totVir){
          minVir = totVir;
          //printMap();
          //cout << "------ " << minVir << " ------\n";
        }
      }
    }
  }


  cout << room.size() - minVir - 3 + virCount;
  return 0;
}
