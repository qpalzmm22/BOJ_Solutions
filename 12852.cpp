#include <iostream>
#include <queue>
#define MAX 1000005
#define pii pair<int, int>
using namespace std;

int dp[1000005];
int N;

void bfs(int n){
  queue< pii > q;
  q.push(make_pair(n, 0));

  while(!q.empty()){
    int x = q.front().first;
    int num = q.front().second;
    q.pop();

    if(x == 1){
      break;
    }

    //cout << "dp["<< x <<"] :  " << num <<"\n";
    
    if(x % 3 == 0 && !dp[x/3]){
      dp[x/3] = x;
      q.push(make_pair(x/3, num +1));
    }
    if(x % 2 == 0 && !dp[x/2]){
      dp[x/2] = x;
      q.push(make_pair(x/2, num +1));
    }
    if(!dp[x-1]){
      dp[x-1] = x;
      q.push(make_pair(x - 1, num +1));
    }
  }
  int x = 1;
  int num = 0; 
  vector<int> ans;
  ans.push_back(1);
  while(x != n){
    //cout << dp[x] << " ";
    ans.push_back(dp[x]);
    x = dp[x];
    num++;
  }
  cout <<  num  << "\n";
  
  for(int i = ans.size() - 1; i >= 0; i--){
    cout << ans[i] << " ";
  }
}

int dfs(int n, int num){
  if(dp[n])
    return dp[n];


  cout << "dp["<< n <<"] :  " << num <<"\n";
    
  if(n == 1){
    return num;
  }

  int val = MAX;
  if(n % 3 == 0){
    val = min( val, dfs(n/3, num+1));
  }
  if(n % 2 == 0){
    val = min( val, dfs(n/2, num+1));
  }
  val = min( val, dfs(n -1, num+1));
  dp[n] = val;

  return val;
}

int main(){
  cin >> N;
  
  bfs(N);
  //cout << dfs(N, 0) << "\n";
  return 0;
}
