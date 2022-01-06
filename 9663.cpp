#include <iostream>
#include <vector>

#define pii pair<int, int>

using namespace std;

int Qcount = 0;

void back_tracking(int N, vector< pii > &queens, int y){
    
    for(int i = 0; i < N; i++){  // new x
        
        //cout << "[y, i] [ " << y << " " << i << "]\n";
        bool safeflag = false;
        for(int j = 0; j < queens.size(); j++){
            int qy = queens[j].first;
            int qx = queens[j].second;
            //cout << "[qy, qx] [ " << qy << " " << qx << "] \n";
            if(qx == i){
                safeflag = true;
                break;
            }

            float slope = (qy - y) / (float)(qx - i);

            if( slope == -1 || slope == 1 ){
                safeflag = true;
                break;
                //cout << "Not possible because [qy, qx] [ " << qy << " " << qx << "] \n";
            }
        }

        if(!safeflag){
            if(y + 1 == N){
                //cout << "Found at [y, i] [ " << y << " " << i << "]\n";
                Qcount++;
                continue;
            }
            //vector< pii > newqueens = queens;
            //newqueens.push_back(make_pair(y, i));
            //back_tracking(N,newqueens,y+1);
            queens.push_back(make_pair(y, i));
            back_tracking(N,queens,y+1);
            queens.pop_back();
        }
    }
}

int main(){
    int N;
    cin >> N;

    vector <pii> queens;
    back_tracking(N, queens, 0);

    cout << Qcount;
    return 0;
}