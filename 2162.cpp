#include <iostream>
#include <vector>

#define pii pair<int, int >
#define ppii pair< pii, pii >

using namespace std;

int N;
vector<ppii > segs;

int parent[3005];

int uni_find(int a){
  if(parent[a] < 0){
    return a;
  }else{
    parent[a] = uni_find(parent[a]);
    return parent[a];
  }
}
void uni_union(int a, int b){
  int pa = uni_find(a);
  int pb = uni_find(b);
  
  //cout << ">> " << parent[pa] << " " << parent[pb] << "\n";
  parent[pa] += parent[pb];
  parent[pb] = pa;
}

void set_uni(){
  for(int i = 0; i < N; i++){
    parent[i] = -1;
  }
}


long long ccw(pii p1, pii p2, pii p3){
  long long x1 = p1.first;
  long long x2 = p2.first;
  long long x3 = p3.first;
  long long y1 = p1.second;
  long long y2 = p2.second;
  long long y3 = p3.second;

  long long ans = (x2 - x1) * (y3 - y1) - (y2 - y1) * (x3 - x1);

  if( ans > 0 ) return 1;
  else if(ans < 0 ) return -1;
  else return 0;
}

bool is_connected(ppii seg1, ppii seg2){
  
  pii p1 = seg1.first;
  pii p2 = seg1.second;
  pii p3 = seg2.first;
  pii p4 = seg2.second;

  int x1 = p1.first;
  int x2 = p2.first;
  int x3 = p3.first;
  int x4 = p4.first;

  int y1 = p1.second;
  int y2 = p2.second;
  int y3 = p3.second;
  int y4 = p4.second;

  int subq1 = ccw(p1, p2, p3);
  int subq2 = ccw(p1, p2, p4);
  int subq3 = ccw(p3, p4, p1);
  int subq4 = ccw(p3, p4, p2);

  if(subq1 * subq2 <= 0 && subq3 * subq4 <= 0){
    if(subq1 == 0 && subq2 == 0 && subq3 == 0 && subq4 == 0){
      if(p2 < p1){
        pii tmp = p1;
        p1 = p2;
        p2 = tmp;
      }
      if(p4 < p3){
        pii tmp = p3;
        p3 = p4;
        p4 = tmp;
      }

      if(p1 <= p4 && p3 <= p2){
        return true;
      } else{
        return false;
      }
    } else {
      return true;
    }
  } else {
    return false;
  }
}

int main(){
  cin >> N;
  for(int i = 0 ; i < N; i++){
    int x1,y1,x2,y2;

    cin >> x1 >> y1 >> x2 >> y2;

    segs.push_back(make_pair(make_pair(x1, y1), make_pair(x2, y2)));
  }

  int groups = N;

  set_uni();
  for(int i = 0; i < N; i++){
    for(int j = i + 1; j < N; j++){
      
      if(uni_find(i) == uni_find(j))
        continue;

      if(is_connected(segs[i], segs[j])){
        groups--;
        uni_union(i, j);
      }
    }
  }
  int largest = 0;
  for(int i = 0; i < N; i++){
    //cout << "> " << parent[i] << "\n"; 
    largest = max(largest, -1 * parent[i]);
  }
  cout << groups << "\n" << largest;

  return 0;
}
