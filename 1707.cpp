#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
#include <algorithm>

#define pii pair < int, int >

using namespace std;

int K;
int V, E;

int group[20005];

void printGroup(int nodes){
  for(int i = 1 ; i <= nodes; i++){
    cout << group[i] << " ";
  }
}

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  cin >> K;

  // 5nlogn
  while(K--){

    memset(group, 0, sizeof(group));
    
    cin >> V >> E;
    
    vector < pii > edges;
    vector < int > adj[V + 5];
    bool check = true;
    for(int i = 0 ; i < E; i++){
      int n1, n2;
      
      cin >> n1 >> n2;
      adj[n1].push_back(n2);
      adj[n2].push_back(n1);
    }

    // bfs for every node execpt the ones that are visited
    queue < int > q;

    for(int i = 1 ; i <= V ; i++){
      int node = i;
      if(group[node] != 0)
        continue;

      group[node] = 1;
      q.push(node);

      while(!q.empty() && check){
        int n1 = q.front();
        q.pop();

        for(int j = 0; j < adj[n1].size(); j++){
          int n2 = adj[n1][j];
          if(group[n2] == group[n1]){
            check = false;
            break;
          }
          if(group[n2] == 0){
            //cout << "n : " <<  n1 << " " << n2 <<  "\n";
            group[n2] = group[n1] % 2 + 1; // 1 -> 2, 2 -> 1
            q.push(n2);
          }
        }
      }
    }
    if(check)
      cout << "YES\n";
    else
      cout << "NO\n";

  }
  return 0;
}
