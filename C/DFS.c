// 내가 생각한 방식; 마지막에 check 

#include <stdio.h>
#include <stdlib.h>    // malloc, free 함수가 선언된 헤더 파일
#include <limits.h>

#define MAX 100


int Stack[MAX];
//Sp is the stack pointer which starts from MAX (bottom)
int Sp=MAX;

//return sp if stack full return  0
int Push(int d){
	if (Sp==0){return 0;}
	Sp--;
	Stack[Sp]=d;
	return Sp;
}

//return sp if stack empty return  0
int Pop(int *p){
	if (Sp==MAX){return 0;}
	*p=Stack[Sp];
	Sp++;
	return Sp;
}

struct Graph{
	int* s;
	int* e;
};


int main(void){
	int result;
	int data;
	int nghbr;
	//graph정의
	struct Graph g;

	//for first input 
	int node_edge[2];

	//input node and edge number 
	for(int i=0;i<2;i++){
		scanf("%d",&node_edge[i]);
	}

	//allocate g.s g.e
	g.s= malloc(node_edge[1]*sizeof(int));
	g.e= malloc(node_edge[1]*sizeof(int));

	//input edge path
	for(int i=0;i<node_edge[1];i++){
		scanf("%d",&(g.s[i]));
		getchar();
		scanf("%d",&(g.e[i]));
		getchar();
	}

	// set check it starts from index 1
	int* check=malloc((node_edge[0]+1)*sizeof(int));


	

	result=Push(1);
	while(Sp!=MAX){
		result=Pop(&data);
		if(check[data]==0){
			//check the dequeue data
			check[data]=1;
			//print 
			printf("%d\n",data);
		}


		//get neigbor and enqueue it 
		for(int i=0;i<node_edge[1];i++){
			if(g.s[i] == data){
				nghbr=g.e[i]; //neighbor node
				
				if(check[nghbr]==0){ 
					Push(nghbr);
					printf("nghbr %d\n",nghbr);
					continue;
				}
				
			}
			if(g.e[i] == data){
				nghbr=g.s[i]; //negibor node
				
				if(check[nghbr]==0){ 
					Push(nghbr);
					printf("nghbr %d\n",nghbr);
					continue;
				}
				
			}
		}
	
	}
	
	free(g.s);
	free(g.e);
	free(check);


	return 0;
}