#include <iostream>
#include <stack>

using namespace std;

const int MAX_STACK = 100005;

int my_stack[MAX_STACK];
int pos;

void push(int n){
    my_stack[pos++] = n;
}

void pop(){
    pos--;
}

int calc_tot()
{
    int tot = 0;
    for(int i = 0; i < pos; i++){
        tot += my_stack[i];
    }
    return tot;
}


int main()
{
    int n, cmd;
    cin >> n;
    while(n-- > 0 ){
        cin >> cmd;
        if(cmd == 0){
            pop();
        } else {
            push(cmd);
        }
    }
    cout << calc_tot();
}