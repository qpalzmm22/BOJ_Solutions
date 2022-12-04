#include <iostream>
#define MX 2e9
#define MXN 100005
using namespace std;


int N;
int Q;
int tree[ MXN << 2];

void init(){
  for(int i = N -1; i > 0; i--){
    tree[i] = min(tree[i << 1], tree[i << 1 | 1]);
  }
}

void update(int idx, int val){
  tree[idx + N] = val;
  for(int i = idx+N; i > 1; i >>= 1){
    tree[i >> 1] = min(tree[i], tree[i^1]);
  }
}

int find(int l, int r){
  int res = MX;
  l += N;
  r += N;
  for(; l < r; l >>= 1, r >>= 1){
    cout << "f : " << l << " " << r << "\n";
    if(l & 1){
      res = min(res, tree[l]);
      cout << "l : " << l <<"\n";
      l++;
    }
    if(r & 1){
      r--;
      res = min(res, tree[r]);
      cout << "r : " << r <<"\n";
    }
  }
  return res;
}


int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);

  cin >> N;

  for(int i = 0 ; i < N ; i++){
    cin >> tree[i+N];
  }

  init();

  cin >> Q;
  for(int i = 0 ; i < Q; i ++){
    int t, a, b;
    cin >> t >> a >> b;
    if(t == 1){
      update(a-1, b);
    } else {
      cout << find(a-1, b) << "\n";
    }
  }

  return 0;
}
