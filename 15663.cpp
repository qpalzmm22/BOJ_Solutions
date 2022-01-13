#include <iostream>
#include <algorithm>

using namespace std;

int N, M;

int arr[10];
int visited[10];
int val[10];

void dfs(int indth){
  if(indth == M){
    for(int i = 0; i < M; i++){
      cout <<  arr[i] << " ";
    }
    cout << "\n";
  } else {

    int prev = -1;

    for(int i = 0; i < N; i++){
      if(prev != -1 && val[i] == val[prev] || visited[i]){
        continue;
      }
      
      visited[i] = 1;
      arr[indth] = val[i];
      dfs(indth+1);
      visited[i] = 0;
      prev = i;
    }
  }
}

int main(){
  cin >> N >> M;

  for(int i=0; i < N; i++){
    cin >> val[i] ;
  }
  sort(val, val + N);

  dfs(0);

  return 0;
}
