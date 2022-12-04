#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define pii pair < int, int >

// if a1 > a2 && b1 < b2 || a1 < a2 && b1 > b2 == crossing
// greedy => From largest crossing, we take it out
//  ==> is there case where largeset crossing doesn't get included in the
//  answer? 
//  Or we can find out which ones are crsosing each other. 
// Draw "graph" and cut off the edges as we go. 
// --- > FAIL
// Greedy doesn't work. We need to use DP somehow

using namespace std;
int N;

int leftLine[105];
int rightLine[105];

int concnt[105]; // idx = from,  cnt , towhat
int crosscnt = 0;
int total = 0;

vector < int > adj[105];

bool cmp(pii a, pii b){
  return a.first > b.first;
}

bool iscrossing(int a1, int a2, int b1, int b2){
  return ((a1 > a2 && b1 < b2) || (a1 < a2 && b1 > b2));
}

void printCrossCnt(){
  cout <<"------------------------\n";
  for(int i = 0 ; i < N; i++){
    cout << i <<  " : " << concnt[i] << "\n";
  }
}

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  cin >> N;

  for(int i = 0 ; i < N; i++){
    cin >> leftLine[i] >> rightLine[i]; 
  }

  //(O(N^2)
  for(int i = 0 ; i < N - 1 ; i++){
    for(int j = i + 1 ; j < N ; j++){
      if(iscrossing(leftLine[i], leftLine[j], rightLine[i], rightLine[j])){
        adj[i].push_back(j);
        adj[j].push_back(i);
        concnt[i]++;
        concnt[j]++;
        crosscnt++ ;
        
      }
    }
  }

  // 1. sort by adj size => using pq?
  // => not working
  // 2. get max by using O(n^2)

  // get rid of adj nodes that are connected 
  
  int i = 0;
  while(crosscnt > 0){
    // O(N)
    int idx = max_element(concnt, concnt + N) - concnt ;

    //cout << "idx : " <<  idx  << "value : " << concnt[idx] << "\n";
    printCrossCnt();
    if(adj[idx].size() == 0 )
      break;
    total++;
    for(int i = 0 ; i < adj[idx].size(); i++){
      if(concnt[adj[idx][i]] == 0)
        continue;
      concnt[idx]--;
      concnt[adj[idx][i]]--;
      crosscnt--;
    }
    i++;
  }

  cout << total << "\n";
  return 0;
}
