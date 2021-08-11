#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int a,b,c,tmp;
    cin >> a >> b >> c;

    if(a <= b && a <= c){
        cout << a << " ";
    } else if(b <= c){
        tmp = a;
        a = b;
        b = tmp;
        cout << a << " ";
    } else {
        tmp = a;
        a = c;
        c = tmp;
        cout << a << " ";
    }
    
    if( b <= c){
        cout << b << " " << c ;
    } else {
        cout << c << " " << b ;
    }
    return 0;
}