#include <iostream>
#include <vector>
#define pii pair < int, int >

using namespace std;

// solve by backtracking
int map[9][9];
int hor[9];
int ver[9];
int box[3][3];

vector < pii > blanks;

void printMap(){
  for(int i = 0; i < 9; i++){
    for(int j = 0; j < 9; j++){
      cout << map[i][j] << " ";
    }
    cout << "\n";
  }
}

bool solve(int blank_idx){
  //cout << " -- " << blanks << "\n";
  //printMap();
  
  int i = blanks[blank_idx].first;
  int j = blanks[blank_idx].second;

  if(blanks.size() == blank_idx){
    printMap();
    return true;
  }
  for(int k = 0 ; k < 9 ; k++){
    if(hor[i] & (1 << k) || ver[j] & (1 << k) || box[i/3][j/3] & (1 << k))
      continue;

    hor[i] |= (1 << k);
    ver[j] |= (1 << k);
    box[i/3][j/3] |= (1 << k);
    map[i][j] = k+1;

    if(solve(blank_idx + 1))
      return true;

    hor[i] &= ~(1 << k);
    ver[j] &= ~(1 << k);
    box[i/3][j/3] &= ~(1 << k);
    map[i][j] = 0;
  }
  return false;
}

int main(){

  for(int i = 0 ; i < 9; i++){
    for(int j = 0 ; j < 9; j++){

      cin >> map[i][j];
      //cout << i << " "  << j << " "  << map[i][j]<< "\n";
      //printMap();

      if(map[i][j] != 0){
        hor[i] |= (1 << (map[i][j] - 1));
        ver[j] |= (1 << (map[i][j] - 1));
        box[i/3][j/3] |= (1 << (map[i][j] - 1));
      }else{
        blanks.push_back(make_pair(i, j));
      }
    }
  }
  solve(0);

  return 0;
}
