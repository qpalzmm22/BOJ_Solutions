#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define pii pair < int, int >

// if a1 > a2 && b1 < b2 || a1 < a2 && b1 > b2 == crossing
// greedy => From largest crossing, we take it out
//  ==> is there case where largeset crossing doesn't get included in the
//  answer? 
//  Or we can find out which ones are crsosing each other. 
// Draw "graph" and cut off the edges as we go. 
// --- > FAIL
// Greedy doesn't work. We need to use DP somehow
// Solve by Using LIS.
// N - LIS(sorted(N)) is the answer...?

using namespace std;
int N;

pii lines[105];

int dp[105];

bool cmp(pii a, pii b){
  return a.first < b.first;
}


void printLine(){
  cout <<"------------------------\n";
  for(int i = 0 ; i < N; i++){
    cout << lines[i].first <<  " : " << lines[i].second << "\n";
  }
}

void printDp(){
  cout <<"------------ DP ------------\n";
  for(int i = 0 ; i < N; i++){
    cout << i <<  " : " << dp[i] << "\n";
  }
}
int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  cin >> N;

  for(int i = 0 ; i < N; i++){
    int leftLine;
    int rightLine;
    cin >> leftLine >> rightLine;
    lines[i] = make_pair(leftLine, rightLine);
  }


  // O(NlgN)
  sort(lines, lines + N, cmp);
  //(O(N^2)
  //printLine();
  
  int lis = 0 ;
  dp[0] = 1;
  for(int i = 1 ; i < N ; i++){
    dp[i] = 1;
    for(int j = 0 ; j < i ; j++){
      if(lines[i].second > lines[j].second)
        dp[i] = max(dp[i], dp[j] + 1);
        lis = max(lis, dp[i]); 
    }
  }
  //printDp();
  cout << N - lis;
  
  return 0;
}
