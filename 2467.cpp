#include <iostream>
#include <cstdlib>
#define MAX 2e9
using namespace std;

int N;

int list[100005];


// finds one that makes it most 0?
int search(int i, int start, int end, int negMIN, int posMIN){

  //cout << i << " " << start << " " << end << "\n";

  int mid = (end + start) / 2;
  int n1 = list[i];
  int n2 = list[mid];
  
  if(start > end){
    if( abs(n1 + list[negMIN]) > abs(n1 + list[posMIN]))
      return posMIN;
    else
      return negMIN;
  }
  if(n1 + n2 < 0){ // search right
    return search(i, mid + 1, end, mid, posMIN);
  } else if(n1 + n2 > 0){
    return search(i, start, mid - 1, negMIN, mid);
  } else{
    return mid;
  }
}
int main(){

  cin >> N; 
  for(int i = 0; i < N; i++){
    cin >> list[i];
  }

  int minAcid = MAX;
  int n1, n2;
  for(int i = 0; i < N - 1; i++){
    int ind = search(i, i+1, N-1, i+1, N-1);
    int diff = abs(list[ind] + list[i]);
    if(minAcid > diff ){
      minAcid = diff;
      n1 = list[i];
      n2 = list[ind];
    }
    //cout << minAcid << "----\n";
  }
  cout << n1 << " " << n2;

  return 0;
}
