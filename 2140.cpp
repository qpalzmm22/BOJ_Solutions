#include <iostream>
#define NOMINE '$'
#define MINE '*'
using namespace std;

int dy[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dx[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

int N;

int map[105][105];
// ad hoc?
// 1. for loop ^ 2 , if # tiles around number equals to the number
// make that tile * and decreause number around that tile
//  or else make that tile 0

int cnt = 0;
void decrease_num(int i, int j){
  for(int k = 0 ; k < 8; k++){

    if(i + dy[k] < 0 || i + dy[k] >= N || j + dx[k] < 0 || j + dx[k] >= N)
      continue;
    // 1 ~ 3  is max
    if(map[i + dy[k]][j + dx[k]] > '0' && map[i + dy[k]][j + dx[k]] < '4' ){
      map[i + dy[k]][j + dx[k]]--;
    }
  }
}

void printmap(){
  for(int i = 0; i < N; i++){
    for(int j = 0 ; j < N; j++){
      cout << (char) map[i][j] << " ";
    }
    cout << "\n";
  }
}
int main(){

  cin >> N;

  if( N < 3 ){
    cout << "0";
    return 0 ;
  }
  for(int i = 0 ; i < N; i++){
    string str;
    cin >> str;
    for(int j = 0 ; j < N ; j++){
      map[i][j] = str[j] ;
    }
  }

  for(int j = 0 ; j < N - 2 ; j++){

  // top -> right bottom
    if(map[1][j+1] != '#')
      continue;

    if(map[0][j] == '0'){
      map[1][j + 1] = NOMINE;
    } else{
      cnt++;
      map[1][j + 1] = MINE;
      decrease_num(1, j+1);
    }
  // bottom
    if(map[N-2][j+1] != '#')
      continue;

    if(map[N-1][j] == '0'){
      map[N-2][j + 1] = NOMINE;
    } else{
      cnt++;
      map[N-2][j + 1] = MINE;
      decrease_num(N-2, j+1);
    }
  }

  for(int i = 0 ; i < N - 2 ; i++){

  // left -> right bottom
    if(map[i+1][1] != '#')
      continue;

    if(map[i][0] == '0'){
      map[i + 1][1] = NOMINE;
    } else{
      cnt++;
      map[i + 1][1] = MINE;
      decrease_num(i + 1, 1);
    }

    // right -> left bottom
    if(map[i+1][N-2] != '#')
      continue;

    if(map[i][N-1] == '0'){
      map[i + 1][N-2] = NOMINE;
    } else{
      cnt++;
      map[i + 1][N-2] = MINE;
      decrease_num(i+1, N-2);
    }
  }
  //printmap();

  if(N - 4 >= 1)
    cnt+= (N-4) * (N-4);
  cout << cnt << "\n";

  return 0;
}
