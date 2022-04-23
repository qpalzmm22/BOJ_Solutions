#include <iostream>
#define ull unsigned long long

/*
 * 3-10
 * 11 2
 * 100 1
 * 101 2
 * 110 2
 * 111 3
 * 1000 1
 * 1001 2
 * 1010 2
 * 1011 3
 * 1100 2
 * 1101 3
 * 1110 3
 * 1111 4
 * => 15
 * Divide and conquer gogo
 */
ull A, B;

using namespace std;

ull dp[10000];

ull solve(int x){
  cout << x << " " << "\n";
  if(x == 0){
    return 0;
  }
  int n_th_pow = 0;
  ull num = x;
  while( num > 0){
    n_th_pow++;
    num = num >> 1; 
  }
  if(dp[n_th_pow] != 0){
    return dp[n_th_pow];
 }
  dp[n_th_pow] =  2 * dp[n_th_pow - 1] + n_th_pow;
  return dp[n_th_pow];
}

int main(){
  cin >> A >> B;
  cout << solve(B) - solve(A-1);
  return 0;
}

