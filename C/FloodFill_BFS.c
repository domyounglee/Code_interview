//BFS
#include <stdio.h>
#include <stdlib.h>
//Queue
struct coord{ int x,y;} queue[25*25];
int Wp;
int Rp;
//아파트 단지
int apt[100][100]={0,};
//단지갯수 
int sol[100]={0,};
int sol_idx=0;


int BFS(){
	int xx[]={-1,1,0,0};
	int yy[]={0,0,-1,1};
	int i,x,y,count=0;
	struct coord p;
	while(Rp<Wp){
		//dequeue
		p=queue[Rp++];
		//recent coordinate
		x=p.x; y =p.y;
		for(i=0;i<4;i++){
			//changed coordinate
			p.x=x+xx[i];
			p.y=y+yy[i];
			//if it has 1
			if(apt[p.x][p.y]==1){
				apt[p.x][p.y]=0;
				count++;
				//enqueue
				queue[Wp++]=p;
			}
		}
	}

	return count;
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
				//enqueue 
				Wp=1;
				Rp=0;
				queue[0].x=i;
				queue[0].y=j;
				//Do BFS
				sol[sol_idx++]=BFS();
			}
		}
	}
	
	for(int i=0;i<sol_idx;i++){
		printf("%d\n",sol[i]);
	}

	return 0;
}