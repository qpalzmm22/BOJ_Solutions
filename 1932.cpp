#include <iostream>

using namespace std;

int tri[505][505];

void print_Tri(int N){
    for(int i = 0; i < N; i++){
        for(int j = 0; j <= i ; j++){
            cout << tri[i][j] << " ";
        }
        cout <<"\n";
    }
}


int main()
{
    int N;
    cin >> N ;

    for(int i = 0; i < N; i++){
        for(int j = 0; j <= i; j++){
            cin >> tri[i][j];
        }
    }
    //print_Tri(N);
    for(int i = N - 2; i >= 0; i--){
        for(int j = 0; j <= i; j++){
            tri[i][j] = tri[i][j] + max(tri[i+1][j], tri[i+1][j+1]);
        }
    }
    cout << tri[0][0];
    //print_Tri(N);
}