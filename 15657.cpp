#include <iostream>
#include <algorithm>

using namespace std;

int N, M;

int arr[10];
int val[10];

void dfs(int numth, int indth){
  if(indth == M){
    for(int i = 0; i < M; i++){
      cout <<  arr[i] << " ";
    }
    cout << "\n";
  } else {
    for(int i = numth; i < N; i++){
      arr[indth] = val[i];
      dfs(i, indth+1);
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
