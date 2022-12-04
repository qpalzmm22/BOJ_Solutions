#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  cin >> N;

  vector<int> arr;
  for(int i = 0; i < N; i++){
    int val;
    cin >> val;
    if(arr.empty() || arr.back() < val){
      arr.push_back(val);
    }else{
      lower_bound(arr.begin(), arr.end(), val)[0] = val;
    }
  }
  cout << arr.size();
  
  for(auto k : arr){
    cout << k << " ";
  }

  return 0;
}
