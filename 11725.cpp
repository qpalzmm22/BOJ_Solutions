#include <iostream>
#include <vector>
#include <queue>
// BFS

using namespace std;

vector <int> adj[100005];

int visited[100005];

void bfs(int n){
    queue<int> q;
    q.push(n);
    visited[n] = 1;

    while(!q.empty()){
        int v = q.front();
        q.pop();

        for(int i = 0 ; i < adj[v].size(); i++){
            if(visited[adj[v][i]] == 0){
                visited[adj[v][i]] = v;
                q.push(adj[v][i]);
            }
        }
    }
}

int main(){
    int N ;

    cin >> N;
    for(int i = 0; i < N-1; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    bfs(1);

    for(int i = 2; i <= N; i ++){
        cout << visited[i] << "\n";
    }

    return 0;
}