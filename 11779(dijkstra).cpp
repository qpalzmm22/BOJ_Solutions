// use Dijkstra and save path at the array?
// or solve with floyd because we dont know if multiple buses start from one place and end at same place.

// Not correct... maybe becsue city numbers could come in any number..?
#include <iostream>
#include <vector>
#include <queue>
#include <stack>

#define pii pair<int,int>
#define INF 2e8   

using namespace std;

vector<pii > adj[1005];

int cost[1005];
int path[1005];

void dijkstra(int a){
    priority_queue<pii > pq;

    pq.push(make_pair(0, a));
    cost[a] = 0;

    while(!pq.empty()){
        int v1v2cost = -pq.top().first;
        int v2 = pq.top().second;
        pq.pop();

        if(v1v2cost > cost[v2])
            continue;

        for(int i = 0 ; i < adj[v2].size() ; i++){
            int v3 = adj[v2][i].second;
            int v2v3cost = adj[v2][i].first;

            if(cost[v3] > v1v2cost + v2v3cost){
                cost[v3] = v1v2cost + v2v3cost;
                path[v3] = v2;
                pq.push(make_pair(-cost[v3], v3));
            }
        }
    }
}

int main(){
    int n, m;

    cin >> n >> m;

    for(int i = 0; i < m; i++){
        int v1, v2;
        long long v1v2cost;
        cin >> v1 >> v2 >> v1v2cost;
        adj[v1].push_back(make_pair(v1v2cost, v2));
        cost[v1] = INF;
        cost[v2] = INF;
    }


    int a, b;
    cin >> a >> b;
    dijkstra(a);


    cout << cost[b] << "\n";

    stack<int> s;

    if(a == b){
        cout << 1 << "\n";
        cout << a;
    } else {
        s.push(b);
        int prevPath = path[b];
        while(prevPath != a){
            s.push(prevPath);
            prevPath = path[prevPath];        
        }
        s.push(a);

        cout << s.size() << "\n";
        while(!s.empty()){
            cout << s.top() << " ";
            s.pop();
        }
    }
    return 0;
}