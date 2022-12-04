#include <iostream>
#include <regex>
using namespace std;



int main(){
  
  regex re("(100+1+|01)+");

  string str;
  cin >> str;
  if(regex_match(str, re)){
    cout << "SUBMARINE";
  } else {
    cout << "NOISE";
  }

  return 0;
}
