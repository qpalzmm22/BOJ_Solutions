#include <iostream>
#include <queue>
// last letter of postfix = root
// infix seperates post and in
using namespace std;

int pre[100005];
int in[100005];
int post[100005];

queue<int> Q;


// 
void process(int sub_post[], int sub_in[]){

}


int main(){
    int N;
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> in[i]; 
    }
    for(int i = 0; i < N; i++){
        cin >> pre[i]; 
    }

}