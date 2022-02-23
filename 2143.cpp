#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;
int setA[1005];
int accA[1005];
int setB[1005];
int accB[1005];
int T, nA, nB;

long long ans = 0;

int main(){
  cin >> T;
  cin >> nA;

  accA[0] = 0;

  for(int i = 0 ; i < nA; i++){
    cin >> setA[i];
    accA[i+1] = accA[i] + setA[i];

  }
  cin >> nB;
  for(int i = 0 ; i < nB; i++){
    cin >> setB[i];
    accB[i+1] = accB[i] + setB[i];
  }
  
  int ind = 0;
  vector<int> arr;
  for(int i = 1; i <= nB; i++){
    for(int j = 0; j < i; j++){
      int sum = accB[i] - accB[j];
      //cout << "sumB: "<< sum << "\n";
      arr.push_back(sum);
    }
  }

  sort(arr.begin(), arr.end());
  map<int, int> m;
  for(int i = 1; i <= nA; i++){
    for(int j = 0; j < i; j++){
      int sum = accA[i] - accA[j];
      long long nums = 0;
      //cout << "sumA: "<< sum << "\n";
      if(m[sum] != 0){
        if(m[sum] != -1)
          ans += m[sum];
      } else {
        vector<int>::iterator iter = lower_bound(arr.begin(), arr.end(), T - sum);
        int found = arr[iter - arr.begin()] ;
        //cout << "found " << found << "\n";
        
        while(found == T - sum){ 
          nums++;
          if(iter+1 == arr.end()){
            break;
          }
          iter = lower_bound(iter + 1, arr.end(), T - sum);
          found = arr[iter - arr.begin()] ;
          //cout << "found " << found << "\n";
        }
        if(nums == 0){
          m[sum] = -1;
        } else {
          m[sum] = nums;
          ans += nums;
        }
      }
    }
  }
  cout << ans;
  return 0;
}
