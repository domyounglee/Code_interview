#include <stdio.h>
#include <stdlib.h>    
#include <string.h> 
#include <math.h>


int main(void)
{

	int W=0;
	int count=0;
	int temp=0;
	int change[4]={500,100,50,10};

	printf("돈 : ");
	scanf("%d", &W);
	getchar();


	for(int i=0;i<4;i++){
		int temp=0;
		temp=W/change[i];
		W-=temp*change[i];
		count+=temp;

	}

	printf("%d\n",count);
	return 0;



	
}