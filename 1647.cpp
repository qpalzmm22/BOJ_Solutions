#include <iostream>
#include <tuple>
#include <queue>

#define tiii tuple<int, int, int >

using namespace std;


int parent[100005];
//vector <pii > adj[100005];
priority_queue < tiii > pq;


int find(int a){
  
  if(parent[a] == a)
    return a;
  else
    return parent[parent[a]] = find(parent[a]);
}

// a's parent become b's parent
void uni(int a, int b){
  parent[find(b)] = find(a);
}

int kruscal(){
  int tot = 0;
  int max = 0;
  while(!pq.empty()){
    tiii tup = pq.top();
    pq.pop();
    int c = -1 * get<0>(tup);
    int v1 = get<1>(tup);
    int v2= get<2>(tup);

    if(find(v1) != find(v2)){
      //cout << "debug " << v1 << " " << v2 << " " << c << "\n";
      uni(v1, v2);
      max = c;
      tot += c;
    }
  }
  return tot - max;
}


int main(){

  int N, M;
  cin >> N >> M;
  
  for(int i = 0; i < N; i++){
    parent[i] = i;
  }

  for(int i = 0; i < M ; i++){
    int v1, v2, c;
    cin >> v1 >> v2 >> c;
    pq.push(make_tuple(-1 *c, v1, v2));
  }

  cout << kruscal();

  //for(int i = 0; i < N; i++){
  //  cout << i << " : " << parent[i]  << "\n";
  //}
  return 0;
}
