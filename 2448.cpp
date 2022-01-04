#include <iostream>



using namespace std;

int map[3100][6500];

void starPrint(int n){
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 2*n - 1; j++){
            cout << (map[i][j]?"*":" ");
        }
        cout << "\n";
    }
}

void starPaint(int y, int x, int n){
    if(n == 3){
        map[y][x+2] = 1;

        map[y+1][x+1] = 1;
        map[y+1][x+3] = 1;

        map[y+2][x+0] = 1;
        map[y+2][x+1] = 1;
        map[y+2][x+2] = 1;
        map[y+2][x+3] = 1;
        map[y+2][x+4] = 1;
    } else{
        starPaint(y , x + n/2 , n/2);
        starPaint(y+n/2 , x , n/2);
        starPaint(y+n/2 , x + n , n/2);
    }
    
}

int main(){
    int n;
    cin >> n;

    starPaint(0,0,n);
    starPrint(n);
    return 0;
}
