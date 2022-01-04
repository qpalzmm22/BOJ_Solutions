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

int map[105][105];

pii parent[105][105];


pii find(pii a){
    if(parent[a.first][a.second] == a)
        return a;
    else 
        return find(parent[a.first][a.second]);
}

void uni(pii a, pii b){
    pii pa = find(a);
    pii pb = find(b);
    parent[b.first][b.second] = pa;
    parent[pb.first][pb.second] = pa;

}

void pm(int N, int M){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cout << map[i][j];
        }
        cout << "\n";
    }
}

void ppm(int N, int M){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cout << "[" << parent[i][j].first << " " << parent[i][j].first << "]";
        }
        cout << "\n";
    }
}

void groupify(int N, int M){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            for(int k = 0; k < 4; k++){
                int vy = i + dy[k];
                int vx = j + dx[k];

                if(vy < 0 || vy == N || vx < 0 || vx == M){
                    parent[i][j] = make_pair(-1, -1);
                    continue;
                }

                if(map[i][j] == 0)

            }
        }
    }
}

void initParent(int N, int M){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            parent[i][j] = make_pair(i, j);
        }
    }
}

int main(){
    int N, M;

    cin >> N >> M;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            char c;
            cin >> c;
            map[i][j] = c;
        }
    }

    pm(N, M);
    ppm(N, M);
    return 0;
}