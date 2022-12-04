#include <iostream>
#include <queue>
#include <map>

using namespace std;

int N;
// SMA (stable marriage algorithm)
int manpref[1005][1005]; // 1005 * 1005 = 100 0000 = 300kb  i = who j : whom
map < int, int > womanpref[1005]; // man : priority

int manOrder[1005]; // starts from 0
int engage[1005]; // in woman perspective
int manEngage[1005]; // man perspective
queue<int> q;

int main(){
  cin >> N;

  // man preference
  for(int i = 1; i <= N; i++){
    for(int j = 0; j < N; j++){
      cin >> manpref[i][j]; 
    }
    q.push(i);
  }

  // woman preference
  for(int i = 1; i <= N; i++){
    for(int j = 1; j <= N; j++){
      int wpref;
      cin >> wpref;
      womanpref[i].insert(make_pair(wpref, j));
    }
  }
  
  while(!q.empty()){
    int man = q.front();
    q.pop();
    
    //cout << "man : " << man << "\n"; 
    
    bool engaged = false;
    while( !engaged ){
      int order = manOrder[man] ;
      manOrder[man] = order + 1;
      int woman = manpref[man][order];
      
      //cout << "man : " << man << "order : " << order  << " want : "<< woman << "\n"; 
      // propose
      if(engage[woman] == 0){ // not engaged  
        //cout << woman << " woman not  engaged\n"; 
        engage[woman] = man;
        manEngage[man] = woman;
        engaged = true;
      } else{
        //cout << womanpref[woman][man] << " " << womanpref[woman][engage[woman]] << "\n"; 
        if(womanpref[woman][man] < womanpref[woman][engage[woman]]){ // if new man is more prefered than engaged partner
          //cout << woman << " likes " << man << " over " << engage[woman] << "\n"; 
          int disenagedman = engage[woman]; //
          manEngage[man] = woman;
          engage[woman] = man; // replace it
          q.push(disenagedman); // the man becomes disengaged
          engaged = true;
        }
      }
    }
  }
  
  for(int i = 1 ; i <= N; i++){
    cout << manEngage[i] ;
    //cout << i << " " << engage[i] ;
    cout << "\n";
  }

  return 0;
}
