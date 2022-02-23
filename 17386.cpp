#include <iostream>

#define pii pair<int, int>

using namespace std;


int ccw(pii p1, pii p2, pii p3){
  long long x1 = p1.first;
  long long x2 = p2.first;
  long long x3 = p3.first;
  long long y1 = p1.second;
  long long y2 = p2.second;
  long long y3 = p3.second;

  long long ans = (x2-x1)*(y3-y1) - (y2-y1)*(x3-x1);
  if(ans > 0)
    return 1;
  else if(ans < 0)
    return -1;
  else
    return 0;
}

int main(){
  int x1, x2, x3, x4;
  int y1, y2, y3, y4;

  cin >> x1 >> y1 >> x2 >> y2;
  cin >> x3 >> y3 >> x4 >> y4;

  pii p1 = make_pair(x1, y1);
  pii p2 = make_pair(x2, y2);
  pii p3 = make_pair(x3, y3);
  pii p4 = make_pair(x4, y4);

  int subq1 = ccw(p1, p2, p3);
  int subq2 = ccw(p1, p2, p4);
  int subq3 = ccw(p3, p4, p1);
  int subq4 = ccw(p3, p4, p2);

  int q1 = subq1 * subq2;
  int q2 = subq3 * subq4;
  if(q1 < 0 && q2 < 0){
    cout << 1;
  } else {
    cout << 0;
  }

  return 0;
}
