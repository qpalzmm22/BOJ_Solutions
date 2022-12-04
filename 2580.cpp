#include <iostream>
#include <queue>
#define pii pair < int, int >

using namespace std;

queue < pii > q;
int map[9][9];
// SUDOKU

int hor[9];
int ver[9];
//012
//345
//678
int box[3][3];

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
      if(map[i][j] == 0){
        q.push(make_pair(i, j));
      }else{
        hor[i] |= (1 << (map[i][j] - 1));
        ver[j] |= (1 << (map[i][j] - 1));
        box[i/3][j/3] |= (1 << (map[i][j] - 1));
      }
    }
  }

  
 for(int i = 0; i < 9; i++){
    found[i] = ((1 << 9) - 1) & (~(1 << i)) ;
    //cout << found[i] << " ";
 }

  while(!q.empty()){

    int y = q.front().first;
    int x = q.front().second;

    //cout << y << " " << x << "\n";
    q.pop();
    
    bool ans = false;
    for(int i = 0 ; i < 9 ; i++){
      if(hor[y] == found[i] || ver[x] == found[i] || box[y/3][x/3] == found[i]){
        //cout << found[i] << " " << x << " " << y << "\n";
        map[y][x] = i+1;
        hor[y] |= (1 << i);
        ver[x] |= (1 << i);
        box[y/3][x/3] |= (1 << i);
        ans = true;
        break;
      }
    }
    //printMap();
    if(!ans)
      q.push(make_pair(y, x));
    //drawPossmap(y,x);
  }
  printMap();

  return 0;
}
