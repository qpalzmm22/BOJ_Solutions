#include <iostream>
#include <vector>
#define vvi vector<vector<int > >

using namespace std;

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, -1, 0, 1};

int cdy[4] = {-1, 0, 1, 0}; // clock wise
int cdx[4] = {0, 1, 0, -1};

int ccdy[4] = {1, 0, -1, 0}; // counter clock-wise
int ccdx[4] = {0, 1, 0, -1};


vvi map1;
vvi map2;

int ref1 = -1;
int ref2 = -1;

int R, C, T;

void printMap(vvi &map){
  for(int i=0; i<R; i++){
    for(int j=0; j<C; j++){
      cout << map[i][j] << " ";
    }
    cout << "\n";
  }
}

int countDust(vvi &map){
  int tot = 0;
  for(int i=0; i<R; i++){
    for(int j=0; j<C; j++){
      if(map[i][j] > 0){
        tot += map[i][j];
      }
    }
  }
  return tot;
}
void process(vvi &map, vvi &nextmap){
  //cout << "---\n";
  for(int i=0; i<R; i++){
    for(int j=0; j<C; j++){

      if(map[i][j] == -1){
        nextmap[i][j] = -1;
        continue;
      }
      
      nextmap[i][j] = 0;
      int ways = 0;
      for(int k = 0; k < 4; k++){
        int uy = i + dy[k];
        int ux = j + dx[k];

        if(uy < 0 || ux < 0 || ux >= C || uy >=R || map[uy][ux] == -1)
          continue;

        ways++;
        nextmap[i][j] += map[uy][ux]/5;
      }
      nextmap[i][j] += map[i][j] - map[i][j]/5 * ways;
    }
  }
  //cout << "<------->\n";
  //printMap(nextmap);
  
  // phase 2
  int cw = 0;
  int y = ref1 + cdy[cw];
  int x = 0 + cdx[cw];
  int nexty, nextx;
  int prev = 0;

  // upper refresh
  while(1){

    nexty = y + cdy[cw];
    nextx = x + cdx[cw];
    //cout << cw << " [" << y << " " << x << "]\n";

    if(nexty < 0 || nextx < 0 || nextx >= C || nexty > ref1){
      cw++;
      continue;
    }

    if(nextmap[nexty][nextx] == -1){
      nextmap[y][x] = 0;
      break;
    }

    nextmap[y][x] = nextmap[nexty][nextx];
    y = nexty;
    x = nextx;
  }

  cw = 0;
  y = ref2 + ccdy[cw];
  x = 0 + ccdx[cw];

  //cout << "<------->\n";
  while(1){
    //prev = nextmap[y][x];

    nexty = y + ccdy[cw];
    nextx = x + ccdx[cw];
    //cout << cw << " [" << y << " " << x << "]\n";

    if(nexty < ref2 || nextx < 0 || nextx >= C || nexty >= R){
      cw++;
      continue;
    }

    if(nextmap[nexty][nextx] == -1){
      nextmap[y][x] = 0;
      break;
    }

    nextmap[y][x] = nextmap[nexty][nextx];
    y = nexty;
    x = nextx;
  }

  int ccw = 0;

}

void processTime(){
  vvi temp;
  while(T--){
    process(map1, map2);
    temp = map1;
    map1 = map2;
    map2 = temp;
  }
  //printMap(map1);
  cout << countDust(map1);
}

int main(){
  cin >> R >> C >> T;

  for(int i=0; i<R; i++){
    vector<int> v;
    for(int j=0; j<C; j++){
      int elem;

      if(elem == -1 && ref1 == -1){
        ref1 = i;
      } else if(elem == -1){
        ref2 = i;
      }
      cin >> elem;
      v.push_back(elem);
    }
    map1.push_back(v);
    map2.push_back(v);
  }

  processTime();


  return 0;
}
