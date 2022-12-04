#include <iostream>
#include <limits.h>

using namespace std;

int N;
string exp;


// only works for 3 letters
long long calc(long long lop, char op, long long rop){
  if(op == '+'){
    return lop + rop;
  } else if(op == '*'){
    return lop * rop;
  }else { // op == '-'
    return lop - rop;
  }
}

long long maxCalc(){
  long long maxVal = INT_MIN;
  for(int i = 0 ; i < 1 << (N / 2); i++){
    if( ((i << 1)  & i) != 0 || ((i >> 1) & i) != 0) 
      continue;

    // Calulate ()s first
    long long sum = 0 ;
    char l_operator = '+';

    for(int j = 0 ; j < N / 2; j++){
      int idx = j * 2 + 1;
      //char idxop = exp[idx];
      
      int lop = exp[idx-1] - '0';
      int rop = exp[idx+1] - '0';

      if(i & (1 << j)){ // it's enwrapped
        sum = calc(sum, l_operator, calc(lop, exp[idx], rop));
        if(idx + 2 >= exp.size())
          break;
        l_operator = exp[idx + 2];
        j++;
      } else{
        sum = calc(sum, l_operator, lop);
        l_operator = exp[idx];
        //if(idx + 2 >= exp.size())
        //  sum = calc(sum, l_operator, rop);
      }
      //cout << idx <<" : " << sum << "\n";
    }
    maxVal = max(maxVal, sum);
    //cout << i << " " << maxVal << "\n";
    // Calculate the rest
  }
  return maxVal;
}
int main(){
  
  cin >> N;
  cin >> exp;
  N +=2;
  exp += "+0";
  cout << maxCalc();
  return 0;
}
