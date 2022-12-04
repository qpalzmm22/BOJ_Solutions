#include <iostream>

using namespace std;

int N;

int mat[25][25];
int considered[25][25];
// Since N is small, iterate N and do dijkstra (ElgV) => V^3logV  
// if and edge is used don't count it later and don't add it.
int main(){
  cin >> N;

  long long tot = 0;
  for(int i = 1; i <= N; i++){
    for(int j = 1 ; j <= N ; j++){
      cin >> mat[i][j];
      if(i < j)
        tot+= mat[i][j];
    }
  }

  for(int i = 1 ; i <= N; i++){
    for(int j = 1; j <= N; j++){
      if(i == j)
        continue;
      for(int k = 1 ; k <= N; k++){
        if(i == k || j == k)
          continue;
        if(considered[i][j])
          continue;

        if(mat[i][j] == mat[i][k] + mat[k][j]){
          //cout << "get rid of " << mat[i][j] << "\n";
          tot-= mat[i][j];
          considered[i][j] = true;
          considered[j][i] = true;
        }else if(mat[i][j] > mat[i][k] + mat[k][j] ){
          cout << "-1";
          return 0;
        }
      }
    }
  }
  cout << tot;
  return 0;
}
