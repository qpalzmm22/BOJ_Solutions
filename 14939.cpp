#include <iostream>
#define MX 10000
int dy[5] = {0, -1, 1, 0, 0};
int dx[5] = {0, 0, 0, -1, 1};


using namespace std;

bool map[10][10];
bool testmap[10][10];
bool pushed[10][10];

void color(int y, int x){
  for(int j = 0 ; j < 5; j++){
    int nextx = x + dx[j];
    int nexty = y + dy[j];

    if(nextx < 0 || nexty < 0 || nextx >= 10 || nexty >= 10)
      continue;

    testmap[nexty][nextx] = !testmap[nexty][nextx];
  }
}

void copymap(){
  for(int i = 0 ; i < 10 ; i++){
    for(int j = 0 ; j < 10; j++){
      testmap[i][j] = map[i][j];
    }
  }
}
void printmap(){
  for(int i = 0 ; i < 10 ; i++){
    for(int j = 0 ; j < 10; j++){
      cout << testmap[i][j] << " ";
    }
    cout << "\n";
  }
}
int main(){
  for(int i = 0 ; i < 10; i++){
    string str;
    cin >> str;
    for(int j = 0; j < 10; j++){
      if(str[j] == 'O')
        map[i][j] = true;
      else
        map[i][j] = false;
    }
  }

  int first_row = 0;
  int lights_on = MX;

  while(first_row < (1 << 10)){

    int num_lights = 0;
    copymap();
    for(int i = 0 ; i < 10; i++){
      pushed[0][i] = (first_row >> i) & 1;
      if(pushed[0][i]){
        num_lights++;
        color(0, i);
      }
    }

    for(int j = 1; j < 10; j++){
      for(int k = 0; k < 10; k++){
        if(testmap[j-1][k]){
          num_lights++;
          pushed[j][k] = true;
          color(j, k);
        }else{
          pushed[j][k] = false;
        }
      }
    }
    //check last row and see if there's still a light
    bool unable = false;
    for(int i = 0 ; i < 10 ; i++){
      if(testmap[9][i]){
        unable = true;
        break;
      }
    }
    if(!unable){
      lights_on = min(lights_on, num_lights);
    }

    //cout << first_row << " " << num_lights <<  "\n";
    //printmap();
    first_row++;
  }

  if(lights_on == MX)
    cout << "-1";
  else
    cout << lights_on;
  return 0;
}
