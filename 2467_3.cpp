#include <iostream>
#include <math.h>
#include <vector>
#define MAX 2e9

using namespace std;


int N;
vector < int > arr1;
vector < int > arr2;
int poss_idx;
//vector < int > arr;


// simliar to the one i solve b4 (subgrouping)
// orig -> nc2 = O(n^2) => 10 000 000 000
// new -> O(n/2lgn)
int main(){
  cin >> N;

  for(int i = 0 ; i < N ; i++){
    int tmp;
    cin >> tmp;
    if(tmp < 0){
      arr1.push_back(tmp) ;
    }else{ // >= 0
      arr2.push_back(tmp) ;
    }
  }
  
  int min_diff = MAX;

  int min_n1 = arr1[0];
  int min_n2 = arr1[1];
  for(int i = 0; i < arr1.size() ; i++){
    int n1, n2;
    n1 = arr1[i];
    
    int n = lower_bound(arr2.begin(), arr2.end(), -1 * n1) - arr2.begin();

    if(n == N)
      n2 = arr2[n-1];
    else if(n == 0)
      n2 = arr2[0];
    else{
      int lower = arr2[n];
      int upper = arr2[n-1];
      
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
      cout << n1 << " " << n2 << " " << min_diff << "\n";
    }
  } 
  cout << min_n1 << " " << min_n2 << "\n";
  return 0;
}
