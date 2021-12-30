#include <iostream>
#include <vector>

#define INF 2e8;

using namespace std;

int currcost[505];
int prevcost[505];

void reset_cost(int N, int cost[]){
    for(int i = 1; i <= N; i++){
        cost[i] = INF;
    }
}

void printCost(int N, int cost[]){
    cout << "cost : ";
    for(int i = 1; i <= N; i++){
        cout << cost[i] << " ";
    }
    cout << endl;
}

void cpyCost(int N){
    for(int i = 1; i <= N; i++){
        prevcost[i] = currcost[i];
    }
}

bool cmpCost(int N){
    for(int i = 1; i <= N; i++){
        if(prevcost[i] != currcost[i])
            return false;
    }
    return true;
}


void test_negloop(int N, vector<pair<int, int> > adj[]){
    int count = N -1;
    bool isSame = false;
    // bellman-ford
    reset_cost(N, currcost);
    reset_cost(N, prevcost);
    currcost[1] = 0; // assumes 1 is the src.

    while(count--){
        for(int i = 1 ; i <= N ; i++){
            for(int j = 0 ; j < adj[i].size() ; j++){
                int v2 = adj[i][j].second;
                int v1v2cost =  adj[i][j].first;
                if(currcost[v2] > currcost[i] + v1v2cost){
                    currcost[v2] = currcost[i] + v1v2cost;
                }
            }
        }

        //if((cmpCost(N))){
        //    cout << "NO\n";
        //    return; 
        //}

        //printCost(N, currcost);
        //cpyCost(N);
    }
    //cout << "----------------\n";
    cpyCost(N);
    // and do one more to test it it gets smaller 
    for(int i = 1 ; i <= N ; i++){
        for(int j = 0 ; j < adj[i].size() ; j++){
            int v2 = adj[i][j].second;
            int v1v2cost =  adj[i][j].first;
            
            if(currcost[v2] > currcost[i] + v1v2cost){
                currcost[v2] = currcost[i] + v1v2cost;
            }
        }
    }
    //printCost(N, currcost);

    isSame = cmpCost(N);
    cout << (isSame ? "NO": "YES") << "\n";

}


int main(){
    int tc;

    cin >> tc;

    while(tc--){
        int N, M, W;
        vector<pair<int, int> > adj[505]; // cost, v2
        cin >> N >> M >> W;

        int v1, v2, cost;
        while(M--){
            cin >> v1 >> v2 >> cost ;
            adj[v1].push_back(make_pair( cost, v2));
            adj[v2].push_back(make_pair( cost, v1));
        }
        while(W--){
            cin >> v1 >> v2 >> cost;
            adj[v1].push_back(make_pair( -cost, v2));
        }
        test_negloop(N, adj);
    }

    return 0;
}