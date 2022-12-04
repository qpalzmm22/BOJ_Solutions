#include <iostream>
#include <vector>
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

int map16[16];

using namespace std;

ull dp[10000];

// n is from 2^n
ull get_ones(ull n){

  if( n < 0){
    return 0;
  }
  if(dp[n]){
    //cout << "get_ones["<< n << "] : " << dp[n] <<  "\n";
    return dp[n];
  }
  
  dp[n] = ((n >> 1)) + 2 * (get_ones(n-1));

  return dp[n];
}

/*
ull solve(ull x){
  int mask = 0xf;
  ull sum = 0;
  while(x > 0){
    sum += map16[(x & mask)];
    x = x >> 4;
  }
  cout << sum << " \n";
  return sum;
}
*/

ull solve(ull x){
  if(x == 0){
    return 0;
  }

  vector < int > v;
  ull tmp = x;
  while(tmp > 0){
    v.push_back(tmp & 1);
    tmp = tmp >> 1;
  }

  ull sum = 0;
  ull val = x;
  for(int i = v.size() -1 ;i >= 0 ; i--){
    if(v[i] == 1){
      ull n = (1 << i) ;
      sum += get_ones(i-1);
      val = val - n;
      sum += val + 1;
    }
  }

  //cout << "sum : "  << sum << "\n";
  return sum;
}


void fill_map(){
  for(int i = 0 ; i < 16 ; i++){
    map16[i] = ((i >> 3) & 1) + ((i >> 2) & 1) + ((i >> 1) & 1) + (i & 1);
  }
}
int main(){
  cin >> A >> B;

  //fill_map();
  cout << solve(B) - solve(A-1);
  //for(int i = 0 ; i < 10; i++){
  //  cout  << dp[i]<< " ";
  //}
  return 0;
}

