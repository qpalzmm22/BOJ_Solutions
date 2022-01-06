#include <iostream>

using namespace std;


int map[2][100005];
int dp[2][100005];

int bfs(int cur, int ind){
    
    if(dp[cur][ind] != -1){
        return dp[cur][ind];
    }

    int p1 = bfs(cur ^ 1, ind + 2);
    int p2 = bfs(cur ^ 1, ind + 1);
    
    dp[cur][ind] = map[cur][ind] + max(p1,p2);
    return dp[cur][ind];
}

void setDP(int N, int val){
    for(int i=0; i<N; i++){
        dp[0][i] = val; 
        dp[1][i] = val;
    }
}

void printDP(int N){
    cout << "---PDP\n";
    for(int n = 0; n < 2; n++){
        for(int i = 0; i < N; i++){
            cout << dp[n][i] << " ";
        }
        cout << "\n";
    }
    cout << "===PDP\n";
}

int main(){
    int T;

    cin >> T;
    int N;
    while(T--){
        cin >> N;

        setDP(N, -1);
        for(int n = 0; n < 2; n++){
            map[n][0] = 0;
            for(int i = 0; i < N; i++){
                cin >> map[n][i];
            }
        }
        
        int p1 = bfs(0,0);
        int p2 = bfs(1,0);
        //printDP(N);
        cout << max(p1, p2) << "\n";
        setDP(N, 0);
    }

    return 0;
}