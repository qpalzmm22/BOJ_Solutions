#include <iostream>
#include <stack>

using namespace std;



int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    stack<pair<int, int>> my_stack;
    int n ;

    cin >> n;
    int i = 1;
    my_stack.push({100000001, 0});

    int num;
    while(n-- > 0){
        cin >> num;
        while( my_stack.top().first < num){
            my_stack.pop();
        }
        cout << my_stack.top().second << " ";

        my_stack.push({num, i++});
    }
    return 0;
}