#include <iostream>

using namespace std;

const int MAX_STACK = 100005;

int my_stack[MAX_STACK];
int pos;

void
push(int n){
    my_stack[pos++] = n;
}

int
pop(){
    pos--;
    return my_stack[pos];
}

int
top(){
    return my_stack[pos-1];
}


int main(){
    int n;
    int i = 0;
    int num = 1;
    int tmp;
    char ans_arr[2 * MAX_STACK];

    cin >> n;                                                                                         
    int nums = n *2;
    cin >> tmp;
    while(nums-- > 0){
        if(pos != 0 && top() == tmp){
            ans_arr[i++] = '-';
            pop();
            if(nums != 0)
                cin >> tmp;
        } else{
            push(num++);
            ans_arr[i++] = '+';
        }
    }
    if(pos != 0){
        cout << "NO";
        return 0;
    } else {
        for(int i = 0 ; i < 2*n ; i++){
            cout << ans_arr[i] << "\n";
        }
    }


    return 0;
}