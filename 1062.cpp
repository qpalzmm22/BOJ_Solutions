#include <iostream>
#include <iostream>

using namespace std;


int N, K;

// convert it into numbers
string words[55];
int wordmask[55];
int total_max = 0;

void printM(int mask){
  cout << "mask : ";
  for(int i = 0 ; i < 26;i++){
    if(mask & (1 << i))
      printf("%c", ('a' + i));
  }
  cout <<"\n";
}

// 0110010 
// 0110011

// 00100001
// 00011110

/*
int solve(int idx, int num, int mask){
  //cout << ">> "<< idx << " " << num  <<"\n";
  //printM(mask);
  if(num == K || idx == 25){
    int tot = 0 ;
    for(int i = 0 ; i < N; i++){
      if((wordmask[i] | mask) == mask){
        tot++;
      }
    }
    //cout << tot << " : ";
    return max(total, tot;
  }else{
    int tot = solve(idx+1, num + 1, mask | (1 << (idx+1)));
    if('a' + idx + 1 == 'a' || 'a' + idx + 1 == 'n' || 'a' + idx + 1 == 't' || 'a' + idx + 1 == 'i' || 'a' + idx  + 1 == 'c')
      return tot;  
    return max(tot, solve(idx+1, num, mask));
  }
}
*/

// 0100011
// 0000110
void solve(int idx, int num, int mask){
  int tot = 0;

  if(num == K + 1 || idx == 26){
    //printM(mask);
    for(int i = 0 ; i < N; i++){
      if((wordmask[i] | mask) == mask){ // could be covered my this mask
        tot++;
      }
    }
    total_max = max(total_max, tot);
  } else {
    if('a' + idx  == 'a' || 'a' + idx  == 'n' || 'a' + idx  == 't' || 'a' + idx == 'i' || 'a' + idx == 'c')
      solve(idx+1, num + 1, mask | (1 << (idx))); // include this letter in mask
    else{
      solve(idx+1, num + 1, mask | (1 << (idx)));
      solve(idx+1, num , mask);
    }
  }
}

int main(){
  cin >> N >> K;
  //string given = "antatica"; // antic
  
  //for(int i = 0 ; i < given.size(); i++){
  //  mask |= (1 << (given[i] - 'a')); 
  //}
  for(int i = 0 ; i < N; i++){
    cin >> words[i];
    for(int j = 0; j < words[i].size(); j++){
      wordmask[i] |= (1 << (words[i][j] - 'a'));
    }
  }

  //cout << hex << mask ;
  // choose K from 0 - 26 
  solve(0, 1, 1); 
  cout << total_max;
  return 0;
}
