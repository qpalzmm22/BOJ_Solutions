#include <iostream>
#include <stack>

using namespace std;

// int main()
// {
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);

//     stack<int> my_stack;

//     int n ;

//     cin >> n;
//     int tot = 0;
//     while( n-- > 0 ){
//         int height;
        
//         cin >> height;
//         while( !my_stack.empty() && my_stack.top() <= height){
//             my_stack.pop();
//         }
//         tot += my_stack.size();

//         my_stack.push(height);
//     }
//     cout << tot;

//     return 0;
// }





// 이거 왜안됨..??? => long long 이 아니여서.. 킹받네

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;

    cin >> n;
    stack<int> my_stack;
    stack<pair<int, int>> ans;
    
    for(int i = 0; i < n; i ++){
        int num;
        cin >> num;
        my_stack.push(num);
    }

    ans.push({1000000001, 0});
    long long count = 0;

    for(int i = 0; i < n; i++){
        int num = my_stack.top();
        my_stack.pop();
        int can_see = 0;
        while(ans.top().first < num){
            can_see++;
            can_see += ans.top().second;

            // cout << ans.top().first << " " << ans.top().second << " " << num << " " << can_see << "\n"; 
            ans.pop();
        }
        count += can_see;
        ans.push({num, can_see});
    }
    cout << count;

    return 0;
}