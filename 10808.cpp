#include <iostream>
#include <algorithm>

using namespace std;

int alpha[50];

int main(){
    
    string in;

    cin >> in;

    fill(alpha, alpha + 30, 0);

    for(int i = 0; i < in.length(); i++){
        alpha[in[i] - 'a']++;
        
    }

    for(int i = 0 ; i < 26 ; i++){
        cout << alpha[i] << " ";
    }

    return 0;
}