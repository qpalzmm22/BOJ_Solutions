#include <iostream>
#include <cmath>

#define PRIME 1000000007

using namespace std;

long long  rem[32];

long long  calc(int b){
    
    int lg2b = floor(log2(b));
    int msb = 1 << lg2b;
    long long  rest = b - msb;
    //cout << lg2b << " " << b << "\n";
    if(rest == 0){
        if(rem[lg2b] != -1){
            //cout << rem[lg2b] << " <=\n";
            return rem[lg2b];
        }
        rem[lg2b] = (calc(b/2) * calc(b/2)) % PRIME;
        //cout << rem[lg2b] << " <==\n";
        return rem[lg2b];
    } else {
        return (calc(msb) * calc(rest)) % PRIME;
    }
}


int bInverse(int b){
    
    int bInv = 0; // initial val
    int lg[30];

    return bInv;
}

void initRem(int val){
    for(int i = 0 ; i < 32; i++){
        rem[i] = -1;
    }
    rem[0] = val;
}

int main(){
    int M;

    cin >> M;
    long long result = 0;

    long long CDN = 1;
    long long by = 0; 
    while(M--){
        int N, S;
        cin >> N >> S;
        
        by = ((by * N) % PRIME + (S * CDN) % PRIME) % PRIME; 
        CDN = (CDN * N) % PRIME;
        
    }
    //cout << by << " " << CDN << "\n"; 
    initRem(CDN);
    result = (calc(PRIME - 2) * (by)) % PRIME;

    cout << result;
    return 0;
}