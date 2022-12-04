#include <iostream>
#include <vector>
#define ll long long 
#define REM 1000000007

using namespace std;

int mat[8][8] = {{0, 1, 1, 0, 0, 0, 0, 0},
      {1, 0, 1, 1, 0, 0, 0, 0},
      {1, 1, 0, 1, 1, 0, 0, 0},
      {0, 1, 1, 0, 1, 1, 0, 0},
      {0, 0, 1, 1, 0, 1, 1, 0},
      {0, 0, 0, 1, 1, 0, 0, 1},
      {0, 0, 0, 0, 1, 0, 0, 1},
      {0, 0, 0, 0, 0, 1, 1, 0}};

vector < vector < ll > > v_mat; 
vector < vector < ll > > res;

long long D;

vector < vector < vector < ll > > >  dp;
int dp_exist[55];


void printMat(vector < vector < ll > > mat){
  for(int i = 0 ; i < 8 ; i++){
    for(int j = 0 ; j < 8 ; j++){
      cout << mat[i][j] << " ";
    }
    cout << "\n";
  }
}
vector< vector < ll > > mat_mult( vector < vector < ll > > matA, vector < vector < ll > > matB){
  vector < vector < ll > > res;
  res.assign(8, vector < ll > (8, 0));

  for(int i = 0; i < 8; i++){
    for(int j = 0 ; j < 8 ; j++){
      for(int u = 0 ; u < 8 ; u++){
        res[i][j] = (res[i][j] + (matA[i][u] * matB[u][j]) % REM ) % REM;
      }
    }
  }
  return res;
}

vector < vector < ll > > calc_mult(vector < vector < ll > > matA, int idx){
  

  if(dp_exist[idx]){
    return dp[idx];
  }

  vector < vector < ll > > tmp = calc_mult(matA, idx-1);
  return dp[idx] = mat_mult(tmp, tmp); 
}


int main(){
  cin >> D;

  res.assign(8, vector < ll > (8, 0));
  
  for(int i = 0 ; i <= 50; i++){
    vector < vector < ll > > tmp;
    tmp.assign(8, vector < ll > (8, 0));
    dp.push_back(tmp);
  }

  for(int i = 0 ; i < 8 ; i++){
    vector < ll > tmp;
    for(int j = 0 ; j < 8 ; j++){
      tmp.push_back(mat[i][j]);
      if(i == j)
        res[i][j] = 1;
    }
    v_mat.push_back(tmp);
  }
  //cout << " < \n";
  //printMat(v_mat);

  dp[0] = v_mat;

  dp_exist[0] = true;

  int i = 0;
  int remainder = D;
  while(D >> i){
    if((D >> i) & 1)
      res = mat_mult(res, calc_mult(v_mat, i));
    i++;
  }
  cout << res[0][0];

  return 0;
}
