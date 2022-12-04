#include <iostream>
#include <queue>
#include <string.h>

#define pii pair < int, int >

using namespace std;
int TC;
int h;
int w;
int keys[26];

int dx[4] = { -1, 0, 1, 0}; // left down right up
int dy[4] = { 0, 1, 0, -1};
char map[105][105];



void printMap(){
  cout << "-- \n";
  for(int i = 0; i < h+2; i++){
    for(int j = 0; j < w+2; j++){
      cout << map[i][j] << " ";
    }
    cout << "\n";
  }
}

int bfs(){
 
  queue< pii > q;
  vector< pii > doors[26];
  int docs = 0;

  q.push(make_pair(0,0));

  while(!q.empty()){

    int y =  q.front().first;
    int x =  q.front().second;
    q.pop();

    if(map[y][x] == '*')
      continue;
    //cout << "(" << y << ", " << x << ") \n";
    if(map[y][x] >= 'A' && map[y][x] <= 'Z'){ // door
      if(!keys[map[y][x] - 'A']){ // if key doesnt exist 
        doors[map[y][x]-'A'].push_back(make_pair(y,x));
        continue;
      }
    }

    if(map[y][x] >= 'a' && map[y][x] <= 'z'){ //  key
      for(int i = 0 ; i < doors[map[y][x] - 'a'].size(); i++){
        q.push(doors[map[y][x] - 'a'][i]);
      }
      keys[map[y][x] - 'a'] = 1; 
    }

    
    if(map[y][x] == '$'){
      docs++;
    } 

    map[y][x] = '*';

    for(int i = 0; i < 4; i++){
      int x1 = x + dx[i];
      int y1 = y + dy[i];
      if(x1 < 0 || y1 < 0 || x1 > w + 2 || y1 > h + 2 || map[y1][x1] == '*')
        continue;

      q.push(make_pair(y1,x1));
    }
   //`` printMap();
  }
  return docs;
}

void resetKeys(){
    for(int i = 0 ; i < 26; i++){
      keys[i] = 0;
    }
}

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  cin >> TC;
  while(TC--){
    resetKeys();
    cin >> h >> w;
    string str;

    memset(map, 0, sizeof(map));
    for(int i = 1; i <= h; i++){
      cin >> str;
      for(int j = 1; j <= w; j++){
        map[i][j] = str[j-1];
      }
    }
    
    cin >> str;
    if(str[0] != '0'){
      for(int i = 0 ; i < str.length(); i++){
        //cout << "Str "  << str << "\n";
        keys[str[i] - 'a'] = 1;
      }
    }
    cout << bfs() << "\n"; 
  }
  return 0;
}
