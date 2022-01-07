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
    arr[N] = 1001;
    int MAX = 1;

    for(int i = N-1 ; i >= 0; i--){
        int longest = 0;
        for(int j = N ; j > i; j--){
            
            if(arr[i] < arr[j]){
                longest = max(longest, val[j] + 1) ; 
               // cout << "Checked : " << i  << " "<< j << "] [" << val[j] << "\n" ;
            }
        }

        val[i] = longest;
        //cout << i << " : " <<  val[i] << "\n" ;
        MAX = max(val[i], MAX);
    }

    cout << MAX;
    return 0;
}