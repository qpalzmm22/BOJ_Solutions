#include <iostream>
#include <algorithm>

using namespace std;

int map[25][25];
int destmap[25][25];

int N;
void printmap(){
  cout << "--------\n";
  for(int i = 0 ; i < N; i++){
    for(int j = 0 ; j < N; j++){
      cout <<  map[i][j] << " ";
    }
    cout << "\n";
  }
}

void moveLeft(){
  for(int i = 0 ; i < N; i++){
    int left = -1;
    int j = 0;
    int k = 0;
    while(k < N){
      if(map[i][k] == 0){
        k++;
        continue;
      }
      if(left == -1){
        left = k;
      } else {
        if(map[i][left] == map[i][k]){
          //cout << ">(same)" << i  << " "  << j << " "  << left << " "<< k << "\n";
          int value = map[i][left] << 1;
          map[i][left] = 0;
          map[i][k] = 0;
          map[i][j] = value;
          left = -1;
          j++;
        } else {
          //cout << ">(diff) " << i << " "  << j << " " << left << " "<< k << "\n";
          int value = map[i][left];
          map[i][left] = 0;
          map[i][j] = value;
          j++;
          left = k;
          map[i][j] = map[i][left];
        }
      }
      k++;
    }
    if(left != -1){
      //cout << ">(last) " << j << " " << left << "\n";
      map[i][j] = map[i][left];
      if(left != j)
        map[i][left] = 0;
    }
  }
}

void moveRight(){
  for(int i = 0 ; i < N; i++){
    int right = -1;
    int j = N - 1;
    int k = N - 1;
    while(k >= 0){
      if(map[i][k] == 0){
        k--;
        continue;
      }
      if(right == -1){
        right = k;
      } else {
        if(map[i][right] == map[i][k]){
          //cout << ">(same)" << i  << " "  << j << " "  << right << " "<< k << "\n";
          int value = map[i][right] << 1;
          map[i][right] = 0;
          map[i][k] = 0;
          map[i][j] = value;
          right = -1;
          j--;
        } else {
          //cout << ">(diff) " << i << " "  << j << " " << right << " "<< k << "\n";
          int value = map[i][right];
          map[i][right] = 0;
          map[i][j] = value;
          j--;
          right = k;
          map[i][j] = map[i][right];
        }
      }
      k--;
      //printmap();
    }
    if(right != -1){
      //cout << ">(last) " << j << " " << right<< "\n";
      map[i][j] = map[i][right];
      if(right != j)
        map[i][right] = 0;
    }
    //printmap();
  }
}
void moveUp(){
  for(int i = 0 ; i < N; i++){
    int up = -1;
    int j = 0;
    int k = 0;
    while(k < N){
      if(map[k][i] == 0){
        k++;
        continue;
      }
      if(up == -1){
        up = k;
      } else {
        if(map[up][i] == map[k][i]){
          //cout << ">(same)" << i << " "  << up << " "<< k << "\n";
          int value = map[up][i] << 1;
          map[up][i] = 0;
          map[k][i] = 0;
          map[j][i] = value;
          up = -1;
          j++;
        } else {
          //cout << ">(diff) " << i << " " << up << " "<< k << "\n";
          int value = map[up][i];
          map[up][i] = 0;
          map[j][i] = value;
          j++;
          up = k;
          map[j][i] = map[up][i];
        }
      }
      k++;
    }
    if(up != -1){
      map[j][i] = map[up][i];
      if(up != j)
        map[up][i] = 0;
    }
  }
}

void moveDown(){
  for(int i = 0 ; i < N; i++){
    int down = - 1;
    int j = N - 1;
    int k = N - 1;
    while(k >= 0){
      if(map[k][i] == 0){
        k--;
        continue;
      }
      if(down == -1){
        down = k;
      } else {
        if(map[down][i] == map[k][i]){
          //cout << ">(same)" << i << " "  << down << " "<< k << "\n";
          int value = map[down][i] << 1;
          map[down][i]= 0;
          map[k][i] = 0;
          map[j][i] = value;
          down = -1;
          j--;
        } else {
          //cout << ">(diff) " << i << " " << down << " "<< k << "\n";
          int value = map[down][i];
          map[down][i] = 0;
          map[j][i] = value;
          j--;
          down = k;
          map[j][i] = map[down][i];
        }
      }
      k--;
    }
    if(down != -1){
      map[j][i] = map[down][i];
      if(down != j)
        map[down][i] = 0;
    }
  }
}

int findMax(){
  int maxVal = 0;
  for(int i = 0 ; i < N ; i++){
    for(int j = 0; j < N; j++){
      if(map[i][j] > maxVal)
        maxVal= map[i][j];
    }
  }
  return maxVal;
}

int dfs(int n){
  //printmap();
  int maxVal = 0; 
  if(n == 5){
    return findMax();
  } else{
    int origMap[25][25];
    for(int i = 0 ; i < N; i++){
      for(int j = 0 ; j < N; j++){
        origMap[i][j] = map[i][j];
      }
    }
    for(int k = 0; k < 4; k++){
      //cout << "k: " << k << "\n";
      if(k == 0){
        moveLeft();
        maxVal = max(maxVal, dfs(n+1));
      }else if( k == 1){
        moveRight();
        maxVal = max(maxVal, dfs(n+1));
      }else if( k == 2){
        moveUp();
        maxVal = max(maxVal, dfs(n+1));
      }else{
        moveDown();
        maxVal = max(maxVal, dfs(n+1));
      }

      for(int i = 0 ; i < N; i++){
        for(int j = 0 ; j < N; j++){
          map[i][j] = origMap[i][j];
        }
      }
    }
  }
  return maxVal;
}

int main(){

  cin >> N;

  for(int i = 0 ; i < N; i++){
    for(int j = 0 ; j < N; j++){
      cin >> map[i][j];
    }
  }
  
  cout << dfs(0);
  //printmap();
  return 0;
}
