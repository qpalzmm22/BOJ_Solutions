#include <iostream>

typedef __uint128_t int4;

#define UNF 0 // undefined  
using namespace std;


// Pascal
int4 dp[105][105]; 

void printInt4(int4 n){
    if(n / 10  == 0){
        printf("%c", '0' + n % 10);
    } else {
        printInt4(n/10);
        printf("%c", '0' + n % 10);
    }
}


// Use pascals triangle
int4 comb(int n, int m){
    
    if(m > n){
        return 0;
    }

    if(dp[n][m] != 0){
        return dp[n][m];
    }

    dp[n][m] = comb(n-1, m-1) + comb(n - 1, m);
    return dp[n][m];
}


void printPT(int n){
    for(int i = 0 ; i <= n; i++){
        for(int j  = 0; j <= i; j++){
            printf("%d ", dp[i][j]);
        }
        cout << "\n";
    }
}

void setPT(int n){
    for(int i = 0 ; i <= n; i++){
        for(int j  = 0; j <= i; j++){
            if(j == 0 || i == j){
                dp[i][j] = 1;
            }
        }
    }
}

int main(){
    int n, m;
    cin >> n >> m;


    setPT(n);

    int4 res = comb(n, m);
    //printPT(n);

    printInt4(res);
    //printf("%d", res);

    return 0;
}