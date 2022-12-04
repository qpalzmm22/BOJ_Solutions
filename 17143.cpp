#include <iostream>
#include <map>
#include <vector>
#define pii pair < int , int >

int dy[5] = {0, -1, 1, 0, 0};
int dx[5] = {0, 0, 0, 1, -1};

using namespace std;

int R,C, M;

//shark 
struct Shark
{
  int r; // y
  int c; // x
  int s; // speed
  int d; // dir
  int z; // size
};

map < int, Shark > sharks;

int sharkMap[2][105][105]; // 0 : curMap, 1: nextMap;


pii calcNextPosition(int moment, int curPos, int dir, int maxWidth){
  int rem = moment % (maxWidth * 2);
  if(dir == 0 )
    return make_pair(curPos, dir);
  
  if(dir > 0){
    if((maxWidth - curPos) * 2 < rem){
      return calcNextPosition(rem - (maxWidth - curPos) * 2, curPos, -1 * dir, maxWidth);
    } else if (maxWidth - curPos < rem){
      return make_pair(maxWidth - (rem - maxWidth + curPos) , -1 *dir);
    } else{
      return make_pair(curPos + rem, dir);
    }
  } else {
    if(curPos * 2 < rem){
      return calcNextPosition(rem - (curPos * 2), curPos, -1 * dir, maxWidth);
    } else if (curPos < rem){
      return make_pair(rem - curPos, -1 * dir);
    } else {
      return make_pair(curPos - rem, dir);
    }
  }
}


void printShark(Shark sh){
  printf("(%d, %d), speed : %d, dir : %d, size : %d\n", sh.r, sh.c, sh.s, sh.d, sh.z);
}
void printMap(int p){
  for(int i = 0 ; i < R; i++){
    for(int j = 0 ; j < C; j++){
      cout << sharkMap[p][i][j] << " ";
    }
    cout << "\n";
  }
}
int main(){
  cin >> R >> C >> M;


  for(int i = 1 ;  i <= M;  i++){
    int r,c,s,d,z;

    cin >> r >> c >> s >> d >> z;
    Shark sh;
    sh.r = r - 1;
    sh.c = c - 1;
    sh.s = s;
    sh.d = d;
    sh.z = z;
    sharks.insert(make_pair(i, sh));
    sharkMap[0][r-1][c-1] = i;
  }

  int fisher = 0;
  int tot = 0;
  
  while(fisher < C){
    int cur = fisher % 2;
    int next = (cur + 1) % 2;
    //cout << cur << " " << next << "\n";
    // catch shark
    for(int i = 0 ; i < R; i++){
      if(sharkMap[cur][i][fisher]){
        int shark_idx = sharkMap[cur][i][fisher] ;
        //printShark(sharks[shark_idx]);
        tot += sharks[shark_idx].z;
        sharks.erase(shark_idx);
        sharkMap[cur][i][fisher] = 0;
        break;
      }
    }
    // move shark
    for(auto itr = sharks.begin(); itr != sharks.end();){
      int idx = itr->first;
      Shark sh = itr->second;
      //cout << "> idx " << idx << "\n";
      //cout << "pos : " << sh.r << " "<< sh.c << "\n";
      //printShark(sh);

      pii nextx_dir = calcNextPosition(sh.s, sh.c, dx[sh.d], C-1);
      pii nexty_dir = calcNextPosition(sh.s, sh.r, dy[sh.d], R-1);
      
      int nextx = nextx_dir.first;
      int nexty = nexty_dir.first;

      // new direction
      for(int i = 1; i < 5; i++){
        if(dy[i] == nexty_dir.second && dx[i] == nextx_dir.second)
          // assign
          sh.d = i;
      }

      //cout << "nexts : "<< nexty << " "<< nextx << " \n";
      sharkMap[cur][sh.r][sh.c] = 0;
      
      // assign
      sh.r = nexty;
      sh.c = nextx;
      itr->second = sh;
      
      if(sharkMap[next][nexty][nextx]){
        //cout << "eating\n";
        int existing_shark_idx = sharkMap[next][nexty][nextx];
        Shark existing_shark = sharks[existing_shark_idx];
        
        //cout << "> existing_shark_idx " << existing_shark_idx << "\n";
        //printShark(existing_shark);
        
        if(existing_shark.z > sh.z){
          sharks.erase(itr++);
        } else {
          sharks.erase(existing_shark_idx);
          sharkMap[next][nexty][nextx] = idx;
          ++itr;
        }
      }else {
        sharkMap[next][nexty][nextx] = idx;
        ++itr;
      }
    } 
    //cout << "next map : \n";
    //printMap(next);
    fisher++;
  }
  cout << tot;

  return 0;
}
