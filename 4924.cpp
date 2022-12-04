#include <iostream>
#include <vector>
#define MX 1000000
using namespace std;

int p[1000005];
int cump[1000005];
vector< int > primes;

void aristotle(){
  p[0] = 0;
  p[1] = 0;

  for(int i = 2; i * i < MX ; i++){
    int tmp = i;
    for(int j = 0; j < primes.size(); j++){
      while( tmp % primes[j] == 0 ){
        tmp /= primes[j];
        p[i]++;
      }
    }
    if(p[i] == 0){
      p[i] = -1;
      primes.push_back(i);
    }
    cump[i] = cump[i-1] + p[i];
  }
}
int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);

  int L, U;
  
  aristotle();

  //print p
  for(int i = 1 ; i <= 100; i++){
    //cout << i << " " << p[i] << "\n";
    cout << i << " " << cump[i] - i << "\n";
  }

  while(1){
    cin >> L >> U ;
    if( L == -1 && U == -1)
      break;
  

  }

  return 0;
}
