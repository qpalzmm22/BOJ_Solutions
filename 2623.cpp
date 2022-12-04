#include <iostream>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

int N, M;
vector<int> adj[1005];
bool visited[1005];
int indeg[1005];

queue<int> q;
queue<int> ans;

/*
void printIndeg(){
  cout << "-------\n";
  for(int i = 1 ; i <= N; i++){
    cout << indeg[i] << " ";
  }
  cout << "\n-------\n";
}
*/

// topological
int solve(){
  for(int i = 1; i <= N; i++){
    if(indeg[i] == 0){
      q.push(i);
    }
  }

  while(!q.empty()){
    int top = q.front();
    //cout << "poped " << top << "\n";
    visited[top] = true;
    ans.push(top);
    q.pop();
  
    for(int i = 0; i < adj[top].size(); i++){

      int v = adj[top][i];
      //cout << "v :  " << v << "\n";
      if(visited[v]) continue;

      indeg[v]--;

      if(indeg[v] == 0){
        q.push(v);
      }
    }
  }

  // check for cycle
  // after dealing with all the indgree = 0, if there's indegree > 0, than
  // there's cycle.
  int sum = 0;
  for(int i = 1; i <= M ; i++){
    sum+= indeg[i];
  }
  if(sum != 0)
    return 0;
  else 
    return 1;
}
int main(){
  cin >> N >> M;

  int order, num;
  for(int i = 0 ; i < M; i++){
    cin >> num;
    int num1 = 0;
    int num2 = 0;
    for(int j = 0; j < num; j++){
      num1 = num2;
      cin >> num2;

      
      if(num1 == 0)
        continue;

      //cout << "recv: " << num1 << ", " << num2 << "\n";
      // Opposite
      adj[num1].push_back(num2);
      indeg[num2]++;
    }
  }

  //printIndeg();
  // topological sort
  if(solve())
    while(!ans.empty()){
      cout << ans.front() <<"\n";
      ans.pop();
    }
  else {
    cout << "0\n";
  }

  //printIndeg();
  return 0;
}
