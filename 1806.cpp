#include <iostream>
#define MAX 100005

using namespace std;
int N, S;
int map[MAX];
int sum[MAX];

int main(){
  cin >> N >> S;

  int tot = 0;

  int res = MAX;
  int j = 0;
  for(int i = 0; i < N; i++){
    cin >> map[i];
    sum[i] = tot + map[i];
    tot = sum[i];
    int shortest = MAX ;

    if(sum[i] >= S){
      while(sum[i] - sum[j] >= S && j < i){
        j++;
      }
    shortest = i - j + 1;
    }
    res = min(shortest, res);
  }
  if(res == MAX)
    cout << 0;
  else 
    cout << res;
  return 0;
}
