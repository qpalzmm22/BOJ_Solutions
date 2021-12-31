// 1043
// 1. Person who knows the truth shouln't join the party
// 2. Person who had had party with Knowns shouldn't joing the party
// 3. Or peerosn who was with person who had party with Known...
// 4 .. so on.

#include <iostream>

using namespace std;

// 0 : nParty, 1:50 :parties with nums 
int parties[52][52];
int union_set[52];

void init_union()
{
    // Parent is my self. Starts from 1, not 0
    for(int i = 0; i < 51 ; i++){
        union_set[i] = i;
    }
}


// for debug
void print_union()
{  
    for(int i = 0; i < 51; i++){
        cout << union_set[i] << " ";
        if(i % 10 == 0)
            cout <<"\n"; 
    }
}

// find root node of x
int u_find(int x)
{
    int parent = union_set[x];
    if(parent == x)
        return x;
    else   
        return u_find(parent);
}

//  unions x and y (y to x) and returns the root node
void u_union(int x, int y)
{   
    if(x == y)
        return ;
    //cout << "(x,y) = [ "<< x << y << "]\n";
    //cout << "debug : u_find : [" << union_set[u_find(y)] << ", " << x << "]\n";
    union_set[u_find(y)] = u_find(x);
}

int main()
{
    int N, M; 
    int lies  = 0;
    int nKnow;
    int pNum;
    int i = 0;

    cin >> N >> M;
    
    cin >> nKnow;

    init_union();

    int p = 0;

    // union knowns
    while(i < nKnow){
        cin >> pNum;   

        u_union(p, pNum);
        p = pNum;
        i++;
    }

    i = 0;
    // group party members and make them union
    while(i < M){
        int p_inParty = 0;
        
        cin >> p_inParty;
        parties[i][0] = p_inParty;

        int p = 0;
        int q;
        int j = 0;
        while(j < p_inParty){
            cin >> q;
            if(p == 0)
                p = q;
            u_union(p, q);
            p = q;

            parties[i][j + 1] = q;
            j++;
        }
        i++;
    }
    //print_union();

    for(i = 0 ; i < M ; i ++){
        int noLie = 0;
        for(int j = 0 ; j < parties[i][0]; j++){
            
            if(u_find(parties[i][j + 1]) == u_find(0)) // in the same unions
                noLie = 1;
               
        }
        if(noLie == 0){
            lies++;
        }
    }
    cout << lies;
    return 0;
}