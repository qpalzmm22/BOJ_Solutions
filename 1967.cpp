#include <iostream>
#include <vector>

#define pii pair<int,int>

using namespace std;


vector<pii > adj[10005];

pii dfs(int callee, int x){
    int maxCost = 0;
    int maxleaf = x;
    for(int i = 0; i < adj[x].size(); i++){
        int xv1cost = adj[x][i].first;
        int v1 = adj[x][i].second;
        
        if(v1 == callee)
            continue;

        pii p = dfs(x, v1);

        int leaf = p.second ;
        int v1leafcost = p.first;

        if(maxCost < xv1cost + v1leafcost){
            maxleaf = leaf;
            maxCost = xv1cost + v1leafcost;
        }
    }

    return make_pair(maxCost, maxleaf);
}

int main(){
    int N;

    cin >> N;

    for(int i = 0; i< N - 1; i++){
        int v1, v2, v1v2cost;

        cin >> v1 >> v2 >> v1v2cost;

        adj[v1].push_back(make_pair(v1v2cost, v2));
        adj[v2].push_back(make_pair(v1v2cost, v1));
    }

    pii p1 = dfs(0, 1);
    pii p2 = dfs(0, p1.second);
    cout << max(p1.first, p2.first);
    
    return 0;
}