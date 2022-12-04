#include <iostream>
#include <vector>


#define pii pair<int,int>

using namespace std;

int N;
vector< pii > coords;


double crossProduct(double x1, double x2, double x3, double y1, double y2, double y3){
  return ((x1*y2 + x2*y3 + x3*y1) - (x2*y1+ x3*y2 + x1*y3)) / 2;
}
int main()
{
  cin >> N;

  int x, y;
  int totN = N;
  double area = 0;

  
  while(N--){
    cin >> x >> y;
    
    pii p;
    p.first = x;
    p.second = y;

    coords.push_back(p);
  }

  for(int i = 1 ; i < totN; i++){
    area += crossProduct(coords[0].first, coords[i-1].first, coords[i].first, coords[0].second, coords[i-1].second, coords[i].second);
  }

  if(area < 0 ) area = -1 * area;
  printf("%.1f", area);
}
