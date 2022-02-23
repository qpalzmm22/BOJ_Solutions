//Solve it with priority queue and indegre
// The topology sort requrires indegree of 0 to be the next order

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> adj[40000];
int indeg[40000];
priority_queue<int> pq;


int main()
{
  int N, M; 
  cin >> N >> M;
  int a, b;

  for(int i = 0 ; i < M; i++){
    cin >> a >> b;
    adj[a].push_back(b);
    indeg[b]++;
  }

  for(int i = 1 ; i <= N; i++){
    if(indeg[i] == 0)
      pq.push(-1 * i);
  }

  while(!pq.empty()){
    int num = -1 * pq.top();
    pq.pop();
    cout << num << " ";

    for(int i = 0; i < adj[num].size(); i++){
      int v2 = adj[num][i];
      indeg[v2]--;
      if(indeg[v2] == 0)
        pq.push(-1 * v2);
    }
  }
  return 0;
}
