#include <iostream>
#include <algorithm>
#define ll long long 
#define pii pair <int , ll>

using namespace std;

pii p[100005]; // parent, distance to root B - A = a, C - A = c, a - c = B - C  = w

//returns root and distance to root
pii find(int a, ll dist){
  //cout <<">>" <<  a << " " << dist << "\n";
  if(p[a].first < 0){
    return make_pair(a, dist);
  } else{
    //ll origdist = p[a].second; 
    pii tmp = find(p[a].first, dist + p[a].second) ;
    p[a] = tmp;
    p[a].second = tmp.second - dist;
    return tmp;
  }
}
// a = b + w
void uni(int a, int b, ll w){
  //cout <<">" <<  a << " " << b << " " << w << "\n";
  pii u = find(a,0);
  pii v = find(b,0);

  if(u.first == v.first)
    return ;

  int dist_to_top = p[a].second - p[b].second; // p[b].second;
  //int dist_to_top = p[a].second + p[b].second + w;
  // u always have high rank 

  //p[v.first] = make_pair(u.first, p[a].second+p[b].second-w);
  p[v.first] = make_pair(u.first, dist_to_top - w);
}

void answer2prof(int a, int b){
  pii u = find(a,0);
  pii v = find(b,0);

  if(u.first != v.first)
    cout << "UNKNOWN\n";
  else{
    cout << p[a].second - p[b].second << "\n";
  }
}

void reset(int n){
  for(int i = 1; i <= n ; i++){
    p[i] = make_pair(-1, 0);
  }
}

void printP(int n){
  cout << "print--\n";
  for(int i = 1; i <= n ; i++){
    cout << "[ " << p[i].first << ", " << p[i].second <<  " ]" << "\n"; 
  }
}

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int N = -1;
  int M = -1;

  while(1){
    cin >> N >> M;

    if( N == 0 && M == 0 ) break;

    reset(N);
    for(int i = 0 ; i < M ; i++){
      char op;
      int a, b;
      cin >> op;
      cin >> a >> b;
      if(op == '!'){
        int w;
        cin >> w;
        uni(a,b,w);
        //printP(N);
      } else {
        answer2prof(a, b);
        //printP(N);
      }
    }
    
  }

  return 0;
}
