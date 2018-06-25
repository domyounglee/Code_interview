#include <stdio.h>
#include <stdlib.h>    
#include <string.h> 
#include <math.h>

#define MAX 100


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

int operate(char operator, char* operand){
	int pop_val;
	switch (operator){
		case '+':

			Push(atoi(operand));
			break;
		case '-':
			
			Push(-1*atoi(operand));
			break;
		case '*':
			Pop(&pop_val);
			Push((pop_val)*atoi(operand));
			break;
		case '/':
			Pop(&pop_val);
			Push((pop_val)/atoi(operand));
			break;
	}
	return 0;
}

int main(void)
{
	int i=0,sum=0;
	char *tokens[30]={NULL,}; 
	int input_num=0,count=0;
	char temp,result;
	int pop_value;

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
		// just insert in the stack
		if(i==0){
			Push(atoi(tokens[i]));
			
		}
		// if number
		if(i%2==0 && i!=0){
			
			char operator=tokens[i-1][0];
			char* operand=tokens[i];
			
			operate(operator,operand);
	

		}

		
		i++;
	}

	//sum all the element in the stack 
	while(Pop(&pop_value)!=-1){
		sum+=pop_value;
	}

	printf("%d\n",sum);

	


	return 0;



	
}