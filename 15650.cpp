#include <iostream>

using namespace std;

int iter[10];

int main(){
    int N,M;

    cin >> N >> M;

    for(int i = 0 ; i < M; i++){
      iter[i] = i+1;
    }

    while(iter[0] < N - M + 2 ){
      for(int i = 0 ; i < M ; i++){
        cout << iter[i] << " ";
      }
      
      iter[M-1]++;

      for(int i = M - 1; i > 0;i--){
        if(iter[i] >= N - M + i + 2){
          iter[i - 1]++;
        }
      }
      for(int i = 1; i < M; i++){
        if(iter[i] == N - M + i + 2){
          iter[i] = iter[i - 1] + 1;
        }
      }
      cout << "\n";
    }

    return 0;
}
