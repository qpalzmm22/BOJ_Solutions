#include <iostream>

#define FILLED 0b111111111 // 0 means possible

using namespace std;


int map[9][3][3];

int pass[9][9];
int passVer[9];
int passHor[9];
int passBox[9];

void printMap(){
  for(int i = 0; i < 9; i++){
    for(int j = 0; j < 9; j++){
      cout << map[(i/3)*3 + j/3][i%3][j%3] << " ";
    }
    cout << "\n";
  }
}

void printPass(){
  for(int i = 0; i < 9; i++){
    for(int j = 0; j < 9; j++){
      cout << pass[i][j] << " ";
    }
    cout << "\n";
  }
}

void elimHor(int i, int num){
  passHor[i] |= 1 << (num - 1);
  for(int j = 0; j < 9; j++){
    pass[i][j] |= 1 << (num - 1);
  }
}

void elimVer(int j, int num){
  passVer[j] |= 1 << (num - 1);
  for(int i = 0; i < 9; i++){
    pass[i][j] |= 1 << (num - 1);
  }
}

void elimBox(int n, int num){
  passBox[n] |= 1 << (num - 1);
  for(int i = 0; i < 3; i++){
    for(int j = 0 ; j < 3 ;j++){
      pass[(n/3)*3+i][(n%3*3)+j] |= 1 << (num - 1);
    }
  }
}

int isTrackable(int n){
  int count = 0;
  int num = 9;
  while(n){
    count += n & 1;
    if((n & 1) == 0){
      num = count + 1;
    }
    n >>= 1;
  }

  if(count == 8){
    return num;
  } else{
    return 0;
  }
}

int main(){
  string str;
  for(int i = 0; i < 9; i++){
    cin >> str;
    for(int j = 0 ; j < 9; j++){
      int y = i/3;
      int x = j/3;
      map[y*3 + x][i%3][j%3] = str[j] - '0';
      int num = map[y*3 + x][i%3][j%3];

      if(num != 0){
        elimHor(i, num);
        elimVer(j, num);
        elimBox(y*3 + x, num);
        pass[i][j] = FILLED;
      }
    }
  }
  printMap();
  printPass();
  
  while(1){
    for(int i = 0; i < 9; i++){
      for(int j = 0; j < 9; j++){
        int num = 0;
        if(pass[i][j] != FILLED && (num = isTrackable(pass[i][j]))){
          cout << "> " << num << " "<< pass[i][j] << "\n";
          int y = i/3;
          int x = j/3;

          elimHor(i, num);
          elimVer(j, num);
          elimBox(y*3 + x, num);
          pass[i][j] = FILLED;
          map[y*3 + x][i%3][j%3] = num;
          printMap();
          printPass();
          cout << "\n";
        }
      }
    }
    //printMap();
    //cout << "\n";
  }

  return 0;
}
