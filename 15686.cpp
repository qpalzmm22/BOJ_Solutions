#include <iostream>
#include <vector>

#define pii pair<int, int>
#define MAX 1e9

using namespace std;

int N, M;
int map[55][55];

vector<pii > chiarr;
int arr[20]; // chicken array


int m_abs(int n){
  return (n < 0 ? -1*n:n);
}

int getDist(){// vector of pairs
  int totDist = 0;
  for(int i = 0; i < N; i++){
    for(int j = 0; j < N; j++){
      int minDist = MAX;
      if(map[i][j] == 1){
        for(int k = 0; k < M; k++){
          int y = chiarr[arr[k]].first;
          int x = chiarr[arr[k]].second;

          minDist = min(minDist, m_abs(y - i) + m_abs(x - j));
        }
        totDist += minDist;
      }
    }
  }

  return totDist;
}

int dfs(int numth, int indth){
  int minDist = MAX;
  if(indth == M){
    //for(int i = 0; i < M; i++){
    //  cout << "[" << chiarr[arr[i]].first << " "<< chiarr[arr[i]].second << "] ";
    //}
    //cout << " " << getDist() << "\n";
    return getDist();
  }
  for(int i = numth; i < chiarr.size(); i++){
    arr[indth] = i;
    minDist = min(minDist, dfs(i + 1 , indth+1));
  }
  return minDist;
}

int main(){
  cin >> N >> M;

  for(int i = 0; i<N ; i++){
    for(int j = 0; j<N; j++){
      int num;
      cin >> num;
      map[i][j] = num;
      if(num == 2){
        chiarr.push_back(make_pair(i, j));
      }
    }
  }
  cout << dfs(0, 0);

  return 0;
}
