#include <iostream>
#include <vector>


using namespace std;

int N, Q, R;
vector<int> adj [100005];
vector<int> children [100005];
int dp[100005];

/* without code below it gets t/o...
 * cin.tie(0);
ios_base::sync_with_stdio(0);
*/
void makeTree(int root, int parent){
  for(int i = 0 ; i < adj[root].size(); i++){
    int u = adj[root][i];
    if(u == parent) continue;

    children[root].push_back(u);
    makeTree(u, root);
  }
}

int countTree(int root){
  if(dp[root])
    return dp[root];

  int tot = 0;
  for(int i = 0 ; i < children[root].size(); i++){
    tot += countTree(children[root][i]);
  }
  dp[root] = tot+1;
  return dp[root];
}

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);

  cin >> N >> R >> Q;
  
  for(int i = 0 ; i < N -1; i++){
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  makeTree(R, -1);

  for(int i = 0; i < Q; i++){
    int q;
    cin >> q;
    cout << countTree(q) << "\n";
  }

  return 0;
}
