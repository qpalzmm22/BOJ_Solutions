#include <iostream>
#include <queue>
#include <tuple>

using namespace std;
#define INF 2e9

char map[1005][1005]; // 0 : possible 1: wall
int dpmap[2][1005][1005]; // 1002 * 1002;

bool visited[2][1005][1005]; // 0 : hammer off, 1: hammer on


int dy[4] = {-1, 0, 1, 0}; // up ,right, down, left
int dx[4] = {0, 1, 0, -1}; // up ,right, down, left

int bfs(int y, int x, int N, int M){
    int vy;
    int vx;

    queue< tuple<int,int,bool> > q;
    q.push(make_tuple(y, x, true));
    visited[1][y][x] = true;

    while(!q.empty()){ 
        int xt = get<1>(q.front());
        int yt = get<0>(q.front());
        bool hammer = get<2>(q.front());
        int v = hammer?1:0; // false => used hamer

        q.pop();
        //cout << "Q : [" << yt << " "<< xt << " "<< hammer <<"]\n";
        if(yt == N && xt == M){
            return hammer;
        }
        for(int i = 0; i < 4; i++){
            vy = yt + dy[i];
            vx = xt + dx[i];

            if(vy == 0 || vx == 0 || vy == N+1 || vx == M+1)
                continue;

            //cout << "[Q : [" << vy << " "<< vx << " "<< hammer <<"]]\n";   
            if(map[vy][vx] == 0){ 
                if(!visited[v][vy][vx]){
                    q.push(make_tuple(vy, vx, hammer));
                    dpmap[v][vy][vx] = dpmap[v][yt][xt] + 1;
                    visited[v][vy][vx] = true;
                }
            } else if(map[vy][vx] == 1 && hammer ){ // have hammer and met wall
                if(!visited[v][vy][vx]){
                    q.push(make_tuple(vy, vx, false));
                    dpmap[0][vy][vx] = dpmap[1][yt][xt] + 1;
                    visited[0][vy][vx] = true;
                }
            }
            // if(vy == N && vx == M)
            //     return hammer; 
        }
    }
    return -1;
}

void printMap(int N, int M){
    for(int i = 0; i <= N+1; i++){
        for(int j = 0; j <= M+1; j++){
            cout << map[i][j] << " ";
        }
        cout << "\n";
    }
}

void printdpMap(int N, int M){
    for(int v = 0; v < 2; v++){
        for(int i = 0; i <= N+1; i++){
            for(int j = 0; j <= M+1; j++){
                printf("%2d ", dpmap[v][i][j]);
            }
            cout << "\n";
        }
        cout << "---------------\n";
    }
}

int main(){

    int N, M;
    cin >> N >> M;

    for(int i = 0; i <= N + 1; i++){
        string s;
        if(i != 0 && i != N + 1)
            cin >> s;
        for(int j = 0; j <=  M + 1; j++){
            //dpmap[i][j] = INF;
            if(i == 0 || j == 0 || i == N + 1|| j == M + 1){
                map[i][j] = 1; // 
                //dpmap[i][j] = INF;
            } else{
                map[i][j] = s[j-1] - '0';
                
            }
        }
    }

    //dpmap[0][1][1] = 1;
    //dpmap[1][1][1] = 1;
    dpmap[1][1][1] = 1;
    dpmap[0][1][1] = 1;


    int hammer = bfs(1,1, N, M);
    
    //printMap(N, M);
    //printdpMap(N, M);
    // if(map[N][M] == 2){
    //     cout << dpmap[N][M];
    // } else{
    //     cout << -1;
    // }
    if(hammer == -1){
        cout << -1;
    } else {
        cout << dpmap[hammer][N][M];
    }
    return 0;
}
