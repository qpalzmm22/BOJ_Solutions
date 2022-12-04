#include <iostream>
#include <queue>

#define pii pair < int, int > // sec, num
using namespace std;

int N, K ;

deque < pii > dq;

bool visited[200005];

void zero_one_bfs(){

  dq.push_back(make_pair(0, N));
  while(!dq.empty()){

    int sec = dq.front().first;
    int num = dq.front().second;
    dq.pop_front();
    
    //cout << sec << " " << num << "\n";

    if( num == K ){
      cout << sec ;
      return ;
    }

    if(visited[num])
      continue;

    visited[num] = true;
    
    if(num * 2 < 200000)
      dq.push_front(make_pair(sec, num * 2));
    
    if(num - 1 >= 0)
      dq.push_back(make_pair(sec + 1, num - 1));
    
    if(num + 1 <= 100000)
      dq.push_back(make_pair(sec + 1, num + 1));
  }
}

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  cin >> N >> K;

  zero_one_bfs();

  return 0;
}
