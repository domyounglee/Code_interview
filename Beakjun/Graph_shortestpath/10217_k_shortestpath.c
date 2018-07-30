#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>
#define INF INT_MAX



int main(void){
	int test_case;
	int num=0;
	scanf("%d",&test_case);

	int ** param = malloc(sizeof(int*) * test_case);

	int *** m =	 malloc(sizeof(int**) * test_case);

	//input 
	for(int i=0;i<test_case;i++){
		//param = 공항수, 비용, 티켓정보수
		param[i] = malloc(sizeof(int)*3);
		for(int j=0;j<3;j++){
			scanf("%d",   param[i]+j  );
			getchar();
		}	
	
		//티켓정보
		m[i] = malloc(sizeof(int*) * param[i][2]);
		for (int j = 0; j < param[i][2]; j++){	
			m[i][j] = malloc(sizeof(int)*4);	
		}
		
		for (int j = 0; j < param[i][2]; j++){	
			for (int k =0; k < 4; k++){
				scanf("%d",m[i][j]+k);
				getchar();
			}
		}
	}




	/*
	for(int i=0;i<test_case;i++){
		for(int j=0;j<3;j++){
			printf("%d ",param[i][j]);
		}
		printf("\n");
		for (int j = 0; j < param[i][2]; j++)
		{	
			for (int k =0;k<4;k++){
				printf("%d ",m[i][j][k]);
			}
			printf("\n");
		}
	}
	*/


	






}