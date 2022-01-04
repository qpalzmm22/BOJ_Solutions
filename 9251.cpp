//LCS

#include <iostream>

using namespace std;

int dp[1005][1005];
string s1, s2;


int lcs(int a, int b){
    if(dp[a][b] != -1){
        return dp[a][b];
    }

    int equal = 0;
    int l1 = lcs(a+1, b);
    int l2 = lcs(a, b+1);
    int l3 = lcs(a+1, b+1);

    if(s1[a] == s2[b] && l1 == l2){
        dp[a][b] = l3 + 1;
    } else {
        dp[a][b] = max(l1, l2) ; 
    }
    // if(s1[a] == s2[b] && l1 == l2){
    //     equal = 1;
    // } else {}


    // dp[a][b] = max(l1,l2) + equal;


    return dp[a][b];
}

int main(){

    cin >> s1 >> s2;

    for(int i = 0; i < s1.size(); i++){
        for(int j = 0; j < s2.size(); j++){
            
            dp[i][j] = -1;
            
        }
    }
    int ans = lcs(0, 0);
    // for(int i = 0; i < s1.size(); i++){
    //     for(int j = 0; j < s2.size(); j++){
    //         //if(i == 0)
    //         //    cout << s2[j] << " ";
    //         //if(j == 0 )
    //         //    cout << s1[i] << " ";
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << "\n";
    // }

    cout << ans;
    return 0;
}