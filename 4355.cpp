#include <iostream>
#include <cmath>
#define ll long long 

using namespace std;

int main(){

  cin.tie(0);
  ios_base::sync_with_stdio(0);
  ll N = -1;

  while(1){
    cin >> N;
    if(N == 0) break;

    // get factors
    ll i = 2;
    ll q = N;
    ll n = N;
    while( i <= sqrt(N)){
      if(n % i == 0){
        while( n % i == 0) n /= i;
        q -= q / i;
      } else {
        i++;
      }
    }
    if(n > 1)
      q -= q/n;

    cout << q << "\n";
  }
  
  

  return 0;
}
