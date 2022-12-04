#include <iostream>
#include <cmath>
#define pii pair < int, int >
using namespace std;

int calc_dist(int x1, int y1, int x2, int y2){
  return (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2);
}

// exclusive
 // always 1s are bigger
bool in_circle(int x1, int y1, int r1, int x2, int y2, int r2){
  
  int dist = calc_dist(x1, y1, x2, y2);
  
  if(dist <= pow(r1, 2))
    return true;
  else
    return false;
}

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);

  int T;
  cin >> T;

  int x1, y1, r1, x2, y2, r2;

  while(T--){
    cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
    int dist = calc_dist(x1, y1, x2, y2);
    /*
    if(r1 + r2 > dist){
      if( r1 - r2  == dist || r1 - r2 == -1 * dist){
        cout << 1;
      }
    } else if( r1 + r2  == dist){
      if(dist == 0){
        cout << -1;
      } else{
        cout << 1; 
      }
    } else { // r1 + r2 < dist
      cout << 0;
    }
    
    if(r1 + r2 == dist){
      cout << 1;
    } else if(r1 == r2 && dist == 0){
      cout << -1;
    } else if(r1 - r2 == dist || r1 - r2 == -1 * dist){
      cout << 1;
    } else if(in_circle(x1, y1, r1, x2, y2, r2)){
        if(r2 + r1 < dist){
          cout << 0;
        }else
          cout << 2;
    } else {
      cout << 2;
    }
    */
    if(r2 > r1){
      swap(x1, x2);
      swap(y1, y2);
      swap(r1, r2);
    }

    bool is_in_circle = in_circle(x1, y1, r1, x2, y2, r2);

    //cout << "\n" << r1 << " " << r2 << " " << dist << " "  << is_in_circle << "\n";
    
    if(is_in_circle){
      if(r1 == r2 && dist == 0){
        cout << -1;
      } else if(pow(r1 - r2, 2) == dist){
        cout << 1;
      } else if(dist < pow(r1 - r2, 2)){
        cout << 0;
      } else {
        cout << 2;
      }
    } else{
      if(pow(r1 + r2, 2) > dist){
        cout << 2;
      } else if(pow(r1 + r2, 2) == dist){
        cout << 1;
      } else {
        cout << 0;
      }
    }
    cout <<"\n";
  }


  return 0;
}
