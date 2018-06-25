//DFS
#include <stdio.h>
#include <stdlib.h>
//아파트 단지
int apt[100][100]={0,};
//단지갯수 
int sol[100]={0,};
int sol_idx=0;
int count=0;

void DFS(int x,int y){
	//exit
	if (apt[x][y]==0){return ;}
	else{
		count++;
		apt[x][y]=0;
	}

	DFS(x,y+1);
	DFS(x,y-1);
	DFS(x+1,y);
	DFS(x-1,y);
}


int main(void){

	freopen("FloodFill_input.txt","r",stdin);

	int row; // it is square
	scanf("%d",&row);
	
	/*
	int** apt=malloc(sizeof(int*)*(row+2));
	for(int i=0;i<row+3;i++){
		apt[i]=calloc(0,sizeof(int)*(row+2));
	}
	*/
	//write
	for(int i=1;i<row+1;i++){
		for(int j=1;j<row+1;j++){
			scanf("%d",&apt[i][j]);
		}
	}
	//print
	printf("%d\n",row);
	for(int i=0;i<row+2;i++){
		for(int j=0;j<row+2;j++){
			printf("%d",apt[i][j]);
		}
		printf("\n");
	}

	for(int i=1;i<row+1;i++){
		for(int j=1;j<row+1;j++){
			if(apt[i][j]==1){
				count=0;
				DFS(i,j);
				sol[sol_idx++]=count;
			}
		}
	}
	
	for(int i=0;i<sol_idx;i++){
		printf("%d\n",sol[i]);
	}

	return 0;
}