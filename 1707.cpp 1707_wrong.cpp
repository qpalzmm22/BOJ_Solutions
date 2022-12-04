#include <iostream>
#include <vector>
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
    bool check = true;
    for(int i = 0 ; i < E; i++){
      int n1, n2;
      
      cin >> n1 >> n2;
      if(n1 > n2)
        swap(n1, n2);
      edges.push_back(make_pair(n1, n2));
    }
    sort(edges.begin(), edges.end());
    
    for(int i = 0 ; i < E; i++){
      int n1 = edges[i].first;
      int n2 = edges[i].second;
      cout << n1 << " "<< n2 << "\n";

      if(group[n1] == 0 && group[n2] == 0){
        group[n1] = 1;
        group[n2] = 2;
      } else if(group[n1] == group[n2]){
        cout << "NO\n";
        check = false;
        break;
      } else{
        if(group[n1] == 0){
          group[n1] = group[n2] % 2 + 1; // 1 or 2
        } else if(group[n2] == 0){
          group[n2] = group[n1] % 2 + 1; // 1 or 2
        }
      }
    }

    if(check)
      cout << "YES\n";
    printGroup(V);
  }
  return 0;
}
