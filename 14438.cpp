#include <iostream>
#include <vector>
#define MX 2e9
using namespace std;

//int arr[100005 * 2];
int seg_tree[100000 << 2];

int N;

void printSeg(){
  for(int i = 1 ; i <= 2*N ; i++){
    cout << seg_tree[i] << " ";
  }
}
// find min
int update(int cur, int target, int val, int l_bound, int r_bound){
  int ret = MX;
  
  if(l_bound > target || r_bound < target ) return seg_tree[cur];
  
  int mid = (l_bound + r_bound) / 2;

  if(l_bound == r_bound){
    seg_tree[cur] = val;
    return val;
  } else {
    ret = min(ret, update(cur*2, target, val, l_bound, mid));
    ret = min(ret, update(cur*2+1, target, val, mid+1, r_bound));
  }

  seg_tree[cur] = ret;
  return ret;
}

int find_min(int cur, int l, int r, int l_bound, int r_bound){
  //cout << "cur : "  << cur << " " << l << " " << r << " " << l_bound << " " << r_bound << " " << "\n";
  int val = MX;
  if(l_bound > r || r_bound < l) return MX;

  if(l <= l_bound && r_bound <= r) return seg_tree[cur];
  
  int mid = (l_bound + r_bound) / 2;
  val = min(find_min(cur * 2, l, r, l_bound, mid), val);
  val = min(find_min(cur * 2 + 1, l, r, mid + 1, r_bound), val);
  

  //cout << "cur : "  << cur << " " << l << " " << r << " " << l_bound << " " << r_bound << " " << val << "\n";

  return val;
}

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);

  cin >> N;

  for(int i= 1; i <=  (N << 2); i++){
    seg_tree[i] = MX;
  }

  for(int i = 1; i <= N ; i++){
    int a;
    cin >> a;
    //arr[i] = a;
    update(1, i, a, 1, N);
  }
  //printSeg();

  int Q;
  cin >> Q;
  for(int i = 0 ; i < Q; i++){
    int t, a, b;
    cin >> t >> a >> b;
    if(t == 1){
      update(1, a, b, 1, N);
      //printSeg();
    } else {
      cout << find_min(1, a, b, 1, N) << "\n";
    }
  }




  return 0;
}
