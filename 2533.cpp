#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N;

vector < int > adj [1000005];
char visited[1000005];

vector < int > children [1000005];
// first Thought : use dfs to solve biparite dfs?
// But. do we have enuf space ?

void printVisited(){
  for(int i = 1 ; i <= N ; i++){
    cout << visited[i] << " ";
  }
  cout << "\n";
}

int total = 0;
// N
bool solve(int node){
  int color = false;
  for(int i = 0 ; i < children[node].size(); i++){
    int child = children[node][i];
    if(solve(child) == false && !color){
      color = true;
      total++;
    }
  }
  return color;
}

// N
void makeTree(int root, int parent){
  for(int i = 0 ; i < adj[root].size(); i++){
    int child = adj[root][i];
    if(child == parent)
      continue;

    children[root].push_back(child);
    makeTree(child, root);
  }
}
int main(){

  cin >> N;

  for(int i = 0 ; i < N-1; i++){
    int u , v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  makeTree(1, -1);
  solve(1);
  cout << total;

  return 0;
}
