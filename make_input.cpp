#include <iostream>
#include <time.h>

using namespace std;

int main(){

  srand(time(NULL));
  
  cout << "100000\n";
  for(int i = 1; i <= 100000; i++){
    cout << i << " " << 100001 -i << "\n";
  }
  return 0;
}
