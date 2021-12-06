#include <iostream>

using namespace std;

int map[130][130];
int num = 0;

int fn(int x, int y, int size ){
	if(size == 1){
		num+=1;
		return map[x][y]
	} else {
		int sum = 0;
		sum += fn(x, y, size/2);
		sum += fn((size-x)/2, y, size/2);
		sum += fn(x, (size-y)/2, size/2);
		sum += fn((size-x)/2, (size-y/2), size/2);
		if(sum == 0x01 << (size - 1))
	}
	
}


int 
main(){
	int n;
	cin >> n;
	
	for(int i = 0 ; i < n ; i++){
		for(j = 0 ; j < n ; j++){
			cin >> map[i][j] ;
		}
	}

	fn(0, 0, n);

	return 0;
}
