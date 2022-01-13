#include <iostream>
#include <algorithm>

using namespace std;

int N, M;

int arr[10];
int visited[10];
int val[10];

void dfs(int numth, int indth){
  if(indth == M){
    for(int i = 0; i < M; i++){
      cout <<  arr[i] << " ";
    }
    cout << "\n";
  } else {
    for(int i = 0; i < N; i++){
      if(!visited[i]){
        arr[indth] = val[i];
        visited[i] = 1;
      } else {
        continue;
      }
      dfs(i+1, indth+1);
      visited[i] = 0;
    }
  }
}

int main(){
  cin >> N >> M;

  for(int i=0; i < N; i++){
    cin >> val[i] ;
  }
  sort(val, val + N);

  dfs(0, 0);

  return 0;
}
