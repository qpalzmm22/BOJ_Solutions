#include <iostream>
#include <cstring>

using namespace std;

int T;

string str;

// could solve with greedy? kj
// (100+1+ | 01)+
// 0,(outermost) 1((left), 2(left-left), 3(left-right) 4(right)
bool solve(int ind, int scope){
  //`cout << ind << " " << scope << "\n";
  if(scope == 0){
    if(ind >= str.length())
      return true;
    if(str.substr(ind, 2) == "01"){ // must be 01
      return solve(ind + 2, 0);
    } else if(str.substr(ind, 3) == "100"){ // must be 01
      return solve(ind+3, 1);
    } else {
      return false;
    }
  } else if(scope == 1){ // 100
    if(ind >= str.length())
      return false;
    if(str[ind] == '0'){
      return solve(ind+1, 1);
    } else{
      return solve(ind+1, 2);
    }
  } else{
    if(str[ind] == '1'){
      //if(ind >= str.length())
        //return false;
      return solve(ind+1, 2) || solve(ind, 0);
    }else {
      return solve(ind, 0);
    }
  }
}

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);

  cin >> T;

  while(T--){
    cin >> str;
    if(solve(0, 0)){
      cout << "YES" <<"\n";
    }else {
      cout << "NO" << "\n"; 
    }

  }
  return 0;
}
