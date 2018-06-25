//책에서 한 방법

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


int Check(int r, int c){
	int i,j;

	for( i=r-1; i>=0; i--){ if(chess_plate[i][c]==1){return 0;}}

	for( i=r-1, j=c+1; (i>=0) && (j<Num); i--,j++){ if(chess_plate[i][j]==1){return 0;}}

	for( i=r-1, j=c-1; (i>=0) && (j>=0); i--,j--){ if(chess_plate[i][j]==1){return 0;}}

	return 1;
}

void N_Queen(int row){

	if(row >= Num){ count++; }
	else{
		//for each column 
		for(int i=0; i < Num; i++){
			if(Check(row, i)==1){
				//Backtracking
				chess_plate[row][i]=1;
				N_Queen(row+1);
				chess_plate[row][i]=0;
			}
		}
	}

}


int main(void){


	scanf("%d",&Num);
	getchar();

	N_Queen(0);
	printf("%d",count);

}