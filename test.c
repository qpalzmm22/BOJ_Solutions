#include <stdio.h>

int main(int argc, char ** argv(){
	
	if(argc != 2){
		fprintf(stderr, "Usuage : http_program [address]");
	}
	
	int len = strlen(argv[1]);
	int check_id = 0;

	for(int i = 0; i < len  ; i++){
		if( argv[i] - '0' >= 0 && argv[i] - '0' <= 9 ){
			check_id = 1;
		}
	}

	if ( check_id ){
		printf("hello \n");
	}
	return 0;
}
