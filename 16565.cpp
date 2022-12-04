#include <iostream>
#define ull unsigned long long

using namespace std;

int N;

ull factorial(ull from, ull to){

  ull res = 1;
  for(ull i = from + 1; i <= to; i++){
    res *= i;
  }
  return res;
}

int main(){
  cin >> N;

  // N chooose 52
  ull res;
  if(52 - N > N){
    res = factorial(52 - N, 52) / factorial(1, N); 
  } else{
    res = factorial(N, 52) / factorial(1, 52 - N); 
  }
  cout << res;

  return 0;
}
