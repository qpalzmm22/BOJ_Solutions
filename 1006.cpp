#include <iostream>

using namespace std;

int T;

int cirtagon [2][10005]; // 0 => inner, 1 => outer

int main(){
  cin >> T;
  while(T--){
    int N, W;
    cin >> N >> W;
    for(int i = 1; i <= N; i++){
      cin >> cirtagon[0][i];
      if(i == 1)
        cirtagon[0][N + 1] = cirtagon[0][i];``
    }
    for(int i = 1; i <= N; i++){
      cin >> cirtagon[1][i];
      if(i == 1)
        cirtagon[1][N + 1] = cirtagon[1][i];``
    }
    cirtagon[i]
    // 6*N
    for(int i = 0; i < 2; i++){
      for(int j = 1 ; j <= N; j++){
        int cur = cirtagon[i][j];
        int left = cirtagon[i][j-1];
        int right = cirtagon[i][j+1];
        if(cirtagon[i][j] + cirtagon[i-1][j] <= W)
      }
    }
  }

  return 0;
}
