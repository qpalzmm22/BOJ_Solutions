#include <iostream>

#define pii pair<int,int>

using namespace std;

pii items[105]; // weight, value

int dp[100005][105];


int main(){
    int N, K;
    int W, V;
    cin >> N >> K;
    for(int i = 1 ; i <= N; i++){
        cin >> W >> V;
        items[i] = make_pair(W, V);
    }

    // for(int i = 0 ; i <= K; i++){
    //     dp[i][0] = 0;
    // }

    for(int i = 1; i <= N; i++){
        //dp[0][i] = 0;
        for(int w = 1; w <= K; w++){
            if(items[i].first <= w){
                if(dp[w-items[i].first][i-1] + items[i].second > dp[w][i - 1]){
                    dp[w][i] = dp[w-items[i].first][i-1] + items[i].second;
                } else {
                    dp[w][i] = dp[w][i-1];
                }
            } else{
                dp[w][i] = dp[w][i-1]; 
            }
        }
    }

    // for(int i = 0; i<= K; i++){
    //     for(int j = 0; j<= N; j++){
    //         cout << dp[i][j] << " "; 
    //     }
    //     cout << "\n";
    // }

    cout << dp[K][N];


    return 0;
}