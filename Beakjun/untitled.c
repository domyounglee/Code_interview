#include <stdio.h>
#include <stdlib.h> 
#include <limits.h> 
#include <math.h> 
#define INF 99999

int check_sum(int * check,int node){
	int sum=0;
	for(int i=0;i<node;i++){
		sum+=check[i];
	}
	if (sum==node){return 1;}
	else{return 0;}

}

int find_min_idx_of_start_node(int node,int * check,int * m_start){
	int min_idx=-1;
	int min_val=INF;

	for(int i=0;i<node;i++){
		if(check[i]==1){continue;}
		if(m_start[i]<min_val){
			min_idx=i;
			min_val=m_start[i];
		}

	}
	return min_idx;
}

int update_start_node(int node,int* check, int min_idx, int start_node, int** m){
	for(int i=0;i<node;i++){
		// continue if it is checked or the min_idx'node has not connect to the i's node
		if(check[i]==1 || m[min_idx][i]==INF){continue;}
		if(m[start_node][i]>m[start_node][min_idx]+m[min_idx][i]){
			m[start_node][i]=m[start_node][min_idx]+m[min_idx][i];
		}
	}
	return 0;
}


int main(void){

	int node;
	int edge;
	int start_node;
	int count=0;

	scanf("%d",&node);
	getchar();
	scanf("%d",&edge);
	getchar();
	scanf("%d",&start_node);
	getchar();

	//generate matrix for the weighted graph
	int **m= malloc(node*sizeof(int *));

	for(int i=0;i<node;i++){
		m[i]=malloc(node*sizeof(int));
	}
	//initialize the matrix with inifinty 
	for(int i=0;i<node;i++){
		for(int j=0;j<node;j++){
			m[i][j]=10000;
		}
	}

	for(int i=0; i<node;i++){
		for(int j=0;i<node;j++){
			printf("%d ",m[i][j]);
		}
		printf("\n");
	}
/*

	//for check 
	int *check= malloc(node*(sizeof(int)));
	for(int i=0;i<node;i++){
		check[i]=0;
	}

	

	//start, end, weight 
	//do input_index -1
	int s_e_w[3];
	for(int i=0;i<edge;i++){
		for(int j=0;j<3;j++){
			scanf("%d",&s_e_w[j]);
			getchar();
		}

		m[s_e_w[0]-1][s_e_w[1]-1]=s_e_w[2];
	}


	*/

/*
	//dijkstra
	check[start_node]=1;
	while(check_sum(check,node)!=1){
		int min_idx = find_min_idx_of_start_node(node,check,m[start_node]);
		check[min_idx]=1;
		update_start_node(node, check,min_idx,start_node,m);
		
	}



	printf("result \n");

	//print the result 
	for(int i=0;i<node;i++){
		if(i==0){printf("%d \n",0);continue;}
		if(m[start_node][i]==INF){printf("INF \n");continue;}
		printf("%d \n",m[start_node][i]);
	}
*/

}