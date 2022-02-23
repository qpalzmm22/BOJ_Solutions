// Similart o N - QUEENS. DFS with not processing all the squares (i forgot what
// it was called)

#include <iostream>
#include <cmath>

#define pii pair<int, int>

using namespace std;

int N;

int map[25][25]; 
int bn = 0;

pii bishops[30];

bool isdiagonal(pii a, pii b){
  int y1 = a.first;
  int x1 = a.second;
  int y2 = b.first;
  int x2 = b.second;
  if(abs(x1 - x2) == abs(y1 - y2))
    return true;
  else
    return false;
}

int dfs(int rank){

  //cout << rank << " " << bn << "\n";
  int maxBs = bn;
  if(rank > 2 * N)
    return bn;
  int x = rank;
  int y = 0;

  // no inclusion in this row
  maxBs = max(maxBs, dfs(rank + 2));
  
  for(int i = 0 ; i <= rank ; i++){
    bool flag = false;
    
    if(map[y][x] == 0){
      x--;
      y++;
      continue;
    }
    
    pii point = make_pair(y, x);
    
    for(int j = 0 ; j < bn ; j++){
      
      if(isdiagonal(bishops[j], point) == true){
        flag = true;
        break;
      }
    }
    if(flag == false){
      //cout << "[y, x] "<< y << " " << x << "\n";
      bishops[bn] = point;
      bn++;
      maxBs = max(maxBs, dfs(rank + 2));
      bn--;
    }
    x--;
    y++;
  }
  return maxBs;
}

int main(){
  cin >> N;
  for(int i = 0 ; i < N ; i++){
    for(int j = 0; j < N ; j++){
      cin >> map[i][j];
    }
  }
  cout << dfs(0) + dfs(1);
  return 0;
}
