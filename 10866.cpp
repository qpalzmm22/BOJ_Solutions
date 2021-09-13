#include <bits/stdc++.h>

using namespace std;

int
main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    deque<int> dq;

    int n;

    cin >> n;

    while(n--) {
        string cmd;
        cin >> cmd;
        if(cmd == "push_back"){
            int operand;
            cin >> operand;
            dq.push_back(operand);
        } else if(cmd == "push_front"){
            int operand;
            cin >> operand;
            dq.push_front(operand);
        } else if(cmd == "pop_front"){
            if(dq.empty()){
                cout << "-1\n" ;
            } else {
                cout << dq.front() << "\n" ;
                dq.pop_front();
            }
        } else if(cmd == "pop_back"){
            if(dq.empty()){
                cout << "-1\n" ;
            } else {
                cout << dq.back() << "\n" ;
                dq.pop_back();
            }
        } else if(cmd == "size"){
            cout << dq.size() << "\n" ;
        } else if(cmd == "empty"){
            cout << dq.empty() << "\n" ;
        } else if(cmd == "front"){
            if(dq.empty()){
                cout << "-1\n" ;
            } else {
                cout << dq.front() << "\n" ;
            }
        } else if(cmd == "back"){
            if(dq.empty()){
                cout << "-1\n" ;
            } else {
                cout << dq.back() << "\n" ;
            }
        } else {
            cout << "error\n" ;
        }
    }
}