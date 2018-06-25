#include <stdio.h>
#include <stdlib.h>    
#include <string.h> 
#include <math.h>

#define MAX 4


int Stack[MAX];
//Sp is the stack pointer which starts from MAX (bottom)
int Sp=MAX;

//return sp if stack full return  -1 
int Push(int d){
	if (Sp==0){return -1;}
	Sp--;
	Stack[Sp]=d;
	return Sp;
}

//return sp if stack empty return  -1 
int Pop(int *p){
	if (Sp==MAX){return -1;}
	*p=Stack[Sp];
	Sp++;
	return Sp;
}

int main()
{
	int input_num=0;
	int temp,result;
	printf("input 갯수 : ");
	scanf("%d", &input_num);
	int pop_value;

	int* input=malloc(sizeof(int) * (input_num));
	printf("insert input : \n");
	for(int i=0;i<input_num;i++){
		scanf("%d", &temp);
		if(temp==0){

			result=Pop(&pop_value);
			
		}
		else{
			result=Push(temp);
		}
		printf("%d\n",result);
		
		
	}

	return 0;



	
}