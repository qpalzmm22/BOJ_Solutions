#include <iostream>
#define MX 10005

using namespace std;

int N, K;
int lines[10005];

int main(){

  cin >> K >>  N ;
  
  int max_line = 0;
  for(int i = 0 ; i < K ; i++){
    cin >> lines[i];
    max_line = max(max_line, lines[i]);
  }
  
  long long left_bound = 1;
  long long right_bound = max_line;

  // nlg n, n = 10000 * 100
  
  
  while(1){
    long long mid = left_bound + (right_bound - left_bound) / 2;
    
    long long num = 0 ;
    for(int i = 0 ; i < K; i++){
      num += lines[i] / mid;
    }
    //cout << "m: "<< mid << " " << num << " " << "\n";
    //cout <<  left_bound << " " << right_bound <<  "\n";

      
    if(num >= N){
      if(left_bound + 1 >= right_bound){
        mid = left_bound + 1;
        num = 0 ;
        for(int i = 0 ; i < K; i++){
          num += lines[i] / mid;
        }
        if(num == N)
          cout << mid;
        else
          cout << mid -1;
        break;
      }
      left_bound = mid ;
    }else{
      right_bound = mid ;
    }
  }
  return 0;
}
