#include <iostream>
#include <algorithm>

#define MAX 1000005 // 1000 * 1000 + 5

using namespace std;

int rgb[1005][3];
int dp [1005][3];
int nHome;

int search_bfs(int ind, int cur_rgb){

    if(ind == nHome)
        return 0;


    int prev = rgb[ind][cur_rgb];
    int path[3] = {MAX, MAX, MAX};

    for(int i = 0 ; i < 3; i++){

        
        if(cur_rgb != i){
            if(dp[ind + 1][i] != MAX){
                path[i] = prev + dp[ind + 1][i];
            } else {
                path[i] = prev + search_bfs(ind + 1, i);
            }
        }
    }

    int minimum = min(min(path[0], path[1]), path[2]);
    dp[ind][cur_rgb] = minimum;
    
    return minimum;
}

int dijkstra(){

    // init  dijkstra matrix
    for(int i = 0; i < nHome; i++){
        dp[i][0] = MAX;
        dp[i][1] = MAX;
        dp[i][2] = MAX;
    }

    int r = search_bfs(0, 0);
    int g = search_bfs(0, 1);
    int b = search_bfs(0, 2);
    
    return min(min(r, g),b);
}


int main(){
     cin >> nHome;
    int i;
 
    i = 0;
    while(i < nHome){
        for(int j = 0 ; j < 3 ; j++){
            cin >> rgb[i][j];
        }
        i++;
    }
    cout << dijkstra();
    // dijkstra algo
    return 0;
}