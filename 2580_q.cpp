#include <iostream>
#include <queue>
#define pii pair < int, int >

using namespace std;

deque < pii > dq;
int map[9][9];
// SUDOKU

int possmap[9][9];

// 123456789
// 111111110
// 111111101
// 111111011
// 111110111
// 111101111
// 111011111
// 110111111
// 101111111
// 011111111
int found[9];

//012
//345
//678
void drawPossmap(int y, int x){
  

 // horizontal
  for(int i = 0 ; i < 9; i++){
    if(map[y][i] != 0)
      possmap[y][x] |= 1 << (map[y][i] - 1);
  }
  
  //vertical
  for(int i = 0 ; i < 9; i++){
    if(map[i][x] != 0)
      possmap[y][x] |= 1 << (map[i][x] - 1);
  }

  
  int nth = 3 * (y / 3) + x / 3;

  int i_box = nth / 3;
  int j_box = nth % 3;

  for(int i = 0; i < 3; i++){
    for(int j = 0; j < 3; j++){
      int boxy = 3 * i_box + i;
      int boxx = 3 * j_box + j;

      //cout << y << " "<< x << "\n";
      if(map[boxy][boxx] != 0)
        possmap[y][x] |= 1 << (map[boxy][boxx] - 1);
    }
  }

  //q.push(make_pair(y, x));
}

void printMap(){
  for(int i = 0; i < 9; i++){
    for(int j = 0; j < 9; j++){
      cout << map[i][j] << " ";
    }
    cout << "\n";
  }
}

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  for(int i = 0; i < 9; i++){
    for(int j = 0; j < 9; j++){
      cin >> map[i][j];
      if(map[i][j] == 0)
        dq.push_back(make_pair(i, j));
      else{
        for(int k = 0 ; i < 9 ; i++){
          possmap[i][k] |= (1 << (map[i][j] - 1))
          possmap[k][j] |= (1 << (map[i][j] - 1))
          possmap[i/3 + (k/3)][j/3 + (k%2)] |= ( 1 << (map[i][j] - 1));
        }
      }
    }
  }

  
 for(int i = 0; i < 9; i++){
    found[i] = ((1 << 9) - 1) & (~(1 << i)) ;
    //cout << found[i] << " ";
 }

  while(!q.empty()){
    int y = dq.front().first;
    int x = dq.front().second;
    dq.pop_front();
    if(map[y][x] != 0)
      continue;

    int ans = false;
    for(int i = 0; i < 9; i++){
      if(possmap[y][x] == found[i]){
        map[y][x] = i + 1;
        printMap();
        for(int k = 0 ; i < 9 ; i++){
          possmap[y][k] |= (1 << i);
          possmap[k][x] |= (1 << i);
          possmap[y/3 + (k/3)][x/3 + (k%3)] |= (1 << i);
          
          if(map[y][k] == 0)
            dq.push_front(make_pair(y,k));
          if(map[k][x] == 0)
            dq.push_front(make_pair(k,x));
          if(map[y/3+k/3][x/3+k%3] == 0)
            dq.push_front(make_pair(y/3+k/3,x/3+k%3));
        }
        ans = true;
        break;
      }
    }
    if(!ans)
      q.push_back(make_pair(y,x));
  }
  printMap();

  return 0;
}
