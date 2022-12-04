#include <iostream>
#include <algorithm>

int N, M;

int list1[500005];
int list2[500005];

using namespace std;

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  cin >> N;
  for(int i = 0; i < N; i++){
    cin >> list1[i];
  }
  cin >> M;
  sort(list1, list1 + N);
  
  for(int i = 0; i < M; i++){
    int num;
    cin >> num;
    cout << upper_bound(list1, list1 + N, num) - lower_bound(list1, list1 + N, num) << " ";
  }


  return 0;
}
