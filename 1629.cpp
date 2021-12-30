#include <iostream>

using namespace std;

// unsigned long long int dp[1147483647]; // square of (A^[index])



unsigned long long mypow(int x, int y, int C){
    if(y == 0){
        return 1;
    } else if(y == 1){
        return x % C;
    } else if(y % 2 == 0){ // even exponent
        //if(dp[y/2] != 0){
        //    return dp[y/2];
        //} else{
        //    dp[y/2] = ((mypow(x, y/2, C) % C) * (mypow(x, y/2, C) % C)) %C;
            //cout << "y : " << y << " dp[y/2] : " << dp[y/2] << endl;  
        //    return dp[y/2]; 
        return (mypow(x, y/2, C) * (mypow(x, y/2, C)) % C);
    } else { // odd exponent
        return ((mypow(x, y-1, C) * (x % C)) % C);
    }
}


int main(){
    int A, B, C;
    unsigned long long result = 1;
    cin >> A >> B >> C;

    result = mypow(A, B, C);

    cout << result ;

    return 0;
}