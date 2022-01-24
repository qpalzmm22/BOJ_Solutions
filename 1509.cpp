// solve with dp by increasing index by one and checking fron (i+1)/2
//
#include <iostream>
#define MAX 2510

using namespace std;

int dp[2510];

string str;

bool ispalindrome(int from, int end ){
  while(from <= end){
    if(str[from] != str[end])
      return false;
    from++;
    end--;
  }
  return true;
}

int solve(int sz){
  if(dp[sz] != 0)
    return dp[sz];
  
  if(sz == 0){
    return 0;
  }

  int mingroup = MAX;
  for(int i = 0; i < sz; i++){
    if(ispalindrome(i, sz - 1)){
      mingroup = min(mingroup, solve(i) + 1 );
    }
  }
  dp[sz] = mingroup;
  return mingroup;
}

int main()
{
  
  cin >> str;
  cout << solve(str.size());
  return 0;
}
