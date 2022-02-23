#include <iostream>
#include <cmath>

using namespace std;

int primeN = 0;

int primes[2000000];
long long accPrimes[2000000];
int ans = 0;
int num;
// n (sqrt(n))?
void findPrimes(int num){
  int i = 2;
  int sqrtnum = ceil(sqrt(num));
  while(i <= num){
    bool flag = false;
    for(int j = 0; j < primeN; j++){
      if(sqrtnum < primes[j])
        break;

      if(i % primes[j] == 0){
        flag = true;
        break;   
      }
    }
    if(flag == false){
      primes[primeN] = i;
      accPrimes[primeN+1] = accPrimes[primeN] + i; // starts from index 1
      //cout << accPrimes[primeN] << " is a prime\n";
      primeN++;
    }
    i++;
  }
}

void solve(){
  for(int i = 0; i < primeN + 1; i++){
    for(int j = i; j < primeN + 1; j++){
      int sub = accPrimes[j] - accPrimes[i];
      if(sub > num)
        break;
      if(sub == num){
      //`cout << i <<  " " << j << " " << sub << "\n";
        ans++;
        break;
      }
    }
  }
}

int main(){
  cin >> num;
  findPrimes(num);
  solve();
  cout << ans << "\n";
}
