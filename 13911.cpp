#include <iostream>
#include <queue>
#define pii pair < long long , int >
#define HOME 0
#define MAC 1
#define STAR 2
#define MACNSTAR 3
#define MX 1e15

using namespace std;

int V, E;
int M, S;
int x, y;

long long dist[10005];

vector < pii > adj[10005];

int identity[10005];

long long distMac[10005];
long long distStar[10005];

int macNode;
int starNode;

void resetDist(){
    for(int i = 1; i <= V+2; i++){
        dist[i] = MX;
    }
}

void printDist(){
    for(int j = 1 ; j <= V+2; j++){
        if(dist[j] == MX)
            cout << "MX ";
        else 
            cout << dist[j] << " " ;
    }
    cout << "\n";
}

void dijkstra(int x){

    priority_queue < pii, vector < pii > , greater <pii> > pq; 
    pq.push(make_pair(0 , x));

    while(!pq.empty()){
        long long xv1cost = pq.top().first;
        int v1 = pq.top().second;
        pq.pop();

        for(int i = 0; i < adj[v1].size(); i++){
            long long v1v2cost = adj[v1][i].first;
            int v2 = adj[v1][i].second;

            if(dist[v2] > dist[v1] + v1v2cost){
                dist[v2] = dist[v1] + v1v2cost;
                pq.push(make_pair(dist[v2], v2));
            }
        }
    }
}

int main(){
    
    cin >> V >> E;

    resetDist();

    macNode = V+1;
    starNode = V+2;

    for(int i = 1; i <= V+2; i++){
        distMac[i] = MX;
        distStar[i] = MX;
    }
    
    for(int i = 0; i < E; i++){
        int u, v, w;
        cin >> u >> v >> w;
        // dist[u][v] = min(dist[u][v], w); 
        // dist[v][u] = min(dist[v][u], w); 
        adj[u].push_back(make_pair(w, v));
        adj[v].push_back(make_pair(w, u));
    }

    //printDist();  
    cin >> M >> x;
    for(int i = 0 ; i < M ; i++){
        int mac;
        cin >> mac;
        identity[mac] += MAC;
        adj[macNode].push_back(make_pair(0, mac));
    }
    

    identity[macNode] = MAC;
    identity[starNode] = STAR;

    cin >> S >> y; 
    for(int i = 0 ; i < S ; i++){
        int star;
        cin >> star;
        identity[star] += STAR;
        adj[starNode].push_back(make_pair(0, star));
    }

    for(int i = V+1 ; i <= V+2 ; i++){
        resetDist();
        dist[i] = 0;
        dijkstra(i);
        //printDist();
        for(int j = 1 ; j <= V; j++){
            if(identity[j] != HOME)
                continue;
            if(i == V+1) // MAC
                distMac[j] = min(distMac[j], dist[j]);
            if(i == V+2) // Star
                distStar[j] = min(distStar[j], dist[j]);
        }
    }

    long long minDists = MX;
    for(int i = 1; i <= V; i++){
        //cout << distMac[i] <<  " " << distStar[i] << "\n";
        if(distMac[i] <= x && distStar[i] <= y){
            minDists = min(minDists, distMac[i] + distStar[i]);
        }
    }
    
    if(minDists >= MX)
        cout << -1 ;
    else 
        cout << minDists;

    return 0;
}
