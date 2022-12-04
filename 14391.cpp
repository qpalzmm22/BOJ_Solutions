#include <iostream>
#include <string.h>

using namespace std;


// Firstt hought use dp

int N, M;
int NMmask;
int dp[1<<18];
int map[20][20];

int helper(int y, int x, int k, bool hor){
  int tot = 0;

  if(hor){
    for(int i = 0 ; i <= k; i++){
      tot = tot * 10 + map[y][i+x];
    }
  }else{
    for(int i = 0 ; i <= k; i++){
      tot = tot * 10 + map[i+y][x];
    }
  }
  return tot;
}

int solve(int mask){
  if(dp[mask] != -1)
    return dp[mask];

  if(mask == (1 << (N*M + 1)) - 1)
    return 0;


  int max_total = 0;
  int val;
  for(int i = 0; i < N; i++){
    for(int j = 0 ; j < M ; j++){
      if(mask & (1 << (i*M+j))) continue; // visited

      int visited = (1 << (i*M+j));
      max_total = max(max_total, solve(mask | visited) + map[i][j]);
      
      // horizontal
      int tmp = 1;
      for(int k = 1 ; k < 4; k++){
        tmp = (tmp << 1) + 1;
        if( j + k >= M)
          break;

        visited = (tmp << (i*M+j));
        if((mask & visited) > 0)
          break;
        val = helper(i, j, k, true);
        max_total = max(max_total, solve(mask | (visited & NMmask)) + val);
      }
      // vertical
      tmp = 1;
      for(int k = 1 ; k < 4; k++){
        tmp = (tmp << M) + 1;
        if( i + k >= N)
          break;
        visited = (tmp << (i*M+j));
        
        if((mask & visited) > 0)
          break;
        val = helper(i, j, k, false);
        max_total = max(max_total, solve(mask | (visited & NMmask)) + val);
      }
    }
  }
  //cout << "mask " << mask << " " << max_total << "\n";
  return dp[mask] = max_total;
}

int main(){
  cin >> N >> M;
  NMmask = (1 <<(N*M+1)) -1;
  
  memset(dp, -1, sizeof(dp));

  for(int i = 0 ; i < N ; i++){
    string str;
    cin >> str;
    for(int j = 0; j < M; j++){
      map[i][j] = str[j] - '0';
    }
  }

  cout << solve(0);

  return 0 ;
}
