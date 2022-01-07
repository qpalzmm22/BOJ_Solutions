#include <iostream>

using namespace std;

int val[1005];

int incr[1005];
int decr[1005];


int main(){
    int N;
    cin >> N;

    val[0] = 0; // MIN
    val[N + 1] = 0; // MAX
    for(int i=1; i<=N; i++){
        cin >> val[i];
    }



    for(int i = 1; i <= N; i++){
        int largest = 0;
        for(int j = 0; j < i; j++){
            if(val[i] > val[j]){
                largest = max(largest, incr[j] + 1);
            }
        }
        incr[i] = largest;
        //cout << i << " "<< incr[i] << "\n";
    }

    for(int i = N; i >= 1; i--){
        int largest = 0;
        for(int j = N+1; j > i; j--){
            if(val[j] < val[i]){
                largest = max(largest, decr[j] + 1);
            }
        }
        decr[i] = largest;
        //cout << i << " "<< decr[i] << "\n";
    }
    int maxval = 1;
    for(int i = 1; i <= N; i++){
        maxval = max(maxval, decr[i] + incr[i] - 1);
    }

    cout << maxval;

    return 0;
}