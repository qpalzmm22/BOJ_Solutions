#include <iostream>
#include <queue>

#define pii pair<int, int>

using namespace std;
int hd
int w;
int keys[26];
queue< pii > q;

int dx[4] = { -1, 0, 1, 0};
int dy[4] = { 0, 1, 0, -1};
char map[105][105];

void printMap(){
  for(int i = 0; i < h; i++){
    for(int j = 0; j < w; j++){
      cout << map[i][j] << " ";
    }
    cout << "\n";
  }
}

void solve(){
  for(int i = 0; i < h; i++){
    for(int j = 0; j < w; j++){
      if(i == 0 || j == 0 || i == h - 1 || j == w - 1 ){
        if(map[i][j] != '*'){
          q.enqueue(make_pair(i, j));
        }
      }
    }
  }
  bfs();
}
int bfs(){
  int docs = 0;
  while(!q.empty()){
    int y =  q.front().first;
    int x =  q.front().second;
    q.pop();

    if(map[y][x] >= 'A' && map[y][x] <= 'Z'){
      q.enqueue(make_pair(y,x));
    }
    for(int i = 0; i < 4; i++){
      x += dx[i];
      y += dy[i];
      if(x < 0 || y < 0 || x >= w || y >= h || map[y][x] == "*")
        continue;

      if(map[y][x] == '$'){
        docs++;
      } 
      q.enqueue(make_pair(y,x));
    }
    if(q.empty() && !doorQ.empty()){
      doorQ.
    }
  }
}

void resetKeys(){
    for(int i = 0 ; i < 26; i++){
      keys[i] = 0;
    }
}

int main(){
  cin >> TC;
  while(TC--){
    cin >> h >> w;
    string str;
    int i = 0;
    while(i < h){
      cin >> str;
      for(int j = 0; j < w; j++){
        map[i][j] = str[j];
      }
      i++;
    }
    cin >> str;
    if(str[0] != '0'){
      for(int i = 0 ; i < str.length(); i++){
        cout << "Str "  << str << "\n";
        keys[str[i] - 'a'] = 1;
      }
    }

    printMap();
  }
  return 0;
}
