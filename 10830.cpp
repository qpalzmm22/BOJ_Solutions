#include <iostream>
#include <vector>
#include <tgmath.h>

// use divide and conquer
using namespace std;

vector <vector <int> > memoi[40];
int filled[40];
int N;

//n^2
vector <vector <int> > multMatrix(vector <vector <int> > &A, vector <vector <int> > &B){
    vector <vector <int> > C;
    for(int i = 0; i < N ; i++){
        vector<int> row(N);
        for(int j = 0; j < N; j++){
            for(int k = 0 ; k < N ; k++){
                row[j] =  (row[j] + (A[i][k] * B[k][j]) % 1000) % 1000;
            }
        }
        C.push_back(row);
    }
    return C;
}

// vector <vector <int> > addMatrix(vector <vector <int> > &A, vector <vector <int> > &B){
//     vector <vector <int> > C;
//     for(int i = 0; i < N ; i++){
//         vector<int> row(N);
//         for(int j = 0; j < N; j++){
//             row[j] += (A[i][j] + B[i][j]) % 1000;
//         }
//         C.push_back(row);
//     }
//     return C;
// }


vector <vector <int> > matrixPow(vector <vector <int> > &A, long long B){
    vector <vector <int> > m1 ;
    vector <vector <int> > m2 ;
    vector <vector <int> > m3 ;
 
    long long msb = floor(log2(B));
    long long one = 1;
    long long rest = B - ( one << msb); 

    // cout << "B : [" << B << "] msb : [" << msb <<  "] \n";
    if(rest == 0 && filled[msb]){
        return memoi[msb];
    }
    // cout << "---- Deeper ---- \n";
    if(rest == 0){
        m1 = matrixPow(A, (one << (msb-1)) );
        m2 = matrixPow(A, (one << (msb-1)) );
        m3 = multMatrix(m1, m2);

        memoi[msb] = m3;
        filled[msb] = 1;
    } else{
        m1 = matrixPow(A, (one << msb));
        m2 = matrixPow(A, rest);
        m3 = multMatrix(m1, m2);
    }

    return m3;
}

void initMemoi(){
    for(int n = 0; n < 40; n++){
        for(int i = 0 ; i < N ; i++){
            vector <int> row;
            for(int j = 0; j < N; j++){
                row.push_back(0);
            }
            memoi[n].push_back(row);
        }
    }
}

void printMatrix(vector <vector <int> > &A){
    //cout << "printing :" << N << " - N \n";
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < N ; j++){
            cout << A[i][j] << " ";
        }
        cout << "\n";
    }
    //cout << "print done\n";
}

int main(){

    long long B;
    vector <vector <int> > A;
    cin >> N >> B;

    for(int i = 0; i < N; i++){
        vector <int> row;
        for(int j = 0; j < N; j++){
            int elem;

            cin >> elem;
            row.push_back(elem % 1000);
        }
        A.push_back(row);
    }
    
    initMemoi();
    memoi[0] = A;
    filled[0] = 1;

    //printMatrix(A);

    vector <vector <int> > result;// = multMatrix(A, A);
    
    result = matrixPow(A, B);

    printMatrix(result);


    return 0;
}