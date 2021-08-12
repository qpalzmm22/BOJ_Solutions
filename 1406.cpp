#include <bits/stdc++.h>

using namespace std;

int main(){
    // ios::sync_with_stdio(0);
    // cin.tie(0);

    string a;
    list<char> list; 

    cin >> a;
    for(int i = 0; i < a.length(); i++){
        list.push_back(a[i]);
    }

    auto it = list.end();

    int n;
    cin >> n;

    for (int i = 0; i < n; i++){
        
        char command;
        cin >> command;
        if(command == 'L'){
            if( it != list.begin())
                it--;
        } else if (command == 'D'){
            if( it != list.end())
                it++;
        } else if (command == 'B'){
            if( it != list.begin()){
                it = list.erase(--it);
            }
        } else {
            cin >> command;
            it = list.insert(it, command);
            it++;
        }
    }
    for(auto it = list.begin(); it != list.end(); it++){
        cout << *it;
    }

    return 0;
}