#include <iostream>

using namespace std;


// since n is small( n < 20) = > 2^20 is max
int N, M;

bool arr[22];
int exp[2][105];


bool solve(int mask, int val){
  bool negation = false;
  if(val < 0){
    val = -1 * val;
    negation = true;
  }

  bool ans = false;
  if(mask & (1 << (val-1))){
    ans = true;
  }
  
  return !(ans ^ negation);
}

int main(){
  cin >> N >> M;
  
  for(int i = 0 ; i < M ; i++){
    cin >> exp[0][i] >> exp[1][i];
  }
  

  bool ans = false;
  for(int i = 0 ; i < (1 << N) ; i++){
    bool unsolvable = false;
    for(int j = 0 ; j < M ; j++){
      if(!(solve(i, exp[0][j]) || solve(i, exp[1][j]))){
        //cout << i << " " << exp[0][j] << " " << exp[1][j] << "\n";
        unsolvable = true;
      }
    }
    if(!unsolvable){
      ans = true;
    }
  }
  cout << ans;
  return 0;
}
