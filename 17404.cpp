#include <iostream>
#include <tuple>
#include <vector>

#define MAX 10000000
using namespace std;

int N;

vector < int > rgbValue[3];

int dp[3][3][1002]; // first_color, cur_color; rgb order

int dfs(int first_color, int cur_color,  int i){

  if(i == N)
    return 0;
    
  if(dp[first_color][cur_color][i]){
    return dp[first_color][cur_color][i];
  }
  

  int min_value = MAX;
  for(int j = 0; j < 3; j++){ // next color
    if(cur_color == j)
      continue;
    if(i == N-2 && first_color == j)
      continue;

    //cout << "------------ i j ------ : " << i << " "<< j << "\n";
    min_value = min(min_value, rgbValue[cur_color][i] + dfs(first_color, j, i + 1));
    //cout << "------------ i j ------ : " << i << " "<< j << "\n";
   // min_value = min(min_value, rgbValue[j][i] + dfs(first_color, j, i + 1));
    //cout << "min(" << i << ")  [" << j <<  "] : " << min_value << "\n";
  }
  dp[first_color][cur_color][i] = min_value;
  //cout << "first_color : " << first_color <<  " i : " << i << " prev : " << cur_color << " >> " << dp[first_color][cur_color][i]<< "\n";
  return dp[first_color][cur_color][i];
}

void print_dp(int first_color){
  for(int j = 0; j < N; j++){
    for(int i = 0; i < 3; i++){
      cout << dp[first_color][i][j] << " ";
    }
    cout << "\n";
  }
}

int main(){

  cin >> N;

  for(int i = 0 ; i < N; i++){
    int r, g, b;
    cin >> r >> g >> b;
    //tmp = make_tuple(r, g, b);
    
    rgbValue[0].push_back(r);
    rgbValue[1].push_back(g);
    rgbValue[2].push_back(b);
  }

  //cout << dfs(0, 0) << "\n";
  //cout << dfs(1, 0) << "\n";
  //cout << dfs(2, 0) << "\n";
  cout << min(min(dfs(0, 0, 0), dfs(1, 1, 0)), dfs(2, 2, 0)) <<"\n";

  //print_dp(0);
  //print_dp(1);
  //print_dp(2);
  return 0;
}
