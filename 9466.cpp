#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <string.h>

using namespace std;

// firsth thought : Strongly Connected Component? use DFSㅁ

int TC;
int N;

int g[100005];
int indegree[100005];

queue<int> q;

int leftout = 0;
void reset(){
  memset(g, 0, sizeof(int) * (N + 1));
  memset(indegree, 0, sizeof(indegree));
  leftout = 0;
}

void solve(){
  for(int i = 1 ; i <= N; i++){
    if(indegree[i] == 0){
      //cout << "in "  << i << "\n";
      q.push(i);
    }
  }

  
  while(!q.empty()){
    int num = q.front();
    q.pop();
    
    //cout << num << " "  << g[num] << "\n";
    
    indegree[g[num]]--;
    if(indegree[g[num]] == 0){
      q.push(g[num]);
    }
    leftout++;
  }
}

void printdeg(){
  cout << "\n=== deg\n";
  for(int i = 1; i <= N; i++){
    cout << indegree[i] << " ";
  }
  cout << "\n=== deg\n";
}
int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  
  cin >> TC;
  while(TC--){
    leftout = 0;
    cin >> N;

    for(int i = 1; i <= N; i++){
      int val;
      cin >> val;
      g[i] = val;
      indegree[val]++;
    }
  
    //printdeg();
    solve();
    cout << leftout << "\n";
    reset();
  }


  //int ord = 1;
  //printDP();
  return 0;
}
