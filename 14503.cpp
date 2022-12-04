#include <iostream>

int dy[4]={-1,0,1,0};
int dx[4]={0,1,0,-1};

using namespace std;

int N, M;
int x, y;
int d;
int map[55][55];

void printMap(){
  for(int i = 0 ; i < N ; i++){
    for(int j = 0 ; j < M; j++){
      if(x == j && y == i )
        cout << d + 4 << " ";
      else
        cout << map[i][j] << " ";
    }
    cout <<"\n";
  }
}

int main(){
  cin >> N >> M;
  cin >> y >> x >> d;

  for(int i = 0 ; i < N; i++){
    for(int j = 0 ; j < M; j++){
      int wall;
      cin >> wall;
      map[i][j] = wall;
    }
  }

  int cleaned = 0;
  while(1){
    // clean
    if(map[y][x] == 0)
      cleaned++;
    map[y][x] = 2;
    
    //printMap();

    //move
    bool ready2clean = false;
    for(int i = 0; i < 4; i++){
      int nextd = ((d + 4) - (i+1)) % 4;
      int nextx = x + dx[nextd];
      int nexty = y + dy[nextd];
      
      
      if(!map[nexty][nextx] ){ // not wall or cleaned
        y = nexty;
        x = nextx;
        d = nextd;
        // start from clean
        ready2clean = true;
        break;
      }
    }
    if(!ready2clean){
      int nextd = (d + 2) % 4;
      int nextx = x + dx[nextd];
      int nexty = y + dy[nextd];

      if(map[nexty][nextx] == 1){ //wall
        break; //halt the machine
      } else{
        x = nextx;
        y = nexty;
      }
    }
  }

  cout << cleaned;

  return 0;
}
