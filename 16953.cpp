#include <iostream>
#include <queue>

#define pii pair<int, int>

using namespace std;
int A, B;

int bfs(int n){
  queue<pii > q;
  q.push(make_pair(n, 1));
  
  while(!q.empty()){
    long long x = q.front().first;
    int op = q.front().second;
    q.pop();
    //cout << x << "in Q" << op << "\n";
    if(x == B)
      return op;

    if(x << 1 <= B)
      q.push(make_pair(x << 1, op + 1));
    if(x * 10 + 1 <= B)
      q.push(make_pair(x * 10 + 1 , op + 1));
  }
  return -1;
}

int main(){
  cin >> A >> B;

  cout << bfs(A);
  return 0;
}
