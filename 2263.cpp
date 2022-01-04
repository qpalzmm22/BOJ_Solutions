#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <queue>
#include <unistd.h>

// last letter of postfix = root
// infix seperates post and in
using namespace std;

int pre[100005];
int in[100005];
int post[100005]; // saves index of the

queue<int> Q; // saves the val

// goes by index(0 ~ N-1)
void process(int p_s, int p_e, int i_s, int i_e, int n){

    //cout  << "[ " << p_s << " " << p_e << " " << i_s << " " << i_e << " " << n << "]\n";
    if(n == 0) return;

    int root = pre[p_e];
    int * p = find(in + i_s, in + i_s + n, root);
    if(p == in + i_s+ n){
        fprintf(stderr, "p == in + n");
        exit(1);
    }
    int in_ind = p - in ;
    int l_n = in_ind - i_s ;
    int r_n = i_e - in_ind;
    // 0 ~ in_ind = l, in_ind ~ in + size = r

    Q.push(root);

    int lp_s = p_s;
    int lp_e = lp_s + l_n - 1 ;
    int li_s = in_ind - l_n ;
    int li_e = in_ind - 1;

    int rp_s = lp_e + 1;
    int rp_e = rp_s + r_n - 1;
    int ri_s = in_ind + 1;
    int ri_e = in_ind + r_n;

    //sleep(2);
    process(lp_s, lp_e, li_s, li_e, l_n);
    process(rp_s, rp_e, ri_s, ri_e, r_n);
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

    process(0, N - 1, 0, N - 1, N);

    while(!Q.empty()){
        cout << Q.front() << " ";
        Q.pop();
    }
    return 0;
}