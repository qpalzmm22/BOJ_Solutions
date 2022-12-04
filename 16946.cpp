#include <iostream>
#include <queue>
#include <set>

#define pii pair < int, int > 

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, -1, 0, 1};

using namespace std;

bool visited[1005][1005];
int groups[1005][1005];
int w[1005*1005]; // empty spaces per group 
int map[1005][1005];
int group_num = 1;

int N, M;

void printGroups(){
  for(int i = 0 ; i < N; i++){
    for(int j = 0; j < M; j++){
      cout << groups[i][j] << " ";
    }
    cout << "\n";
  }
}

// returns empty spots
int bfs(int i, int j, int group){

  int tot = 0;
  queue< pii > q;
  q.push(make_pair(i, j));
  visited[i][j] = 1;

  while(!q.empty()){
    int y = q.front().first;
    int x = q.front().second;
    q.pop();

    groups[y][x] = group;
    tot++;

    for(int dir = 0 ;  dir < 4;  dir++){
      int nextx = x + dx[dir];
      int nexty = y + dy[dir];

      if(nextx < 0 || nexty < 0 || nextx >= M || nexty >= N )
        continue;

      if(map[nexty][nextx])
        continue;

      if(visited[nexty][nextx])
        continue;

      visited[nexty][nextx] = 1;

      q.push(make_pair(nexty, nextx));
    }
  }
  //cout << "tot : " << tot << "\n";
  return tot; 
}
// First Thought : get availabe space for '0' first, then solve it =
// O(n^2 +n^2)
int main()
{
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cin >> N >> M;
  
  for(int i = 0 ; i < N; i++){
    string str;
    cin >> str;
    for(int j = 0; j < M; j++){
      map[i][j] = str[j] - '0';
    }
  }
  for(int i = 0 ; i < N; i++){
    for(int j = 0; j < M; j++){
      if(!map[i][j]){
        if(visited[i][j])
          continue;
        w[group_num] = bfs(i, j, group_num);
        group_num++;
      }
    }
  }
  //printGroups();
  
  for(int i = 0 ; i < N; i++){
    for(int j = 0; j < M; j++){
      if(!map[i][j]){
        cout << 0;
        continue;
      }

      set < int > s;
      for(int dir = 0 ;  dir < 4;  dir++){
        int nextx = j + dx[dir];
        int nexty = i + dy[dir];

        if(nextx < 0 || nexty < 0 || nextx >= M || nexty >= N )
          continue;

        s.insert(groups[nexty][nextx]);
      }
      
      int total = 1;
      for(auto g : s){
        total += w[g];
        //cout << g << " " << w[g] << "\n";
      }
      cout << total % 10;
    }
    cout <<"\n";
  }

  return 0;
}
