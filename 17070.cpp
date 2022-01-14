#include <iostream>

using namespace std;

// state 
// 0 -> horizontal
// 1 -> diagonal
// 2 -> vertical

int N;
int map[20][20];
int dp[20][20][3];

void printDP(){
  for(int i = 0; i < N; i++){
    for(int j = 0; j < N; j++){
      cout << "[";
      for(int k = 0; k < 3; k++){
        cout << dp[i][j][k] << ", ";
      }
      cout << "] ";
    }
    cout << "\n";
  }
}

int solve(int y, int x, int state){
  if(y == N || x == N)
    return 0;

  if(y == N - 1 && x == N - 1)
    return 1;

  if(dp[y][x][state] != -1){
    return dp[y][x][state];
  }
  
  int solutions = 0;

  if(state != 2 && map[y][x+1] != 1){
    solutions += solve(y, x+1, 0);
  }

  if(state != 0 && map[y+1][x] != 1){
    solutions += solve(y+1, x, 2);
  }

  if(map[y][x+1] + map[y+1][x] + map[y+1][x+1] < 1)
    solutions += solve(y+1, x+1, 1);
  
  dp[y][x][state] = solutions;
  
  return dp[y][x][state];
}


int main(){
  cin >> N;
  
  for(int i = 0; i < N; i++){
    for(int j = 0; j < N; j++){
      cin >> map[i][j];
      for(int k = 0; k < 3; k++){
        dp[i][j][k] = -1;
      }
    }
  }

  

  cout << solve(0, 1, 0);
  //printDP();
  return 0;
}
