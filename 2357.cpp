#include <iostream>
#define ll long long 
#define pii pair < ll, ll >
#define MX 2e15
#define MN 0

using namespace std;

int N, M ;

pii tree[200005]; // min , max 

void init(){
  for(int i = N-1; i > 0; i--){
    tree[i].first = min(tree[i << 1].first, tree[i << 1 | 1].first);
    tree[i].second = max(tree[i << 1].second, tree[i << 1 | 1].second);
  }
}
void update(int idx, ll val){
  tree[idx+N].first = val;
  tree[idx+N].second = val;
  for(int i = idx+N; i > 1; i >>= 1){
    tree[i >> 1].first = min(tree[i].first, tree[i^1].first);
    tree[i >> 1].second = max(tree[i].second, tree[i^1].second);
  }
}

pii query(int l, int r){
  ll min_val = MX;
  ll max_val = MN;
  l += N;
  r += N;
  for(; l < r; l >>= 1, r >>= 1 ){
    if(l&1){
      min_val = min(min_val, tree[l].first);
      max_val = max(max_val, tree[l].second);
      l++;
    }
    if(r&1){
      --r;
      min_val = min(min_val, tree[r].first);
      max_val = max(max_val, tree[r].second);
    }
  }

  return make_pair(min_val, max_val);
}

void printTree(){
  for(int i = 1; i <= 2*N ; i++){
    cout << " <"<< tree[i].first << ", " << tree[i].second << ">\n";
  }
}
int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);

  cin >> N >> M;

  init();

  for(int i = 1 ; i <= 2*N; i++){
    tree[i].first = MX;
    tree[i].second = MN;
  }

  for(int i = 0 ; i < N ;i++){
    ll num;
    cin >> num;
    update(i, num);
  }

  //printTree();

  for(int i = 0 ; i < M ; i++){
    ll a, b;
    cin >> a >> b;
    pii ans = query(a-1, b);
    cout << ans.first << " " << ans.second << "\n";
  }
    
  

  return 0;
}
