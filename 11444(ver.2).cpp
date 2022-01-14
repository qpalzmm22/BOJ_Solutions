// Solve with Daganu ...
// F2n = Fn-1Fn + FnFn+1
// 1. f2n = fn(2fn-1 + fn)
// 2. f2n-1 = fn^2 +fn-1^2

#include <iostream>
#include <map>

#define DIVISOR 1000000007

using namespace std ;

map<long long, long long> memo;

long long fib(long long n){
  long long res = 0;
  //cout << n<< "\n";
  if(n == 0)
    return 0;
  if(n == 1)
    return 1;

  if(memo.find(n) != memo.end()){
    return memo.find(n)->second;
  }

  long long fn = fib((n+1)/2);
  long long fnm1 = fib((n+1)/2-1);

  if(n % 2 == 0){
    memo[n] = (fn * (((2 * fnm1) % DIVISOR) + fn) % DIVISOR) % DIVISOR;
  }else{
    memo[n] = (((fn * fn) % DIVISOR) + ((fnm1 * fnm1) % DIVISOR)) % DIVISOR;
  }
  
  return memo[n];
}

int main(){
    long long n;

    cin >> n;
  
    cout << fib(n);
    return 0;
}
