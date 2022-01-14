#include <iostream>
#include <vector>
#include <cmath>

#define MAX 1e9
#define pii pair<int, int>

using namespace std;

pii dist[25][25];
int T, N;

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
        toty += dist[i][j].first;
        totx += dist[i][j].second;
      }
      length = sqrt(toty * toty + totx * totx);
      minVec = min(minVec, length);
    }
    cout << minVec << "\n";
  }
  return 0;
}
