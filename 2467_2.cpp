#include <iostream>
#include <math.h>
#include <vector>
#define MAX 2e9

using namespace std;


int N;
vector < int > arr;
int poss_idx;
//vector < int > arr;


// simliar to the one i solve b4 (subgrouping)
// orig -> nc2 = O(n^2) => 10 000 000 000
// new -> O(nlgn)
int main(){
  cin >> N;

  for(int i = 0 ; i < N ; i++){
    int tmp;
    cin >> tmp;
    arr.push_back(tmp) ;
  }
  
  int min_diff = MAX;

  int min_n1 = arr[0];
  int min_n2 = arr[1];
  for(int i = 0; i < arr.size() - 1 ; i++){
    int n1, n2;
    n1 = arr[i];
    
    int n = lower_bound(arr.begin() + i + 1, arr.end(), -1 * n1) - arr.begin();

    if(n == N)
      n2 = arr[n-1];
    else if(n <= i + 1)
      n2 = arr[i+1];
    else{
      int lower = arr[n];
      int upper = arr[n-1];
      
      if(abs(n1 + lower) < abs(n1 + upper)){
        n2 = lower;
      } else{
        n2 = upper;
      }
    }
    
    if(min_diff > abs(n1 + n2)){
      min_diff = abs(n1 + n2);
      min_n1 = n1;
      min_n2 = n2;
    }
    //cout << n1 << " " << n2 << " " << min_diff << "\n";
  } 
  cout << min_n1 << " " << min_n2 << "\n";
  return 0;
}
