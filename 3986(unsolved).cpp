#include <iostream>
#include <stack>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int ans = 0;


    while(n--){
        string s;
        stack<char> st;
        cin >> s;
        int aCount = 0;
        int bCount = 0;
        bool flag = true;

        for(int i = 0 ; i < s.length() ; i++){
            if(s[i] == 'A'){
                aCount++;
                if(aCount % 2 == 1){
                    st.push(s[i]);        
                } else{
                    if(st.empty() ||st.top() != 'A'){
                        flag = false;
                        break;
                    } else{
                        st.pop();
                    }
                }
            } else { //  'B'
                bCount++;
                if(bCount % 2 == 1){
                    st.push(s[i]);        
                } else {
                    if(st.empty() || st.top() != 'B'){
                        flag = false;
                        break;
                    } else{
                        st.pop();
                    }
                }
            }
        }
        if(st.empty() && flag)
            ans++;
    }
    cout << ans << "\n";
    return 0;
}