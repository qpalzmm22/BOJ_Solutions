#include <iostream>
#include <algorithm>

using namespace std;

int p[1000005];
int find(int a){
  if(p[a] < 0 ){
    return a;
  }
  return p[a] = find(p[a]); 
}

void uni(int a, int b){
  int u, v;
  u = find(a);
  v = find(b);
  if(u == v)
    return;
  if(p[u] > p[v]){
    swap(u, v);
  }
  if(p[u] == p[v])
    p[u]--;
  
  p[v] = u;
}

// 1000005 
int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int n, m;
  cin >> n >> m;
  for(int i = 1 ; i <= n+1 ; i++){
    p[i] = -1;
  }

  for(int i = 0; i < m ; i++){
    int op, a, b;
    cin >> op >> a >> b;

    if(op == 0){
      uni(a+1, b+1);
    }else{
      if(find(a+1) == find(b+1))
        cout << "YES\n";
      else
        cout << "NO\n";
    }
  }

  return 0;
}
