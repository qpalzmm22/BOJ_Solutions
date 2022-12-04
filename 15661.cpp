#include <iostream>
#define INF 2e9
using namespace std;

int N;
int map[25][25];

int minDiff = INF;
// FT : N = 20, TO = 2 sec. 
// Something like bruteforce could work

int my_abs(int num){
  return (num > 0) ? num : -1*num;
}
void solve(int idx, int group, int num){
  if(idx == N || num >= N/2){
    int group1 = 0;
    int group2 = 0;
    for(int i = 0; i < N; i++){
      for(int j = 0 ; j < N ; j++){
        if( (group & (1 << i)) && (group & (1 << j)))
          group1 += map[i][j];
        if( !(group & (1 << i)) && !(group & (1 << j)))
          group2 += map[i][j];
      }
    }
    minDiff = min(minDiff, my_abs(group1 - group2));
  } else {
    solve(idx + 1, group | (1 << idx), num+1);
    solve(idx + 1, group, num);
  }
}

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);

  cin >> N ;
  
  for(int i = 0 ; i < N ; i++){
    for(int j = 0; j < N; j++){
      cin >> map[i][j];
    }
  }
  solve(0, 0, 0);
  cout << minDiff;
  return 0;
}
