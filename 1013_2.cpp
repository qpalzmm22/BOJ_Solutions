#include <iostream>
#include <regex>

using namespace std;

int T;

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);

  cin >> T;

  regex re("(100+1+|01)+");
  string str;

  while(T--){
    cin >> str;
    if(regex_match(str, re))
      cout << "YES\n"; 
    else
      cout << "NO\n"; 
  }
  return 0;
}
