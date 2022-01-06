//9935

#include <iostream>

using namespace std;

string str;
string bomb;

int bombVal = 0;
int strVal[1000005];

int main(){
    cin >> str;
    cin >> bomb;
    
    strVal[0] = 0;
    for(int i = 1; i <= bomb.size(); i++){
        bombVal += bomb[i];
        strVal[i] = strVal[i - 1] + str[i];
    }
    
    int s_i = 0 ;
    int e_i = bomb.size();
    while(1){
        if(bomb,   == 0){

        } 
    }
    return 0;
}