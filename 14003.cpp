#include <iostream>
#include <vector>
#include <algorithm>

#define NOP -1000000005
using namespace std;

int N;

// NO idea...
int num[1000005];
int dp[1000005];
void printDP(){
  cout << "printDP\n";
  for(int i = 0 ; i < N; i++){
    cout << dp[i] << " ";
  }
  cout << "printDP\n";
}
int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  cin >> N;

  vector<int> arr;
  vector<int> idxarr;
  int max_idx = -1;
  
  for(int i = 0 ; i < N ; i++){
    cin >> num[i];
  }
  idxarr.push_back(-1);

  int idx;
  for(int i = 0; i < N; i++){
    if( arr.empty() || arr.back() < num[i]){
      arr.push_back(num[i]);
      idxarr.push_back(i);
      max_idx = i;
      dp[i] = idxarr[idxarr.size() - 2];
    }else{
      idx = lower_bound(arr.begin(), arr.end(), num[i]) - arr.begin() ;
      //cout <<" low : " <<  i << " " << idx << " ";
      arr[idx] = num[i];
      idxarr[idx + 1] = i;
      
      dp[i] = idxarr[idx];
    }

  }
  
  int newidx = dp[max_idx]; 
  
  //printDP();
  //printarr();
  //
  //cout << "printArra\n";
  //for(int i = 0 ; i < arr.size(); i++){
   // cout << arr[i] << " ";
  //}

  vector<int> ans;
  while(max_idx != -1){
    ans.push_back(num[max_idx]);
    max_idx = dp[max_idx];
  }

  cout << ans.size() << "\n";
  for(int i = ans.size() - 1 ; i >= 0 ; i--){
    cout << ans[i] << " ";
  }

  //cout << arr.size() << "\n";
  

  return 0;
}
