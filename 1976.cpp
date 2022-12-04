#include <iostream>
#include <algorithm>

using namespace std;

int p[205];
int plan[205];
int N, M;

int find(int a){
  if(p[a] < 0){
    return a;
  }else{
    return p[a] = find(p[a]);
  }
}
void group_union(int a, int b){
  int u = find(a);
  int v = find(b);
  
  if( u == v)
    return;
  //cout <<" u, v : " <<  u << " " << v << "\n";

  if(p[u] > p[v]) // if u is smaller tree
    swap(u, v); // make v the smaller tree

  int vrank = p[v];
  p[v] = u;
  if(p[u] == vrank)
    p[u]--;
}

int main(){
  cin >> N;
  cin >> M;

  for(int i = 1; i <= N; i++){
    p[i] = -1;
  }

  for(int i = 1 ; i <= N; i++){
    for(int j = 1 ; j <= N; j++){
      int num;
      cin >> num;

      if(j < i)
        continue;
      if(num == 1)
        group_union(i, j);
    }
  }
  
  for(int i = 0 ; i < M; i++){
    int city;
    cin >> city;
    plan[city] = 1;
  }

  bool same_group = true;
  int prev = 0;
  for(int i = 1 ; i <= 200; i++){
    if(plan[i] == 0)
      continue;
    int city = i;

    if(prev != 0 && find(city) != find(prev))
      same_group = false;
    prev = city;
  }

  if(same_group)
    cout << "YES";
  else  
    cout << "NO"; 
  return 0; 
}
