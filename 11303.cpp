#include <iostream>

#define INF 10000005

using namespace std;

int V[105][105];

int main(){
    int N, M;
    cin >> N >> M;

    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            V[i][j] = INF;
            if(i == j)
                V[i][j] = 0;

        }
    }

    while(M--){
        int i, j;
        int cost; 
        cin >> i >> j >> cost;

        V[i][j] = min(V[i][j], cost);
    }

    // FLOYD
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            for(int k = 1; k <= N; k++){
                if(V[j][k] > V[j][i] + V[i][k])
                    V[j][k] = V[j][i] + V[i][k];
            }
        }
    }

    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            if(V[i][j] >= INF)
                cout << 0 << " ";
            else 
                cout << V[i][j] << " ";
            
        }
        cout << "\n";
    }

    return 0;
}