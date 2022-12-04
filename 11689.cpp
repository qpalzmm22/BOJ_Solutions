#include <iostream>
#include <cmath>
#include <vector>
#include <set>

using namespace std;


// FirstThouhgt : use 포함배제의 원리
// get factor of N and find possibiliy by using
// N - p[a1] - p[a2] + p (a*b) ===> WRONG 
// use phi function
long long N;
set < long long  > factors;
int main(){
  cin >> N;

  long long n = N;
  long long i = 2;
  bool is_prime;

  // find factors and
  while( i <= sqrt(N)){ 
    if(n % i == 0){
      n /= i;
      factors.insert(i);
    }else{
      i++;
    }
  }
  if( n > 1)
    factors.insert(n);

  long long ans = N;
  // use phi function
  for(auto itr = factors.begin() ; itr != factors.end() ; itr++){
    long long num = *itr;
    //cout << num << " ";
    //ans =  ans * (num - 1)/ num ; // always int
    ans =  ans / num * (num - 1); // always int
    //cout << ans << "\n";
  }

  cout << ans ;


  return 0;
}
