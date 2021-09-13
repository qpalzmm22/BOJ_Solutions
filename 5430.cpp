#include <bits/stdc++.h>

using namespace std;

int
main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    string p, x;
    int n;
    
    deque<int> dq;

    string delimiter = ",";


    cin >> T;
    while(T--){
        dq.clear();
        int countR = 0;
        int countD = 0;
        bool ispopback = false;
        bool eflag = false;
        cin >> p >> n >> x;

        int startind = 1; // [
        int endind =  0;
        if(x.length() > 2){
            for(int i = 1 ; i < x.length() ; i++){
                if(x[i] == ',' || x[i] == ']'){
                    endind = i;
                    //cout << stoi("3") << "here" << x.substr(startind, endind - startind ) << "end" <<  "\n";
                    dq.push_back(stoi(x.substr(startind, endind - startind )));
                    // cout << x.substr(startind, endind - 1 ) << "\n";
                    startind = i + 1;
                }
            }
        }

        for(int i = 0; i < p.length(); i++){
            if(p[i] == 'R'){
                ispopback = !ispopback;
            } else{ // if 'D'
                if(dq.empty()){
                    cout << "error\n";
                    eflag = true;
                    break;
                }
                if(ispopback){ 
                    dq.pop_back();
                } else{
                    dq.pop_front();
                }
            }
        }
        if(!eflag){
            cout << "[";
            while(dq.size() > 0){
                if(!ispopback){
                    cout << dq.front();
                    dq.pop_front();
                } else {
                    cout << dq.back();
                    dq.pop_back();
                }
                if(dq.size() != 0){
                    cout << ",";
                }
            }
            cout << "]\n";
        }
    }


    return 0;
}