#include <iostream>
#include <string.h>

using namespace std;

int N, M;

int map[1005][1005];
int dp[1005][1005];
int dp2[1005][1005][2];

int findMax2(int i, int j, bool down){
  if(j >= M)
    return 0;
  
  if(dp2[i][j][down] != -1)
    return dp2[i][j][down];
  
  dp2[i][j][down] = map[i][j];
  int maxVal = 0;
  
  if(down == true){ // came from i - 1
    maxVal = max(maxVal, findMax2(i, j+1, false));
    if(i + 1 < N)
      maxVal = max(maxVal, findMax2(i+1, j+1, true));
  }else {
    maxVal = max(maxVal, findMax2(i, j+1, true));
    if(i - 1 >= 0)
      maxVal = max(maxVal, findMax2(i-1, j+1, false));
  }

  dp2[i][j][down] += maxVal;
  return dp2[i][j][down];
}

int findMax(int i, int j){
  if(j >= M)
    return 0;
  
  if(dp[i][j] != -1)
    return dp[i][j];

  dp[i][j] = map[i][j];
  int maxVal = 0;
  if(i - 1 >= 0) { // up
    maxVal = max(maxVal, findMax(i-1, j+1));
  }
  if(i + 1 < N){ // down
    maxVal = max(maxVal, findMax(i+1, j+1));
  }
  if(j+1 < M){
    maxVal = max(maxVal, map[i][j+1] + findMax(i, j+2));
  }

  dp[i][j] += maxVal;
  // right
  //
  return dp[i][j];
}

void printDP(){
  for(int i = 0 ; i < N; i++){
    for(int j = 0 ; j < M ; j++){
      cout << dp[i][j] << " ";
    }
    cout << "\n";
  }
}

void printDP2(){
  for(int i = 0 ; i < N; i++){
    for(int j = 0 ; j < M ; j++){
      for(int k = 0 ; k < 2 ; k++){
        cout << dp2[i][j][k] << ",";
      }
      cout << " ";
    }
    cout << "\n";
  }
}
int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);

  cin >> N >> M;

  memset(dp, -1, sizeof(dp));
  memset(dp2, -1, sizeof(dp2));

  for(int i = 0 ; i < N; i++){
    for(int j = 0 ; j < M ; j++){
      cin >> map[i][j];
    }
  }

  int ans = 0;
  for(int i = 0; i < N ; i++){
    ans = max(ans,findMax(i, 0));
  }

  for(int i = 0 ; i < N ; i++){
    ans = max(ans, findMax2(i, 0, true)); // if true it's increasing i
    ans = max(ans, findMax2(i, 0, false));
  }
  //printDP2();

  cout << ans ;

  return 0;
}
