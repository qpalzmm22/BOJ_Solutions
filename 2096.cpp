#include <iostream>

using namespace std;

int map[3][100005];
int N;

#define INF 1e8

int currmax[3];
int nextmax[3];
int currmin[3];
int nextmin[3];

int main(){

    cin >> N;


    for(int i = 0; i < N; i++){
        cin >> map[0][i] >> map[1][i] >> map[2][i];
    }

    currmax[0] = currmin[0] = map[0][0];
    currmax[1] = currmin[1] = map[1][0];
    currmax[2] = currmin[2] = map[2][0];

    //cout << "max : "<< maxdp[0] << " " << maxdp[1] << " " << maxdp[2] << "\n";
    //cout << "min : "<< mindp[0] << " " << mindp[1] << " " << mindp[2] << "\n";
    //int prev = 1;
    for(int i = 1; i < N; i++){     
        for(int j = 0; j < 3; j++){ // dp   
            int maxx = -INF;
            int minn = INF;
            for(int k = 0; k < 3; k++){ // map
                if(k - 1 == j || k == j || k + 1 == j){
                    if(maxx < map[j][i] + currmax[k]){
                        maxx = map[j][i] + currmax[k];
                    }
                    if(minn > map[j][i] + currmin[k]){
                        minn = map[j][i] + currmin[k];
                    }
                }
            }
            nextmax[j] = maxx;
            nextmin[j] = minn; 
        }
        currmax[0] = nextmax[0];
        currmax[1] = nextmax[1];
        currmax[2] = nextmax[2];
        currmin[0] = nextmin[0];
        currmin[1] = nextmin[1];
        currmin[2] = nextmin[2];

        // cout << "max : "<< currmax[0] << " " << currmax[1] << " " << currmax[2] << "\n";
        // cout << "min : "<< currmin[0] << " " << currmin[1] << " " << currmin[2] << "\n";
    }

    int maxcost = max(currmax[0], max(currmax[1], currmax[2]));
    int mincost = min(currmin[0], min(currmin[1], currmin[2]));

    cout << maxcost <<  " ";
    cout << mincost;
    return 0;
}