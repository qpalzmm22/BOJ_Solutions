#include <bits/stdc++.h>

using namespace std;

const int MAX = 10000;
int dq[2 * MAX + 1];
int head = MAX, tail = MAX; 

int
size()
{
    return tail - head;
}

bool
empty()
{
    if(size() == 0) return true;
    else return false;
}

int
front()
{
    if(!empty()){
        return dq[head + 1];
    } else {
        return -1;
    }
}

int
back()
{
    if(!empty()){
        return dq[tail];
    } else {
        return -1;
    }
}

void
push_front(int x)
{
    dq[head--] = x;  
}

void
push_back(int x)
{
    dq[++tail] = x;
}

void
pop_front()
{
    if(!empty()){
        head++;
    }
}

void
pop_back()
{
    if(!empty()){
        tail--;
    }
}

int
main(){
  push_back(30); // 30
  cout << front() << '\n'; // 30
  cout << back() << '\n'; // 30
  push_front(25); // 25 30
  push_back(12); // 25 30 12
  cout << back() << '\n'; // 12
  push_back(62); // 25 30 12 62
  pop_front(); // 30 12 62
  cout << front() << '\n'; // 30
  pop_front(); // 12 62
  cout << back() << '\n'; // 62
    return 0;
}