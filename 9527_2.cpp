#include <iostream>
#include <math.h>

using namespace std;

long long dp[100];

long long get_full(int idx){
  if(idx < 0)
    return 0;
  if(dp[idx])
    return dp[idx];

  return dp[idx] = 2 * get_full(idx - 1) + ((long long)1 << (idx));
}

long long solve(long long n){
  long long tmp = n;
  long long i = 63;
  long long total = 0;
  while(i >= 0){
    if((tmp >> i) & 1){
      long long full = get_full(i - 1);
      total += full;
      total += tmp - ((long long) 1 << i) + 1;
      tmp = tmp - ((long long) 1 << i );
    }
    i--;
  }
  return total;
}


int main(){
  long long A, B;

  cin >> A >> B;

  dp[0] = 1;

  cout << solve(B) - solve(A-1);
  return 0;
}
