// solve with DFS and bihmasking and memoization
#include <iostream>
#define REM 1000000000

using namespace std;
int N;

long long memoi[105][10][1024];

long long dfs(int n, int lastnum, int check){
  

  long long ans = 0;

  if(n == N){
    if(check == 1023) {
      //cout << "num : "<< lastnum << "\n";
      return 1;
    }
    else
      return 0;
  }
  if(memoi[n][lastnum][check] != -1){
   // cout << "memoi : "<< n << " " << lastnum << " " << check << " " << memoi[n][lastnum][check]<< "\n";
    return memoi[n][lastnum][check];
  }

  if(lastnum + 1 < 10 )
    ans += dfs(n+1, lastnum + 1, check | (1 << (lastnum + 1))) % REM;
  if(lastnum - 1 >= 0 )
    ans += dfs(n+1, lastnum - 1, check | (1 << (lastnum - 1))) % REM;

  memoi[n][lastnum][check] = ans % REM;
  return ans ;
}

int main(){
  cin >> N;
  
  long long  ans = 0;

  for(int i = 0 ; i <= N; i++){
    for(int j = 0 ; j < 10; j++){
      for(int k = 0 ; k < 1024; k++){
        memoi[i][j][k] = -1;
      }
    }
  }
  //for(int k = 1 ; k <= 40; k++){
    //N = k;
    for(int i = 1; i <= 9; i++){
      ans += dfs(1, i, 1 << i) % REM;
    }
  //}
  cout << ans % REM;

  return 0;
}
