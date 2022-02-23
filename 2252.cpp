#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int M, N;
queue<int> q;
vector<int> adj[100005];

int indegree[32005];

int main(){
  cin >> N >> M;

  for(int i = 0; i < M ; i++){
    int num1, num2;
    cin >> num1 >> num2;
    indegree[num2]++;
    adj[num1].push_back(num2);
  }

  for(int i = 1; i <= N; i++){
    if(indegree[i] == 0)
      q.push(i);
  }

  while(!q.empty()){
    int num = q.front();
    q.pop();
    cout << num <<" ";
    
    for(int i = 0; i < adj[num].size(); i++){
      int num2 = adj[num][i];
      indegree[num2]--;
      if(indegree[num2] == 0 ){
        q.push(num2);
      }
    }
  }

  return 0;
}
