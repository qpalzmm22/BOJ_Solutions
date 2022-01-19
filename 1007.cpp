#include <iostream>
#include <stdio.h>
#include <vector>
#include <cmath>

#define MAX 1e9
#define pii pair<int, int>

using namespace std;

pii dist[25][25];
int T, N;

int visited[25];
pii que[25];

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
double solve(int indth, double toty, double totx){
  double minDist = MAX;
  double res;//double toty = 0;
  if((N/2) == indth){
    res = sqrt(toty * toty + totx * totx); 
    //cout << "res : " << res << "\n";
    return res; 
  }
  int pivot;
  for(int i = 0; i < N; i++){
    if(!visited[i] ){
      visited[i] = 1;
      pivot = i;
      break;
    }
  }

  for(int i = 0; i < N; i++){
    if(visited[i])
      continue;

    visited[i] = 1;
    //cout << indth << " | " <<  pivot << " | " << i <<  "\n";
    minDist = min(minDist, solve(indth+1, toty + dist[pivot][i].first, totx + dist[pivot][i].second));
    if(indth != 0)
      minDist = min(minDist, solve(indth+1, toty + dist[i][pivot].first, totx + dist[i][pivot].second));
    visited[i] = 0;
  }
  visited[pivot] = 0;

  return minDist;
}


int main(){
  cin >> T;

  while(T--){
    vector<pii > p;
    cin >> N;
    for(int i = 0; i < N; i++){
      int x, y;
      cin >> x >> y;
      p.push_back(make_pair(y,x));
    }
    double minVec = MAX;
    
    for(int i = 0; i < N; i++){
      int toty = 0;
      int totx = 0;
      double length;
      for(int j = 0; j < N; j++){
        if(i == j){
          dist[i][j].first = 0;
          dist[i][j].second = 0;
        } else if(i < j){
          dist[i][j].first = p[j].first - p[i].first; 
          dist[i][j].second = p[j].second - p[i].second; 
        } else{
          dist[i][j].first = -dist[j][i].first;
          dist[i][j].second = -dist[j][i].second;
        }
      }
    }
    //printDist();
    //cout << "solve : " << solve(0);
    printf("%.12f\n",solve(0, 0, 0));
  }
  return 0;
}
