#include <iostream>
#include <vector>
#include <map>

using namespace std;

int N, M, K;

int p[100005 * 2];

int find(int a){
  if(p[a] == a){
    return a;
  } else {
    return p[a] = find(p[a]);
  }
}
void uni(int a, int b){
  int u = find(a);
  int v = find(b);

  p[u] = v;
}
// Group
int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);

  cin >> N >> M >> K;

  for(int i = 1; i <= 2*N; i++){
    p[i] = i;
  }

  for(int i = 0; i < M; i++){
    int t, a, b;
    cin >> t >> a >> b;
    
    if(t){
      uni(a+N, b);
      uni(b+N, a);
    }else {
      uni(a, b);
      uni(a+N, b+N);
    }
  }

  for(int i = 0 ; i < K; i++){
    int a, b;
    cin >> a >> b;

    if(find(a) != find(b) && find(a+N) != find(b)){
      cout << "Unknown\n";
    } else if(find(a) == find(a+N) || find(b) == find(b+N)){
      cout << "Error\n";
    } else if(find(a) == find(b)){
      cout << "Friend\n";
    } else if(find(a+N) == find(b)){
      cout << "Enemy\n";
    }

  }
  return 0;
}
