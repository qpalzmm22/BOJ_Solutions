#include <iostream>

using namespace std;

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

char map[25][25];
//int dp[25][25];

int R, C;

int passed[256];
//map<char, int> passed;

int dfs(int y, int x, int alphas){
  //if(dp[y][x] != -1)
  //  return dp[y][x];
  int num = alphas;

  //cout << "["<< y << "," << x << "]" << " " << map[y][x] << " " << alphas << "\n";

  for(int i = 0; i < 4; i++){
    int ux = x + dx[i];
    int uy = y + dy[i];

    //out << "==["<< uy << "," << ux << "]" << " " << map[uy][ux] << " " << alphas << "\n";
    
    if(ux < 0 || uy < 0 || ux >= C || uy >= R)
      continue;
    
    if(passed[map[uy][ux]])
      continue;
    
    passed[map[uy][ux]] = 1;
    num = max(dfs(uy, ux, alphas + 1) , num);
    passed[map[uy][ux]] = 0;

  }
  return num;
}

int main(){
  cin >> R >> C;
  
  string s;
  for(int i = 0 ; i < R; i++){
    cin >> s;
    
    for(int j = 0; j < C; j++){
      map[i][j] = s[j];
    }
  }

  passed[map[0][0]] = 1;
  cout << dfs(0,0,1);


  return 0;
}
