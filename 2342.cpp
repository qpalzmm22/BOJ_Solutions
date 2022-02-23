// Solve it with greedy..? 

#include <iostream>

using namespace std;

int path[100005];
int dp[5][5][100005];
int N = 0;

int movecost(int from, int to){
  if(from == 0){
    return 2;
  } else if(from + 2 == to || to + 2 == from){
    return 4;
  } else if(from == to){
    return 1;
  } else{
    return 3;
  }
}

int dfs(int l, int r, int i){
  //cout << l << " " << r << " " << i <<  "\n";
  if(i == N){
    return 0;
  }

  if(dp[l][r][i])
    return dp[l][r][i];

  int lcost = dfs(path[i], r, i + 1) + movecost(l, path[i]);
  int rcost = dfs(l, path[i], i + 1) + movecost(r, path[i]);

  if(lcost < rcost)
    dp[l][r][i] = lcost;
  else
    dp[l][r][i] = rcost;

  return dp[l][r][i];
}

int main(){
  int l = 0;
  int r = 0;
  int totcost = 0;
  while(1){
    int num;
    cin >> num;
    if(num == 0){
      break;
    }

    path[N++] = num;
  }
  totcost = dfs(0, 0, 0);
  cout << totcost;
  return 0;
}
