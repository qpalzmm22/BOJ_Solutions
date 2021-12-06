#include <iostream>
#include <stack>

using namespace std;

int main(){

    string str;

    while(1) {
        stack<char> s;
        string ans = "yes";
        getline(cin, str);
        if(str == ".")
            break;
            
        for(int i = 0; i < str.size(); i++){
            if(str[i] == '(') 
                s.push('(');
            else if(str[i] == '[')
                s.push('[');
            else if(str[i] == ')') {
                if(s.empty()){
                    ans = "no"; 
                    break;
                } else if(s.top() != '(') {
                    ans = "no";
                    break;
                } else{
                    s.pop();
                }
            } else if(str[i] == ']'){
                if(s.empty()){
                    ans = "no"; 
                    break;
                } else if(s.top() != '[') {
                    ans = "no";
                    break;
                } else{
                    s.pop();
                }
            }
        }
        if(!s.empty()) ans = "no";
        
        cout << ans << "\n";
    }


    return 0;
}