#include <iostream>

#define FILLED 0b111111111 // 0 means possible

using namespace std;



int pass[9][9];
void printPass(){
  for(int i = 0; i < 9; i++){
    for(int j = 0; j < 9; j++){
      cout << pass[i][j];
    }
    cout << "\n";
  }
}

bool checkHor(int i, int num){
  for(int j = 0; j < 9; j++){
    if(pass[i][j] == num){
      //cout << " hor: " << i << " " << j << "\n";
      return false;
    }
  }
  return true;
}

bool checkVer(int j, int num){
  for(int i = 0; i < 9; i++){
    if(pass[i][j] == num){
      //cout << "ver : "<< i << " " << j << "\n";
      return false;
    }
  }
  return true;
}

bool checkBox(int y, int x, int num){
  for(int i = 0; i < 3; i++){
    for(int j = 0 ; j < 3 ;j++){
      if(pass[(y/3)*3 + i][(x/3)*3 + j] == num){
        //cout <<"box : " <<(y/3*3+i) << " " << x/3*3 + j << "\n";
        return false;
      }
    }
  }
  return true;
}



void dfs(int i, int j){
  //cout << i << " " << j << "\n";
  if(i == 9)
  {
    printPass();
    exit(0);
  }
  if(pass[i][j] != 0){
    if(j+1 == 9){
      dfs(i+1, 0);
    }else{
      dfs(i, j+1);
    }
  } else{  
    for(int k = 1; k < 10; k++){
      if(checkVer(j, k) && checkHor(i, k) && checkBox(i, j, k)){
        //cout << "> "<< i << " " << j << " " << k << "\n";
        pass[i][j] = k;
        if(j+1 == 9){
          dfs(i+1, 0);
        }else{
          dfs(i, j+1);
        }
        pass[i][j] = 0;
      }
    }
  }
}

int main(){
  string str;
  for(int i = 0; i < 9; i++){
    cin >> str;
    for(int j = 0 ; j < 9; j++){
      pass[i][j] = str[j] - '0';
    }
  }
  //printPass();
  dfs(0, 0);  

  return 0;
}
