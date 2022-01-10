#include <iostream>
#include <algorithm>
#include <queue>

#define pii pair<int,int>

#define MAX 100000
#define MAXCOST 100005
#define MIN 0 

using namespace std;

pii dp[100004]; // cost, pathnum

pii bfs(int a, int b){
    queue<pii > q;

    q.push(make_pair(a, 0)); // num, cost
    dp[a] = make_pair(0,1); // cost, pathnum

    int mincost = MAXCOST;
    int var = 0;

    while(!q.empty()){
        int num = q.front().first;
        int cost = q.front().second;
        q.pop();
        
        // if(dp[num].first != -1)
        //     continue;
        //cout  << " num: " << num << "] [" << cost << " "<<  mincost << " " << dp[num].second <<"]\n";

        if(mincost < cost)
            break;

        if(num == b){
            mincost = cost;
        }
        
        if(num + 1 <= MAX){
            if(dp[num + 1].first == -1){
                q.push(make_pair(num + 1, cost + 1));
                dp[num + 1].first = cost + 1;
            }
            if(dp[num + 1].first == cost + 1)
                dp[num + 1].second += dp[num].second;

        }
        if(num - 1 >= MIN){
            if(dp[num - 1].first == -1){
                q.push(make_pair(num - 1, cost + 1));
                dp[num - 1].first = cost + 1;
            } 
            if(dp[num - 1].first == cost + 1)
                dp[num - 1].second += dp[num].second;
        
        }
        if(num * 2 <= MAX){
            if(dp[num * 2].first == -1){
                q.push(make_pair(num * 2, cost + 1));
                dp[num * 2].first = cost + 1;
            } 
            if(dp[num * 2].first == cost + 1)
                dp[num * 2].second += dp[num].second;
    
        }
        
    }
    
    return dp[b];
}

int main()
{
    int N, K;
    cin >> N >> K;
    pii result;
    for(int i = 0; i <= MAX; i++){
        dp[i].first = -1;
    }
    result = bfs(N, K);

    // if(N > K ){
    //     result = make_pair(N - K, 1);
    // } else {
    //     result = fp(N, K, K, K);
    // }
    cout << result.first << "\n" << result.second << endl;

    return 0;   
}