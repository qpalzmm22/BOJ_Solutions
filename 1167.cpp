//1167.cpp
// use adj vector to implement tree and use DFS using DP

#include <iostream>
#include <string.h>
#include <tuple>
#include <vector>

#define MIN 0

using namespace std;

//vector< tuple<int,int,bool > > adj[100002]; // V, cost, DP
vector< pair<int,int > > adj[100002]; // V, cost

//int vCheck[100002];


// <max, max leaf>
pair<int, int> dfs(int callee, int x){

    //cout << "dfs[x] : " << x << "\n";
    //vCheck[x] = 1;

    int max_cost = 0;
    int max_leaf = x;

    for(int i = 0 ; i < adj[x].size() ; i++){
        pair<int,int> p = adj[x][i];
        if(p.first == callee)
            continue;
        pair<int, int> res = dfs(x, p.first);
        if(max_cost < p.second + res.first){
            max_cost = p.second + res.first;
            max_leaf = res.second; 
        }
        //max_cost = max(max_cost, p.second + res.first);
        
        // tuple<int,int,bool> p = adj[x][i];
        // if(get<0>(p) == callee)
        //     continue;
        // if(get<2>(p) == true){
        //     max_cost = get<1>(p);
        // } else {
        //     max_cost = max(max_cost, get<1>(p) + dfs(x, get<0>(p)).first);
        //     get<1>(p) = max_cost;
        //     get<2>(p) = true;
        // }
    }  
    pair<int,int> res_pair = make_pair(max_cost, max_leaf);

    return max_cost;
}

int main(){
    int nV;
    int branch[100002];
    cin >> nV;

    for(int i = 1; i <= nV; i++){
        int x;
        int V;
        int E;

        cin >> x;
        while(1){
            
            cin >> V;
            if(V == -1){
                break;
            }
            branch[V]++;
            cin >> E;
            //tuple<int, int, bool> p = make_tuple(V, E, false);
            pair<int,int> p = make_pair(V,E);
            adj[x].push_back(p);
        }
    } 

    // find all dfs of all nodes?
    // not it... => O(EV)
    // maybe?
    int max_cost = 0;
    // if(branch[i] == 1) // leaf
    //     max_cost = max(max_cost, dfs(0, i));
    pair<int,int> p1 = dfs(0, 1);
    pair<int,int> p2 = dfs(0, p1.second);

    max_cost = max(p1.first, p2.first);

    cout << max_cost;
    return 0;
}