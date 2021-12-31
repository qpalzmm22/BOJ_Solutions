// 1. Dijkstraf form target node,
// 2. reverse the adjlist
// 3. Dijkstra from target node

// add 1 and 3 for all nodes and find max.
#include <iostream>
#include <string>
#include <vector>
#include <tuple>
#include <queue>

using namespace std;

vector<pair<int,int> > adj1[1005]; // cost, V
vector<pair<int,int> > adj2[1005]; // cost, V
priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pQ;

#define MAXCOST 1000000005

int gocost[1005];
int retcost[1005];

void dijkstra(int x, int cost[], vector<pair<int,int> > adj[]){
    pair<int,int> p = make_pair(0, x);
    pQ.push(p);
    cost[x] = 0;
    
 
    while(!pQ.empty()){
        int v1 = pQ.top().second;
        //int v1cost = pQ.top().first;
        pQ.pop();
        
    
        //cout << "looping : [" << v1 << ", " << cost[v1] << "]\n" ;
        
        for(int i = 0; i < adj[v1].size(); i++){
            pair<int,int> t = adj[v1][i];
            int v2 = t.second;
            int v1v2cost = t.first;
            
            if(cost[v2] > cost[v1] + v1v2cost){
                pQ.push(make_pair(cost[v1] + v1v2cost, v2));
                cost[v2] = cost[v1] + v1v2cost;
            }
        }
    }
}

void printCost(int n, int cost[]){
    for(int i = 0; i <= 0; i++){
        cout << cost[i] << " ";
    }
}

void resetCost(int n, int cost[]){
    for(int i = 1; i <= n; i++){
        cost[i] = MAXCOST;
    }
}

int main(){
    int N, M, X;

    cin >> N >> M >> X;
    resetCost(N, retcost);
    resetCost(N, gocost);

    for(int i = 0; i < M; i++){
        int v1, v2, v1v2cost;
        cin >> v1 >> v2 >> v1v2cost;
        pair<int,int> t = make_pair(v1v2cost, v2);
        adj1[v1].push_back(t);

        pair<int,int> t2 = make_pair(v1v2cost, v1);
        adj2[v2].push_back(t2);
    }
    
    dijkstra(X, retcost, adj1);
    //cout << "--------------\n";
    dijkstra(X, gocost, adj2);

    int maxCost = 0;
    
    for(int i = 1; i <= N; i++){
        maxCost = max(maxCost, gocost[i] + retcost[i]);
    }
    //printCost(N, retcost);
    //cout << "--------------\n";
    //printCost(N, gocost);
    //cout<< endl;
    cout << maxCost;

    return 0;
}