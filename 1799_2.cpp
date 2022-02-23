// Similart o N - QUEENS. DFS with not processing all the squares (backtracking)

#include <iostream>
#include <cmath>

#define pii pair<int, int>

using namespace std;

int N;

int map[25][25];
int newmap[25][25];
int dp[12][12][30]; // 2 * N

int bn = 0;

pii bishops[30];

bool isdiagonal(pii a, pii b){
  int y1 = a.first;
  int x1 = a.second;
  int y2 = b.first;
  int x2 = b.second;
  if(abs(x1 - x2) == abs(y1 - y2))
    return true;
  else
    return false;
}

int dfs(int rank, int check){

  //cout << rank << " " << bn << "\n";
  int maxBs = bn;
  if(rank == 2 * N)
    return bn;
  int x = rank;
  int y = 0;

  // no inclusion in this row
  maxBs = max(maxBs, dfs(rank + 1));
  
  for(int i = 0 ; i <= rank ; i++){
    bool flag = false;
    
    if(newmap[y][x] == 0){
      x--;
      y++;
      continue;
    }
    int dy = y+1;
    int dx = x+1;
    while(dy < N && dx < N){
      newmap[dy][dx] = 0;
      dy++;
      dx++;
    }
    bn++;
    maxBs = max(maxBs, dfs(rank + 1));
    bn--;

    dy = y+1;
    dx = x+1;
    while(dy < N && dx < N){
      newmap[dy][dx] = map[dy][dx];
      dy++;
      dx++;
    }

    x--;
    y++;
  }
  return maxBs;
}

int main(){
  cin >> N;
  for(int i = 0 ; i < N ; i++){
    for(int j = 0; j < N ; j++){
      cin >> map[i][j];
      newmap[i][j] = map[i][j];
    }
  }
  cout << dfs(0, (1 << 2 *N) - 1);
  return 0;
}
