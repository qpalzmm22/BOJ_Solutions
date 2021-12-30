#include <iostream>


using namespace std;
pair<char, char> nodes[100]; // left, right // index == A ~ Z


void preorder(char n){
    if(n == '.')
        return;
    cout << n;
    preorder(nodes[n].first);
    preorder(nodes[n].second);
}
void postorder(char n){
    if(n == '.')
        return;
    postorder(nodes[n].first);
    postorder(nodes[n].second);
    cout << n;
}
void inorder(char n){
    if(n == '.')
        return;
    inorder(nodes[n].first);
    cout << n;
    inorder(nodes[n].second);
}   
int main(){
    int N;

    cin >> N ;

    while(N--){
        char node;
        char left, right;
        cin >> node >> left >> right;
        nodes[node] = make_pair(left, right);
    }

    // preorder
    preorder('A');
    cout << "\n";
    // inorder
    inorder('A');
    cout << "\n";
    // postorder
    postorder('A');

    return 0;
}