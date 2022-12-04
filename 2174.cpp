#include <iostream>
#include <vector>

#define pii pair < int, int > 

using namespace std;

int map[105][105];

int A, B;
int N, M; // N : robots, M : actions

// inc : clockwise from N -> E -> S -> W
// dec : N -> W -> S -> E
int dy[4] = {1, 0, -1, 0} ;
int dx[4] = {0, 1, 0, -1} ;


vector < int > robots_dir; // N : 0, E : 1, S : 2, W : 3
vector < pii > robots;

void printmap(){
  cout << "\n";
  for(int i = B ; i > 0; i--){
    for(int j = 1 ; j <= A; j++){
      cout << map[i][j] << " ";
    } 
    cout << "\n";
  }
}
int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  cin >> A >> B;
  cin >> N >> M;

  for(int i = 0 ; i < N; i++){
    int x, y ;
    char dir;

    cin >> x >> y >> dir;
    robots.push_back(make_pair(x, y));
    if(dir == 'N')
      robots_dir.push_back(0);
    if(dir == 'E')
      robots_dir.push_back(1);
    if(dir == 'S')
      robots_dir.push_back(2);
    if(dir == 'W')
      robots_dir.push_back(3);
    map[y][x] = i + 1;
  }

  for(int i = 0 ; i < M; i++){
    int idx;
    char action;
    int rep;

    cin >> idx >> action >> rep;
    
    int dir = robots_dir[idx-1];

    if(action == 'L'){
      for(int j = 0 ; j < rep; j++){
        dir = dir - 1;
        if(dir == -1) dir = 3;
      }
      robots_dir[idx-1] = dir;
    } else if(action == 'R') {
      for(int j = 0 ; j < rep; j++){
        dir = dir + 1;
        if(dir == 4) dir = 0;
      }
      robots_dir[idx-1] = dir;
    } else {
      for(int j = 0 ; j < rep; j++){
        int x = robots[idx-1].first;
        int y = robots[idx-1].second;
        int nextx = x + dx[dir] ;
        int nexty = y + dy[dir] ;

        //printmap();
        //cout << nexty << " " << nextx << " "<< x << " "<< y << "\n";
          
        if(map[nexty][nextx]){
          cout << "Robot " << idx << " crashes into robot " << map[nexty][nextx] ;
          return 0;
        }

        if(nexty == 0 || nextx == 0 || nexty > B || nextx > A){
          cout << "Robot " << idx << " crashes into the wall";
          return 0;
        }
        map[y][x] = 0;
        map[nexty][nextx] = idx;
        robots[idx-1].first = nextx;
        robots[idx-1].second = nexty;

      }
    }
  }
  cout << "OK\n";

  return 0;
}
