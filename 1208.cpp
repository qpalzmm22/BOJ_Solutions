#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, S;
int arr[50];
int dp[50];
long long cnt = 0;

vector<int > a; // 1024 => (nlogn);
vector<int > b; // 1024

void halfA(int ind, int sum){
  ////cout << "A"<< ind << " " << sum << "\n";

  if(ind == N/2 )
    return;

  int newsum = sum + arr[ind];
  if(newsum == S)
    cnt++;
  

  a.push_back(newsum);
  halfA(ind + 1, newsum - arr[ind]);
  halfA(ind + 1, newsum);
}

void halfB(int ind, int sum){

  if(ind == N)
    return;

  int newsum = sum + arr[ind];
  
  //cout << "B"<< ind << " " << newsum << "\n";

  if(newsum == S)
    cnt++;
  
  b.push_back(newsum);
  halfB(ind + 1, newsum - arr[ind]);
  halfB(ind + 1, newsum);
}
int main(){
  cin >> N >> S;

  for(int i = 0; i < N; i++){
    cin >> arr[i];
  }
  
  halfA(0, 0);
  halfB(N / 2, 0);

  sort(b.begin(), b.end());

  for(int i = 0; i < a.size(); i++){
    int find = S - a[i];
    int lower = lower_bound(b.begin(), b.end(), find) - b.begin();
    int upper = upper_bound(b.begin(), b.end(), find) - b.begin();

    //cout << "find " << find << "lower " << lower << "upper " << upper << "\n";
    cnt += upper - lower ;
    //cout << "cnt "<< cnt;
  }

  cout << cnt;
  return 0;
}
