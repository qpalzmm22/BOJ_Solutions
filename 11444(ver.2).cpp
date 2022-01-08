// Solve with Daganu ...
// F2n = Fn-1Fn + FnFn+1
#include <iostream>
#include <cmath>

#define DIVISOR 1000000007
#define sqrt5 sqrt(5)

using namespace std ;

double plusdp[60]; // ((1+5^(1/2)^2)^i / 5^(1/2)
double minusdp[60]; // ((1-5^(1/2)^2)^i / 5^(1/2)

double pluspow(long long n){
    long long exp = floor(log2(n));
    long long one = 1;
    long long rest = n - (one << exp);
    double result;

    if(rest == 0 && plusdp[exp] != 0){
        return plusdp[exp];
    }

    if(rest == 0){
        plusdp[exp] = fmod(pluspow(n/2) * pluspow(n/2), DIVISOR);
        result = plusdp[exp];
    } else{
        result = fmod(pluspow(n - rest) * pluspow(rest), DIVISOR);
    }
      
    return result;
}

double minuspow(long long n){
    long long exp = floor(log2(n));
    long long one = 1;
    long long rest = n - (one << exp);
    double result;   

    if(rest == 0 && minusdp[exp] != 0){
        return minusdp[exp];
    }

    if(rest == 0){
        minusdp[exp] = fmod(minuspow(n/2) * minuspow(n/2), DIVISOR);
        //minusdp[exp] = minuspow(n/2) * minuspow(n/2);
        result = minusdp[exp];
    } else{
        result = fmod(minuspow(n - rest) * minuspow(rest), DIVISOR);
        //result = minuspow(n - rest) * minuspow(rest);
        // (((int)(pluspow(one << exp) * sqrt5) % DIVIDOR) * ((int)(pluspow(rest)  * sqrt5) % DIVIDOR)) / sqrt5 ;
    }
      
    return result;
}

double fib(long long n){
    double p1 = pluspow(n); 
    double p2 = minuspow(n);
    printf("plus : %lf, minus : %lf\n",p1,p2);
    
    return (pluspow(n) - minuspow(n)) / sqrt5;
}   

void printdp(int n){
    for(int i = 0 ; i < log2(n); i++){
        cout << i << "] [" << plusdp[i] << "] [" << minusdp[i] << "]\n";
    }
}

int main(){
    long long n;

    cin >> n;
    
    //plusdp[0] = fmod( (1 + sqrt5) / 2  , DIVISOR);
    //minusdp[0] = fmod( (1 - sqrt5) / 2  , DIVISOR);
    plusdp[0] = (1 + sqrt5) / 2;
    minusdp[0] = (1 - sqrt5) / 2;

    printf("%lf\n", fib(n));
    printdp(n);
    return 0;
}