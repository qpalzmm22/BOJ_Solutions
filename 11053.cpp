#include <iostream>

using namespace std;

int arr[1005];
int val[1005];

int main(){
    int N;
    cin >> N;
    for(int i=0; i < N; i++){
        cin >> arr[i];
    }

    val[N] = 0;

    for(int i = N-1 ; i >= 0; i--){
        int longest;
        for(int j = N ; j > i; j--){
            if(arr[i] < arr[j]){
                longest = max(longest, val[j] + 1) ; 
            } else{
                longest = max(longest, val[j]) ; 
            }
        }

        val[i] = longest;
    }

    for(int i=0; i < N; i++){
        cout << val[i] << " " ;
    }
    cout << val[0];
    return 0;
}