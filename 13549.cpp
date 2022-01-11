#include <iostream>
#include <queue>

#define MAX 100000
#define MAXCOST MAX+5

#define pii pair<int,int>
// use dijkstra

int cost[MAX + 5];

using namespace std;

int N, K;

int dijkstra(int n){
    priority_queue<pii > pq;
    pq.push(make_pair(0, n));
    cost[n] = 0;

    while(!pq.empty()){
        int numNcost = -pq.top().first;
        int num = pq.top().second;
        pq.pop();

        //cout << numNcost << "], [" << num << "\n";
        
        if(num == K)
          return cost[K];

        if(num + 1 <= MAX && cost[num + 1] > 1 + numNcost ){
            cost[num + 1] = 1 + numNcost;
            pq.push(make_pair(-(1 + numNcost), num + 1));
        }
        if(num - 1 >= 0 && cost[num - 1] > 1 + numNcost ){
            cost[num - 1] = 1 + numNcost;
            pq.push(make_pair(-(1 + numNcost), num - 1));
        }
        if(num * 2 <= MAX && cost[num * 2] > numNcost ){
            cost[num * 2] = numNcost;
            pq.push(make_pair(-numNcost, num * 2));
        }
    }
    return cost[K];
}

int main(){
    cin >> N >> K;
  
    for(int i = 0; i <= MAX; i++){
      cost[i] = MAXCOST;
    }

    int result = dijkstra(N);
    cout << result;
    return 0;
}
