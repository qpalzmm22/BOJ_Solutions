// first approach : sort bags by ascending order and jewels in price descending
// order.
// Per bag, chose a jewels that is most expensive. (greedy)

#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <queue>

#define pii pair <int, int>
#define MAX 300005

using namespace std;

int N, K;
//priority_queue < pii > jewels;
pii jewels[MAX];
priority_queue < int > bags;
priority_queue < int > possible_jewels;

bool compare(pii a, pii b){
  if(a.first == b.first) {
    return a.second > b.second;
  }
  else {
    return a.first < b.first;
  }
}

int main(){
  cin >> N >> K; 

  for(int i = 0; i < N; i++){
    int price, weight;
    cin >> weight >> price;
    pii p = make_pair(weight, price);
    //jewels.push(p);
    jewels[i] = p;
  }

  sort(jewels, jewels + N);

  for(int i = 0; i < K; i++){
    int cap;
    cin >> cap;
    bags.push(-1 * cap);
  }

  long long tot_price = 0;
  int index = 0;
  
  while(!bags.empty()){
    int cap = -1 * bags.top();
    bags.pop();

    //cout << ">> cap : " << cap << "\n"; 
    int price = 0;

    /*
    for(int i = 0; i < jewels.size(); i++){
      //cout << ">>> "<< jewels.size() << "\n"; 
      if(jewels[i].first <= cap){
        tot_price += jewels[i].first;
        //cout << "cap : " << cap << " price : " << jewels[i].first << "\n"; 
        jewels.erase( jewels.begin() + i );
        break;
      }
    }
    */
    while(index < N && jewels[index].first <= cap){
      possible_jewels.push(jewels[index].second);
      //cout << " >> price " << jewels[index].second << "\n";
      index++;
    }
   if(!possible_jewels.empty()){
      tot_price += possible_jewels.top();
      //cout << "price " << possible_jewels.top() << "\n";
      possible_jewels.pop();
    }
  }
  cout << tot_price;
  return 0;
}
