#include <iostream>
#include <map>
#include <vector>

using namespace std;

int N;

class Room{
  private:
    string _name;
    map < string , Room > s;
  
  public :
    void addRoom(vector<string> names){
      if(names.size() == 0) return;

      string n = names[0];
      names.erase(names.begin());

      if(s.find(n) == s.end()){
        //cout << "not found insert" <<  n << "\n";
        Room r;
        r._name = n;
        r.addRoom(names);
        s.insert(make_pair(n ,r));
        
      }else{
        auto it = s.find(n);
        (*it).second.addRoom(names);
        //cout << "found insert " <<  n << "\n";
      }
    }

    void printRoom(int f){
      if(f != -1){
        for(int i = 0 ; i < f ; i++){
          cout << "--";
        }
        cout << _name << "\n";
      }
      auto it = s.begin();
      for(;it != s.end(); it++){
        (*it).second.printRoom(f + 1);
      }
    }
};

int main(){
  cin >> N;
  
  Room root;

  for(int i = 0 ; i < N; i++){

    int K;
    vector <string> names;
    cin >> K;
    for(int j = 0; j < K; j++){
      string str;
      cin >> str;
      names.push_back(str);
    }
    root.addRoom(names);
  }
  root.printRoom(-1);
}
