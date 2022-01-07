//9935

#include <iostream>
#include <stack>
#define pii pair<char, int>

using namespace std;


deque< pii > st;

int main(){

    string str;
    string bomb;

    cin >> str;
    cin >> bomb;

    for(int i = 0; i < str.size(); i++){
        int prevInd;
        if(!st.empty()){
            prevInd = st.back().second;
            //cout << "prev Ind : " << prevInd << "\n" ;
            
            if(str[i] == bomb[prevInd]){
                prevInd++;
            } else if (str[i] == bomb[0]){
                prevInd = 1;
            } else {
                prevInd = 0;
            }
        } else {
            if (str[i] == bomb[0]){
                prevInd = 1;
            } else { 
                prevInd = 0;
            }
        }
        //cout << "[ " << str[i] << " " << prevInd <<" ]\n";
        st.push_back(make_pair(str[i], prevInd));

        if( prevInd == bomb.size()){
            while(prevInd--){
                st.pop_back();
            }
        }
    }

    if(st.empty()){
        cout << "FRULA";
    } else{
        while(!st.empty()){
            cout << st.front().first;
            st.pop_front();
        }
    }

    return 0;
}