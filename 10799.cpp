#include <iostream>

using namespace std;

int main(){
  string str;

  cin >> str;
  int count = 0;
  int tot = 0;
  for(int i = 0; i < str.size(); i++){
    if(str[i] == '(')
      count++;
    else{
      if(str[i - 1] == '('){
        count--;
        tot += count;
      } else{
        count--;
        tot++;
      }
    }
  }
  cout << tot;

  return 0;
}
