#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M, K;

// First Thought : it;'s jsut greedy..?
// use sort, and bin search (lower_bound)  => NlgN + KlgN
// NO : vector erase could take O(N) in worst case so actually the time
// complextiy becomes NlgN + K(lgN+N)
//

// New : O(NlgN + N + ka(n))
int p[4000005];

int find(int a){
  if(p[a] == a)
    return a;
  else
    return p[a] = find(p[a]);
}

void uni(int a, int b){
  int u = find(a);
  int v = find(b);

  if(u > v)
    swap(u, v);
  p[u] = v;
}

vector < int > minsu;

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);

  cin >> N >> M >> K;

  for(int i = 1 ; i <= N + 1; i++){
    p[i] = i ;
  }

  minsu.push_back(0);

  for(int i = 1 ; i <= M ; i++){
    int val;
    cin >> val;
    minsu.push_back(val);
  }

  sort(minsu.begin(), minsu.end());
 
  // K * (NlgN + lgN)
  for(int i = 0 ; i < K ; i++){
    int q ;
    cin >> q;
    auto it = lower_bound(minsu.begin(), minsu.end(), q+1);
    int idx = it - minsu.begin() ;
    //cout << idx << " " << minsu[find(idx) -1] << "\n";
    int nextidx = find(idx);
    cout << minsu[nextidx] << "\n";
    
    uni(nextidx, nextidx + 1);
  }
  return 0;
}
