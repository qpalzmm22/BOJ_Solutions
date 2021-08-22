#include <iostream>
#include <stack>


using namespace std;

int
main()
{
    int n ;
    stack<int> st;
    cin >> n; 
    while(n -- > 0){
        string cmd;
        int num;
        cin >> cmd;

        if( cmd == "push"){
            cin >> num;
            st.push(num);
        } else if( cmd == "pop"){
            if(st.empty()){
                cout << "-1" << "\n";
            } else{
                cout << st.top() << "\n";
                st.pop();
            }
        } else if( cmd == "top") {
            if(st.empty()){
                cout << "-1" << "\n";
            } else {
                cout << st.top() << "\n";
            }
        } else if (cmd == "size") {
            cout << st.size() << "\n";
        } else {
            if(st.empty() == true){
                cout << 1<< "\n";
            } else {
                cout << 0 << "\n";
            }
        }
    }
    return 0;    
}
