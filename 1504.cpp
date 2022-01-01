// 1504
// Possibly find Shortest Path to 2 first then 3, then from 3 to 4. DP

#include <iostream>
#include <vector>
#include <tuple>
#include <queue>

using namespace std;

#define INF 2e8

int x1cost[805];
int x2cost[805];



vector <pair<int,int>> adj[805]; // adj list with dp


void resetCost(int N, int cost[]){
    for(int i = 1; i <= N; i++){
        cost[i] = INF;
    }
}

void printCost(int N, int cost[]){
    for(int i = 1; i <= N; i++){
        cout << cost[i]  << " ";
    }
}
void dijksta(int x, int cost[]){
    
    // bfs;
    priority_queue<pair<int, int>> Q;
    Q.push(make_pair(0, x));
    cost[x] = 0;

    while(Q.empty() != true){
        int v1 = Q.top().second;
        int xvcost = -Q.top().first;
        Q.pop();
        
        
        for(int i = 0; i < adj[v1].size(); i++){
            int v2 = adj[v1][i].second;
            int v1v2cost = adj[v1][i].first;
            
            if(cost[v2] > xvcost + v1v2cost){
                cost[v2] = xvcost + v1v2cost;
                Q.push(make_pair(-cost[v2], v2));
            }
        }
    }
}


int main()
{
    int N, E;

    cin >> N >> E ;

    for(int i = 0; i < E; i++){
        int v1, v2;
        int cost;
        cin >> v1 >> v2 >> cost; 
        
        pair<int, int> p1 = make_pair(cost, v2);
        adj[v1].push_back(p1);

        pair<int, int> p2 = make_pair(cost, v1);
        adj[v2].push_back(p2);
    }

    int V1, V2; 
    cin >> V1 >> V2; 

    resetCost(N, x1cost);
    resetCost(N, x2cost);
    // take dijkstra from V1 and V2. find cost to 1 and N use them
    dijksta(V1, x1cost);
    dijksta(V2, x2cost);
    // printCost(N, x1cost);
    // cout << "-------\n";
    // printCost(N, x2cost);

    int path1 = x1cost[1] + x1cost[V2] + x2cost[N]; // 2 -> 1, 2 -> 3 , 3 -> 4
    int path2 = x2cost[V1] + x2cost[1] + x1cost[N]; // 3 -> 1, 3 -> 2 , 2 -> 4
    int cost = min(path1, path2);
    
    if(x1cost[1] == INF || x2cost[1] == INF || x1cost[V2] == INF || x1cost[N] == INF || x2cost[N] == INF)
        cout << "-1";
    else
        cout << cost;


    return 0;
}