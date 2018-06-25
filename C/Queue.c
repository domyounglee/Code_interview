#include <stdio.h>
#include <stdlib.h>    
#include <string.h> 
#include <math.h>

#define MAX 5


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

	printf("input 갯수 : ");
	scanf("%d", &input_num);
	getchar();

	printf("input : ");
	char *input= malloc(sizeof(char)*(4*input_num+1));
	fgets (input, 4*input_num+1, stdin);

	char* ptr=strtok(input," ");
	//tokenize
	while(ptr!=NULL){
		tokens[count]=ptr;
		count++;
		ptr=strtok(NULL," ");
	}
		//calculate
	while(tokens[i]!=NULL){
		// ith element
		//printf("%d\n",atoi(tokens[i]));

		if(atoi(tokens[i])!=0){
			result=enqueue(atoi(tokens[i]));
			if(result==0){
				printf("can't write %d\n",result);
			}
		}
		else{
			result=dequeue(&deq_data);
			if(result==0){
				printf("can't read -1\n");
			}
			else{printf("%d\n",deq_data);}
		}

		i++;
	
	}





	
}