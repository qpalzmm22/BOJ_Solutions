// use Dijkstra and save path at the array?
// or solve with floyd because we dont know if multiple buses start from one place and end at same place.

// Not correct... maybe because city numbers could come in any number..?
#include <iostream>
#include <vector>
#include <stack>

#define INF 2e8   

using namespace std;

long long adj[1005][1005];
int path[1005][1005];

void floyd(int N){
    for(int k = 1; k <= 1000; k++){
        for(int i = 1; i <= 1000; i++){
            for(int j = 1; j <= 1000; j++){
                if(adj[i][j] >  adj[i][k] + adj[k][j]){
                    adj[i][j] = adj[i][k] + adj[k][j];
                    path[i][j] = k;
                }
            }
        }    
    }
}

int main(){
    int n, m;

    cin >> n >> m;

    for(int i = 1; i <= 1000; i++){
        for(int j = 1 ; j <= 1000 ; j++){
            path[i][j] = i;
            if(j == i){
                adj[i][j] = 0;
            } else{
                adj[i][j] = INF;
            }
        }
    }

    for(int i = 0; i < m; i++){
        int v1, v2;
        long long v1v2cost;
        cin >> v1 >> v2 >> v1v2cost;
        adj[v1][v2] = min(adj[v1][v2], v1v2cost);
    }

    floyd(n);

    int a, b;
    cin >> a >> b;

    // for(int i = 1; i <= n; i++){
    //     for(int j = 1 ; j <= n ; j++){
    //         cout << adj[i][j] << " ";
    //     }
    //     cout << "\n";
    // }

    cout << adj[a][b] << "\n";

    stack<int> s;

    if(a == b){
        cout << 1 << "\n";
        cout << a;
    } else {
        s.push(b);
        int prevPath = path[a][b];
        while(prevPath != a){
            s.push(prevPath);
            prevPath = path[a][prevPath];        
        }
        s.push(a);

        cout << s.size() << "\n";
        while(!s.empty()){
            cout << s.top();
            s.pop();
            if(!s.empty())
                cout << " "; 
        }
    }
    return 0;
}