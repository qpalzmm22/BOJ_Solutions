#include <iostream>
#include <algorithm>
#include <vector>
#define ll long long 
#define REM 1000000007

using namespace std;
int N;
vector <ll> menu;

// saves value of 2 ^ 299999 % REM
ll dp[300005];

ll solve(int num, int pow){
  ll tmp = (num * dp[pow]) % REM;
  //cout << num << " " << pow << " " << tmp << "\n";
  return tmp;
}

// must solve it by n;gn
int main(){
  cin >> N;

  for(int i = 0; i < N ; i++){
    int val;
    cin >> val;
    menu.push_back(val);
  }

  sort(menu.begin(), menu.end());
  dp[0] = 1;
  for(int i = 1; i <= 300000; i++){
    dp[i] = (dp[i-1] << 1) % REM;
  }

  ll ans = 0;
  for(int i = 0 ; i < N -1 ; i++){
    for(int j = i + 1; j < N ; j++){
      //cout << i << " " << j  << "\n";
      ans = (ans +  solve((menu[j] - menu[i]) % REM, j - i - 1 )) % REM;
      //(menu[j] - menu[i]) * 2 ^ (m)
    }
  }
  cout << ans ;


  return 0; 
}
