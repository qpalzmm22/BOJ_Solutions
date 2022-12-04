#include <iostream>
#include <algorithm>

using namespace std;



int N, C; 

long long homes[200005];
long long max_dist = 0;


int main(){
  

  cin >> N >> C ;
  
  for(int i = 0 ; i < N; i++){
    cin >> homes[i];
    max_dist = max(max_dist, homes[i]);
  }
  
  sort(homes, homes+N);

  long long left = 1;
  long long right = 1e9;

  // NlgN
  while(1){

    if(left + 1 == right){
      cout << left;
      break;
    }
    long long dist = (left + right) / 2;
    long long prev = homes[0];
    long long num_routes = 1;

    for(int i = 1 ; i < N; i++){
      if(homes[i] - prev >= dist){
        prev = homes[i];
        num_routes++;
      }
    }

    //cout << left << " " << right << "\n";
    if(num_routes < C){
      right = dist;
    } else {
      left = dist;
    }
  }

  return 0;
}
