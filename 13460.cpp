#include <iostream>
#include <queue>
#define pii pair < int, int >
#define ppii pair < pii, pii > // <blue, red>
#define pppii pair < ppii, int > // ppii, int
#define NOP make_pair(make_pair(-1,-1), make_pair(-1,-1))
#define GOAL make_pair(make_pair(-1,-2), make_pair(-1,-2))

using namespace std;

int dy[4] = {-1, 0, 1 , 0}; // left up right down
int dx[4] = {0, -1, 0 , 1};

bool visited[12][12][12][12]; // blue , red

pii B;
pii R;
pii G; // goal

int N, M;

char map[12][12];

void printmap(){
  for(int i = 0 ; i < N; i++){
    for(int j = 0 ; j < M; j++){
      cout << map[i][j] << " ";
    }
    cout << "\n";
  }
}

ppii move_to_end(int dir, pii blue, pii red){

  
  int bx = blue.first; // next x
  int by = blue.second; // next x
  int rx = red.first;
  int ry = red.second;


  //cout << " MTE (" <<  dir  <<  ") ["<< rx << " "<< ry << "] [" << bx << " " << by << "]\n";
  
  if(blue == red){
    return make_pair(blue, red);
  }

  if(blue == G)
    return NOP;

  if(red == G){
    if(move_to_end(dir, blue, make_pair(-1,-1)) == NOP)
      return NOP;
    return GOAL;
  }

  int possbx = bx + dx[dir];
  int possby = by + dy[dir];
  int possrx = rx + dx[dir];
  int possry = ry + dy[dir];
  
  int nextbx = bx;
  int nextby = by;
  int nextrx = rx;
  int nextry = ry;
  
  // Move Blue first
  //cout << " possbx ["<< possbx << " "<< possby << "] [" << rx << " " << ry << "]\n";

  
  //printmap();

  if(make_pair(possbx, possby) != red && possby > 0 && possbx > 0 && possby < N && possbx < M  && map[possby][possbx] != '#') {
    nextbx = possbx;
    nextby = possby;
  }

  if(make_pair(possrx, possry) != blue && possry > 0 && possrx > 0 && possry < N && possrx < M && map[possry][possrx] != '#') {
    nextrx = possrx;
    nextry = possry;
  }

  pii nextblue = make_pair(nextbx, nextby);
  pii nextred = make_pair(nextrx, nextry);

  if(nextblue == blue && nextred == red){
    return make_pair(nextblue, nextred);
  }

  //cout << " MTEE (" <<  dir  <<  ") ["<< nextrx << " "<< nextry << "] [" << nextbx << " " << nextby << "]\n";
  return move_to_end(dir, nextblue, nextred);
}

void bfs(){
  queue<pppii> q;
  q.push(make_pair(make_pair(B, R), 1));

  while(!q.empty()){
    pii blue = q.front().first.first;
    pii red = q.front().first.second;
    int count = q.front().second;
    q.pop();
  
    int bx = blue.first; // next x
    int by = blue.second; // next x
    int rx = red.first;
    int ry = red.second;
    
    if(visited[bx][by][rx][ry])
      continue;

    visited[bx][by][rx][ry] = true;
    //cout << "["<< rx << " "<< ry << "] [" << bx << " " << by << "]\n";
    for(int i = 0 ; i < 4; i++){
      
      ppii res = move_to_end(i, blue, red);
      if(res == GOAL){
        cout << count ;
        return;
      }
      if(res == NOP){
        continue;
      }
      if(blue == res.first && red == res.second)
        continue;
      if(count == 10)
        continue;
      q.push(make_pair(res, count + 1));
    }
  }
  cout << "-1\n";
}



int main(){

  cin >> N >> M;

  for(int i = 0; i < N; i++){
    string str;
    cin >> str;
    for(int j = 0; j < M; j++){
      map[i][j] = str[j];
      if(str[j] == 'R') R = make_pair(j,i);
      if(str[j] == 'B') B = make_pair(j,i);
      if(str[j] == 'O') G = make_pair(j,i);
    }
  }

  bfs();
  return 0;
}
