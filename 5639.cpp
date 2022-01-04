#include <iostream>
#include <vector>

using namespace std;

int preorder[100005];

void printTree(int * tree, int n){
    for(int i = 0 ; i < n; i++){
        cout << tree[i] << " ";
    }
}

void preTraversal(int from, int to){
    //cout << " [" << from << " " << to << "]\n";
    if(from == to) {
        cout <<  preorder[from] << "\n";
        return ;
    }   

    int root = from;

    int small_end = from;
    for(int i = from ; i <= to; i++){
        if(preorder[i] > preorder[root])
            break;
        small_end = i;
    }
    //cout << " smallend=" << small_end << "]\n";
    if(small_end > from)
        preTraversal(from + 1, small_end);
    if(to > small_end) 
        preTraversal(small_end + 1, to);
    cout << preorder[root] << "\n";
}

int main(){

    int n = 0;
    while(scanf("%d", &preorder[n]) != EOF){
        n++;
    }

    //printTree(preorder, n);
    //cout <<"-----------------\n";
    preTraversal(0, n - 1);


    return 0;
}