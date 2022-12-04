#include <iostream>
#define pii pair < int, int >
#define EMPTY make_pair(0, 0)

using namespace std;

pii dp[50];
int T;

pii fib(int n){
  
  if(dp[n] != EMPTY )
    return dp[n];

  pii res1 = fib(n-1);
  pii res2 = fib(n-2);
  
  return dp[n] = make_pair(res1.first + res2.first, res1.second + res2.second);
}
int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);

  cin >> T;

  dp[0] = make_pair(1, 0);
  dp[1] = make_pair(0, 1);
  
  while(T--){
    int num;
    cin >> num;
    pii res =  fib(num);
    cout << res.first << " " << res.second << "\n";
  }
  return 0;
}
