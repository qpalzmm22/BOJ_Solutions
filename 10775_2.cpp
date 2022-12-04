#include <iostream>
#include <algorithm>

using namespace std;

int G, P;
int p[100005];

int find(int a){
  if(p[a] == a){
    return a;
  }
  return p[a] = find(p[a]);
}
void printP(){
  cout << "P : \n";
  for(int i = 0 ; i <= G; i++){
    cout << p[i] << " ";
  }
}

void uni(int a, int b){
  int u = find(a);
  int v = find(b);
  if(u == v)
    return;

  if(u > v){
    swap(u, v);
  }
  p[v] = u;
}

int main(){
  cin >> G >> P;

  for(int i = 0; i <= G; i++){
    p[i] = i;
  }

  int poss = 0;
  for(int i = 0; i < P; i++){
    int airplane;
    cin >> airplane;

    int prev = find(airplane);
    if(prev == 0){
      break;
    }
    uni(prev - 1, airplane);
    poss++;
  }

  cout << poss;
  
  return 0;
}
