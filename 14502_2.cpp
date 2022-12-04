#include <iostream>
#include <vector>
#include <queue>

#define pii pair < int, int >
#define EMPTY 0
#define WALL 1
#define VIRUS 2 // viroused

int dx[4] = {-1, 0 , 1, 0};
int dy[4] = {0, -1 , 0, 1};

using namespace std;

int N, M;
int origMap [9][9];
int map [9][9];

int safeCount = 0;

vector < pii > blank;
vector < pii > virus;

void printMap(){
  
  cout <<  "---------------\n";
  for(int i = 0 ; i < N ; i++){
    for(int j = 0 ; j < M ;j ++){
      cout <<  map[i][j] << " ";
    }
    cout << "\n";
  }
}
int activate_virus(){
  int safe = safeCount;
  queue <pii> q;
  
  for(int i = 0 ; i < virus.size(); i++){
    q.push(virus[i]);
  }

  while(!q.empty()){
    int x = q.front().second;
    int y = q.front().first;
    q.pop();

    for(int i = 0 ; i < 4; i++){
      int nextx = dx[i] + x; 
      int nexty = dy[i] + y;

      if(nextx < 0 || nexty < 0 || nexty >= N || nextx >= M)
        continue;

      if(map[nexty][nextx] == WALL || map[nexty][nextx] == VIRUS)
        continue;

      q.push(make_pair(nexty, nextx));
      map[nexty][nextx] = VIRUS;
      safe--;
    }
  }
  return safe;
}

void reDraw(){
  for(int i = 0; i < N; i++){
    for(int j = 0; j < M; j++){
      map[i][j] = origMap[i][j];
    }
  }
}
int main()
{
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  cin >> N >> M; 

  for(int i = 0 ; i < N ; i++){
    for(int j = 0 ; j < M ;j ++){
      cin >> origMap[i][j];
      if(origMap[i][j] == EMPTY)
        blank.push_back(make_pair(i, j));
      
      if(origMap[i][j] == VIRUS)
        virus.push_back(make_pair(i, j));
    }
  }

  safeCount = blank.size() - 3;
  //cout << safeCount << "\n";
  
  // (8^2^3)  = 10000)
  int safe = 0;

  for(int i = 0; i < blank.size()-2; i++){
    for(int j = i + 1; j < blank.size()-1; j++){
      for(int k = j + 1 ; k < blank.size()-0; k++){
        reDraw();
        pii wall1 = blank[i];
        pii wall2 = blank[j];
        pii wall3 = blank[k];
        map[wall1.first][wall1.second] = WALL;
        map[wall2.first][wall2.second] = WALL;
        map[wall3.first][wall3.second] = WALL;
        safe = max(safe, activate_virus());
        //printMap();
        //map[wall1.first][wall1.second] = EMPTY;
        //map[wall2.first][wall2.second] = EMPTY;
        //map[wall3.first][wall3.second] = EMPTY;
      }
    }
  }

  cout << safe ;


  return 0;
}
