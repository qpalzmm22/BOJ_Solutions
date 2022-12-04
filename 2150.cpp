#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

// SCC = > use dfs? twise with G^-1
//
vector < int > G[10005];
vector < int > G_inv[10005];

int finishing_time[10005];
//push_back by 

int V;
int E; 

vector<int> answer;

bool visited[10005];
bool rev_visited[10005];

int dfs(int v, int time){

  visited[v] = true;;

  for(int i = 0; i < G[v].size(); i++){
    if(visited[G[v][i]]) continue;

    time = dfs(G[v][i], time);
  }
  finishing_time[v] = time + 1;
  return time + 1;
}

void printF(){
  cout << ">>\n";
  for(int i = 1 ; i <= V; i++){
    cout << finishing_time[i] << " ";
  }
}

void dfs_rev(int v){

  rev_visited[v] = true;
  answer.push_back(v);

  for(int i = 0; i < G_inv[v].size(); i++){
    if(rev_visited[G_inv[v][i]]) continue;

    dfs_rev(G_inv[v][i]);
  }
}

// SCC = 2 dfs = O(2V+2E)
int main(){
  cin >> V >> E;

  for(int i = 0 ; i < E; i++){
    int u, v;
    cin >> u >> v;
    G[u].push_back(v);
    G_inv[v].push_back(u);
  }

  int time = 0;
  for(int i = 1 ; i <= V; i++){
    if(visited[i]) continue;

    time = dfs(i, time);
    //cout << "t : "<< time << "\n";
  }
  //printF();

  priority_queue< pair< int, int > > pq;

  for(int i = 1 ; i <= V; i++){
    pq.push(make_pair(finishing_time[i], i));
  }
  
  priority_queue< pair< int, vector<int> > > anspq;

  // V lg V
  while(!pq.empty()){
    int i = pq.top().second;
    //cout << " > " << ft << " "<< i <<"\n";
    pq.pop();

    if(rev_visited[i]) continue;
    
    dfs_rev(i);
    sort(answer.begin(), answer.end());
    
    anspq.push(make_pair(-1 * answer[0], answer));
    answer.clear();
  }

  cout << anspq.size() << "\n";
  // V
  while(!anspq.empty()){
    vector<int> arr = anspq.top().second;
    
    for(int i = 0 ; i < arr.size(); i++){
      cout << arr[i] << " ";
    }
    cout << "-1\n";
  
    anspq.pop();
  }
  /*
  for(int i = 1 ; i <= V ; i++){
    if(rev_visited[i]) continue;
    
    dfs_rev(i);
    sort(answer.begin(), answer.end());
    for(int i = 0 ; i < answer.size(); i++){
      cout << answer[i] << " ";
    }
    cout << "-1\n";
    answer.clear();
  }
  */
  return 0 ;
}
