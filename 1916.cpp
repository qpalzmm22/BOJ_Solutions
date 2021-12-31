#include <iostream>
#include <vector>
#include <queue>

#define INF 2e9

using namespace std;

vector<pair<int, int> > adj[1005];

int cost[1005];

void dijkstra(int N, int x, int y){
    
    
    priority_queue <pair < int, int> > pq;
    pq.push(make_pair(0, x));
    
    for(int i = 1 ; i <= N; i++){
        cost[i] = INF;
    }
    
    cost[x] = 0;
    
    while(!pq.empty()){
        int xv1cost = -(pq.top().first);
        int v1 = pq.top().second;
        if(v1 == y){
            cout << cost[y];
            return;  
        }
        pq.pop();
        
        for(int i = 0; i < adj[v1].size(); i++){
            int v2 = adj[v1][i].second;
            int v1v2cost = adj[v1][i].first;

            if(cost[v2] > xv1cost + v1v2cost){
                cost[v2] = xv1cost + v1v2cost;
                pq.push(make_pair(-cost[v2], v2));
            }
        }
    }
}


int main(){
    int N, M, A, B;

    cin >> N >> M;
    while(M--){
        int v1, v2, v1v2cost;
        cin >> v1 >> v2 >> v1v2cost;

        adj[v1].push_back(make_pair(v1v2cost, v2));
    }
    cin >> A >> B;    
    
    dijkstra(N, A, B);
    
    return 0;
}