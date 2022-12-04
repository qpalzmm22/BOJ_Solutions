#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

#define pii pair < int, int >

using namespace std;

int N;

pii lines[100005];

int dp[100005]; // -last value
vector <int> ans;
// first thought : very similar to Longest Increasing Subsqeunce problem 

map < int , int > m;

bool cmp (pii a, pii b){
  return a.second < b.second;
}

void printLines(){
  cout << "-----------------------\n";
  for(int i = 0 ; i < N ; i++){
    cout << lines[i].first << " " << lines[i].second << "\n";
  }
}

void printAns(){
  cout << "---ANS--------------------\n";
  for(int i = 0 ; i < ans.size() ; i++){
    cout << ans[i] << " ";
  }
  cout <<"\n";
}
void printDP(){
  cout << "---DP--------------------\n";
  for(int i = 0 ; i < N ; i++){
    cout << dp[i] << " ";
  }
  cout <<"\n";
}
int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  cin >> N; 

  for(int i = 0 ; i < N; i++){
    int leftLine;
    int rightLine;
    cin >> leftLine >> rightLine ;
    lines[i] = make_pair(leftLine, rightLine);
    
  }

  sort(lines, lines + N, cmp);
  
  //printLines();

  ans.push_back(lines[0].first);
  m.insert(make_pair(lines[0].first, 0)); //  key = value, value = index
  dp[0] = -1;
  for(int i = 1 ; i < N ; i++){
    m.insert(make_pair(lines[i].first, i));

    if(ans.back() < lines[i].first){
      dp[i] = m[ans.back()];
      ans.push_back(lines[i].first);
    } else {
      int idx = lower_bound(ans.begin(), ans.end(), lines[i].first) - ans.begin() ;
      //cout << "idx : " << idx << " \n";
      if(idx == 0){
        dp[i] = -1;
      } else {
        dp[i] = m[ans[idx-1]];
      }
      ans[idx] = lines[i].first;
    }
    //printAns();
    //printDP();
  }

  int val = ans.back();
  while(1){
    int prev_idx = dp[m[val]];
    m.erase(val);
    if(prev_idx == -1)
      break;
    int newval = lines[prev_idx].first;
    //cout << val << " "  << newval << "\n";
    val = newval;
  }
  
  cout << m.size() << "\n";
  for(auto i = m.begin() ; i != m.end() ; i++){
    cout << (*i).first << "\n";
  }

  return 0;
}
