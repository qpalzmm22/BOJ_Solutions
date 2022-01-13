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

    int prev = -1;

    for(int i = numth; i < N; i++){
      if(prev != -1 && val[i] == val[prev]){
        continue;
      }
      
      arr[indth] = val[i];
      if(val[numth] == val[i])
        dfs(numth, indth+1);
      else
        dfs(i, indth+1);
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

  dfs(0, 0);

  return 0;
}
