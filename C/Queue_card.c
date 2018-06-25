#include <stdio.h>
#include <stdlib.h>    
#include <string.h> 
#include <math.h>

#define MAX 100


int Queue[MAX];
//wp is the write pointer rp is the read pointer
int Wp=0;
int Rp=0;


int enqueue(int d){
	if (Wp==MAX){return 0;}
	Queue[Wp++]=d;
	return 1;
}

//return sp if stack empty return  -1 
int dequeue(int *p){
	if (Rp==Wp){return 0;}
	*p=Queue[Rp++];
	return 1;
}

int main()
{
	int i=0,sum=0;
	char *tokens[30]={NULL,}; 
	int input_num=0,count=0;
	int result;
	int deq_data;
	int peek;

	printf("input 갯수 : ");
	scanf("%d", &input_num);
	getchar();
	
	for(int i=1;i<=input_num;i++){
		result=enqueue(i);
		
	}
	

	while(input_num>1){
		int cond=Queue[Wp-1]/2;
		for(int j=0; j<cond;j++){
			//printf("%d\n", Queue[Wp-1]/2);
			dequeue(&deq_data);
			enqueue(deq_data);
			
		}
		dequeue(&deq_data);
		printf("%d\n",deq_data);
		input_num--;
	}

	dequeue(&deq_data);
	printf("%d\n",deq_data);
	return 0;




	
}