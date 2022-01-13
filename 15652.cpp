#include <iostream>

using namespace std;

int arr[10];

int N, M;

void dfs(int num, int ind){
  if(ind == M){
    for(int i = 0; i < M; i++){
        cout << arr[i] << " ";
      }
    cout << "\n";
  } else {
    for(int i = num; i <= N; i++){
      arr[ind] = i;
      dfs(i, ind + 1);
    }
  }
}

int main(){

  cin >> N >> M;

  dfs(1, 0);

  return 0;
} 
