#include <iostream>
#define INF 1e9
using namespace std;
int n, m;
// FLOYD
int mat[105][105];

void floyd(){
  for(int i = 1 ; i <= n ; i++){
    for(int j = 1 ; j <= n; j++){
      for(int k = 1 ; k <= n ; k++){
        if(mat[j][k] > mat[j][i] + mat[i][k])
          mat[j][k] = mat[j][i] + mat[i][k];
      }
    }
  }
}

void setMat(){
  for(int i = 1; i <= n ; i++){
    for(int j = 1 ; j <= n; j++){
      mat[i][j] = INF;
      if(i == j)
        mat[i][j] = 0;
    }
  }
}

void printMat(){
  for(int i = 1; i <= n ; i++){
    for(int j = 1 ; j <= n; j++){
      if(mat[i][j] == INF)
        cout << 0 << " ";
      else
        cout << mat[i][j] << " ";
    }
    cout << "\n";
  }
}
int main(){
  cin >> n >> m;
  
  setMat();

  for(int i = 0 ; i < m ;i++){
    int u, v, w;
    cin >> u >> v >> w;
    mat[u][v] = min(mat[u][v], w);
  }


  floyd();

  printMat();

  return 0;
}
