#include <iostream>
#include <stdio.h>
#include <vector>
#include <cmath>

#define MAX 1e9
#define pii pair<int, int>

using namespace std;

pii dist[25][25];
int T, N;

//vector<pii > vp;
pii vp[25];

int visited[25];

void printDist(){
  for(int i = 0; i < N; i++){
    for(int j = 0; j < N; j++){
      cout << " [" <<dist[i][j].first << ", " << dist[i][j].second <<"] ";
    }
    cout << "\n";
  }
}

//dfs
//double solve(int indth){
double solve(int indth, int numth){
  double toty = 0;
  double totx = 0;
  double minDist = MAX;
  double res;//double toty = 0;
  if((N/2) == indth){
    for(int i = 0; i < N; i++){
      if(!visited[i]){
        toty -= vp[i].first;
        totx -= vp[i].second;
      } else {
        toty += vp[i].first;
        totx += vp[i].second;
      }
    }

    res = sqrt(toty * toty + totx * totx); 
    //cout << "res : " << res << "\n";
    return res; 
  }

  for(int i = numth; i < N; i++){

    visited[i] = 1;
    //cout << indth << " | " <<  pivot << " | " << i <<  "\n";
    minDist = min(minDist, solve(indth+1, i + 1));
    visited[i] = 0;
  }

  return minDist;
}


int main(){
  cin >> T;

  while(T--){
    cin >> N;
    for(int i = 0; i < N; i++){
      int x, y;
      cin >> x >> y;
      vp[i] = make_pair(y, x);
    }
    double minVec = MAX;
    
    //cout << "solve : " << solve(0, 0);
    printf("%.12f\n",solve(0, 0));
  }
  return 0;
}
