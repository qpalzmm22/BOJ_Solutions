#include <bits/stdc++.h>

using namespace std;

int 
main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    queue<int> q;
    int n, operand;
    string cmd;

    cin >> n;

    while(n-- > 0 ){
        cin >> cmd;
        if(cmd == "push"){ 
            cin >> operand;
            q.push(operand);
            continue;
        } else if(cmd == "pop"){
            if(q.empty()){
                cout << -1;
            } else{         
                cout << q.front();
                q.pop();
            }
        } else if(cmd == "size"){
            cout << q.size();
        } else if(cmd == "empty"){
            cout << q.empty();
        } else if(cmd == "front"){
            if(q.empty()){
                cout << -1;
            } else{         
                cout << q.front();
            }
        } else if(cmd == "back"){
            if(q.empty()){
                cout << -1;
            } else{         
                cout << q.back();
            }
        } else {
            cout << "error";
            exit(1);
        }
        cout << "\n";
    } 

    return 0;
}