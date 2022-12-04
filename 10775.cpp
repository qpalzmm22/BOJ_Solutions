#include <iostream>

int G, P;
int port[100005];

using namespace std;

// First Thought : Greedy with little data structure? => O(n)
// Correction : use union find and time complexity will be soemthing like that 

int find(int a){
  if(a == port[a])
    return a;
  else 
    return port[a] = find(port[a]);
}

// a is always smaller
void uni(int a, int b){
  int u = find(a);
  int v = find(b);

  port[v] = u; 
}

void printP(){
  for(int i = 0 ; i <= G; i++){
    cout << port[i] << " "; 
  }
  cout << "\n"; 
}
int main(){
  cin >> G >> P;

  for(int i = 0 ; i <= G; i++){
    port[i] = i;
  }

  int tmp;
  int ans = P;
  for(int i = 0 ; i < P; i++){
    int g;
    cin >> g;

    if(port[g] == g){
      uni(g-1, g); // into port g 
      tmp = g;
    } else {
      tmp = find(g); 
      if(tmp == 0){
        ans = i;
        break;
      } else {
        int next_port = tmp - 1;
        uni(next_port, tmp);  // into available port that is less than g
      }
    }
    //printP();
    //cout << g << " into port " << tmp << "\n"; 
  }
  cout << ans << "\n";
  return 0;
}
