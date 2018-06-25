//책에서 한 방법
//accelerated version of NQueen
#include <stdio.h>
#include <stdlib.h>    // malloc, free 함수가 선언된 헤더 파일
#include <limits.h>

#define MAX 100


int Queue[MAX];
//wp is the write pointer rp is the read pointer
int Wp=0;
int Rp=0;

//number of row of the chess plate 
int Num;
// count of the possible queen
int count=0;

//chess plate 
int chess_plate[MAX][MAX]={0,};

int Check_col[MAX]={0,};
int Check_1[MAX]={0,};
int Check_2[MAX]={0,};


void N_Queen(int row){

	if(row >= Num){ count++; }
	else{
		//for each column 
		for(int i=0; i < Num; i++){
			//Backtracking
			if(Check_col[i]==1){continue ;}
			if(Check_1[row+i]==1){continue ;}
			if(Check_2[Num-1+(row-i)]==1){continue ;}

			Check_col[i]=1;
			Check_1[row+i]=1;
			Check_2[Num-1+(row-i)]=1;

			N_Queen(row+1);
	
			Check_col[i]= 0;
			Check_1[row+i]= 0;
			Check_2	[Num-1+(row-i)]= 0;
		}
	}

}


int main(void){


	scanf("%d",&Num);

	getchar();

	N_Queen(0);
	printf("%d \n",count);

}