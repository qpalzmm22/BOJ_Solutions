// #include <bits/stdc++.h>

// using namespace std;

// const int MX = 102;
// int q[MX];
// int front, rear;

// int
// pop()
// {
//     int popped;
//     if(rear - front > 0){
//         popped = q[front];
//         front++;
//     } else {
//         popped = -1;
//         cout << "something wrong in pop" << "\n";
//     }
//     return popped;
// }   

// void
// push(int num)
// {
//     q[rear] = num;
//     rear++;
// }

// void
// rotateRight()
// {
//     int tmp = q[rear - 1];
//     int i = 1; 
//     while(rear - i - 1 != front){
//         q[rear - i] = q[rear-i-1]; 
//     }
//     q[front] = tmp;
// }

// void
// rotateLeft()
// {
//     int tmp = q[front];
//     int i = 0; 
//     while(front + i + 1 != rear - 1){
//         q[front + i] = q[front + i + 1]; 
//     }
//     q[rear - 1] = tmp;
// }
// //0123
// //012
// //120
// int
// main()
// {
//     // ios::sync_with_stdio(0);
//     // cin.tie(0);   
//     int n ;
//     int m ;
//     int num;
//     int tot = 0;
//     int iter = 0;

//     cin >> n >> m;
//     // create queue;
//     for(int i = 1; i <= n; i++){
//         push(i);
//     }
//     cout << "m: "<< m <<"\n";

//     while(m-- > 0 ){
//         cout << "here"<< "\n";
//         cin >> num;
//         while(1){

//             if(q[front] == num || front + iter == rear - iter){
//                 cout << "A";
//                 break;
//             }
            
//             if(q[front + iter] == num){
//                 // fix queue.
//                 for(int i = 0; i < iter; i++){
//                     rotateLeft();
//                 }        
//                 pop();
//                 tot += iter;
//                 cout << "B";
//                 iter = 0;
//                 break;

//             } else if(q[rear - iter] == num){
//                 // fix queue.
//                 for(int i = 0; i < iter; i++){
//                     rotateRight();
//                 }
//                 pop();
//                 tot += iter;
//                 cout << "C";
//                 iter = 0;
//                 break;
//             }
//             iter++;
//         }
//     }
//     cout << tot;

//     return 0;
// }

#include <bits/stdc++.h>

using namespace std;

deque<int> dq;

int 
main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    deque<int>::iterator iter1, iter2;
    
    int n, m;

    cin >> n >> m;
    
    for(int i = 1; i <= n; i++){
        dq.push_back(i);
    }

    int num;

    int tot = 0;
    while(m-- > 0){
        cin >> num;
        int count1 = 0, count2 = 1;
        
        if( dq.front() == num){
            dq.pop_front();
            continue;
        }
        
        for(iter1 = dq.begin(); iter1 != dq.end(); iter1++) {
            if (*iter1 == num) break; 
            else count1++; 
        }

        for(iter1= dq.end() -1; iter1 != dq.begin() ; iter1--) {
            if (*iter1 == num) break; 
            else count2++; 
        }
        if(count1 < count2){
            int tmp;
            for(int i = 0 ; i < count1 ; i++){
                tmp = dq.front();
                dq.pop_front();
                dq.push_back(tmp);
            }
            dq.pop_front();
            tot += count1;
        } else {
            int tmp;
            for(int i = 0 ; i < count2 ; i++){
                tmp = dq.back();
                dq.pop_back();
                dq.push_front(tmp);
            }
            dq.pop_front();
            tot += count2;
        }
    }
    cout << tot;    
    return 0;
}