#include <iostream>
#include <string.h>
#include <map>

using namespace std;

int N;

int p[200005];
int network_size[200005];
int T;
int F;


int find(int a){
  if(p[a] < 0){
    return a;
  }
  return p[a] = find(p[a]);
}
int uni(int a, int b){
  int u = find(a);
  int v = find(b);

  if( u == v )
    return network_size[u];

  if(p[u] > p[v])
    swap(u, v);

  if(p[u] == p[v])
    p[u]--;

  p[v] = u;
  network_size[u] += network_size[v];
  return network_size[u];
}


int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cin >> T;
  while(T--){
    cin >> F;

    map <string, int> str_map;

    memset(p, -1, sizeof(p));
    memset(network_size, 0, sizeof(network_size));
    int idx = 0; // number of network_size
    for(int i = 0 ; i < F; i++){
      string tmp1, tmp2;
      cin >> tmp1 >> tmp2;

      if(str_map.find(tmp1) == str_map.end()){
        network_size[idx]++;
        str_map.insert(make_pair(tmp1, idx++));
      } // doesn't exist

      if(str_map.find(tmp2) == str_map.end()){
        network_size[idx]++;
        str_map.insert(make_pair(tmp2, idx++));
      } // doesn't exist

      int idx1 = str_map[tmp1];
      int idx2 = str_map[tmp2];

      int network = uni(idx1, idx2);
      cout << network <<"\n";
    }
  }
  return 0;
}
