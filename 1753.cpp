#include <iostream>
#include <vector>
#include <queue>

#define INF 9999999

using namespace std;

vector<pair<int, int> > adj[20005];
priority_queue <pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pQ;
int cost[20005];

void dijkstra(int x){
    pQ.push(make_pair(0, x));
    cost[x] = 0;

    while(!pQ.empty()){
        int v1 = pQ.top().second;
        int xv1cost = pQ.top().first;
        pQ.pop();
        
        for(int i = 0; i < adj[v1].size(); i++){
            int v2 = adj[v1][i].second;
            int v1v2cost = adj[v1][i].first;

            if(cost[v2] > v1v2cost + xv1cost){
                cost[v2] = v1v2cost + xv1cost;
                pQ.push(make_pair(cost[v2], v2));
            }
        }
    }
}

void resetCost(int N){
    for(int i = 1; i <= N; i++){
        cost[i] = INF;
    } 
}

void printCost(int N){
    for(int i = 1; i <= N; i++){
        if(cost[i] == INF){
            cout << "INF" << "\n";
        } else {
            cout << cost[i] << "\n";
        }
    }
}

int main(){
    int V, E, X;

    cin >> V >> E ;
    cin >> X;

    resetCost(V);

    while(E--){
        int v1, v2, cost;
        cin >> v1 >> v2 >> cost;

        adj[v1].push_back(make_pair(cost, v2));
    }    

    dijkstra(X);

    printCost(V);


    return 0;
}