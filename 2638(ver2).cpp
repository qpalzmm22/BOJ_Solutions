#include <iostream>

#define pii pair<int,int>

// How to seperate outer air from inner air?
// sol1:
// make them nodes and see if it creates a loop => (x) hard to implement
// sol 2 :
// union find 0s and for ones, find parent


using namespace std;



int dy[4] = {-1, 0, 1, 0}; // up left down right
int dx[4] = {0, -1 , 0, 1};
int cheesCount = 0;

int map[105][105]; // 0 : none, 1 : cheese, {2: outer air, 3: inner air} 

void bfs(int x, int y, int N, int M){  

    map[y][x] = -1;

    for(int i = 0; i < 4; i++){
        int vx = x + dx[i];
        int vy = y + dy[i];
        
        if(vy < 0 || vy == N || vx < 0 || vx == M){
            continue;
        }
        
        if(map[vy][vx] == 0)
            bfs(vx, vy, N, M);
        if(map[vy][vx] > 0){
            map[vy][vx]++;
        }
    }
}

void passDay(int N, int M){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(map[i][j] == -1 ){
                map[i][j] = 0;
            } else if(map[i][j] == 2){
                map[i][j] = 1;
            } else if(map[i][j] > 2){
                map[i][j] = 0;
                cheesCount--;
            }
        }
    }
}

void pm(int N, int M){
    cout << "--------------------------------\n";
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cout << map[i][j];
        }
        cout << "\n";
    }
}

int main(){
    int N, M;

    cin >> N >> M;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            int c;
            cin >> c;
            map[i][j] = c;
            if(c == 1)
                cheesCount++;
        }
    }
    //pm(N, M);

    int hour = 0;
    while(cheesCount > 0){
        bfs(0,0,N,M);
        passDay(N, M);
        //pm(N, M);
        hour++;
    }
    

    cout << hour;
    return 0;
}