// 1504
// Possibly find Shortest Path to 2 first then 3, then from 3 to 4. DP

#include <iostream>
#include <vector>
#include <tuple>
#include <queue>



using namespace std;

vector <tuple<int,int,bool>> adj[800]; // adj list with dp

int dijksta(int from, int to){
    
    // bfs;
    queue<int> Q;
    Q.push(from);

    while(Q.empty() != true){
        int v = Q.front();
        Q.pop();
        
        for(int i = 0; i < adj[v].size(); i++){
            tuple<int,int,bool> t = adj[v][i];
            if(get<2>(t) == false){
                Q.push(get<1>(t));
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
        
        tuple<int, int, false> p1 = make_tuple(v2, cost,false);
        adj[v1].push_back(p1);

        tuple<int, int, false> p2 = make_tuple(v1, cost,false);
        adj[v2].push_back(p2);
    }

    int V1, V2; 
    cin >> V1 >> V2; 


    // take dijkstra from V1 and V2. find cost to 1 and N use them
    dijksta(V1);
    // int d1 = dfs(1, a) + dfs( );
    // int d2 = dfs() + dfs(); 





    return 0;
}