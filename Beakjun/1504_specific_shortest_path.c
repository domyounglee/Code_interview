//1. 특정 edge에 해당하는 양 node 를 a,b라고 함. 
//2. start_point, a, b array 따로 최단거리 구한다. 단 ,initalize는 처음 값으로 


#include <stdio.h>
#include <stdlib.h> 
#include <limits.h> 
#include <math.h> 
#define INF INT_MAX

int check_sum(int * check,int node){
	int sum=0;
	for(int i=0;i<node;i++){
		sum+=check[i];
	}
	if (sum==node){return 1;}
	else{return 0;}

}

int find_min_idx(int node,int * check,int * m_start){
	int min_idx=-1;
	int min_val=INF;

	for(int i=0;i<node;i++){
		if(check[i]==1){continue;}
		//등호 붙여줘야함. 안그럼 0이 가리키지 않은 노드들(INF) 처리 불가. 
		if(m_start[i]<=min_val){
			min_idx=i;
			min_val=m_start[i];
		}

	}
	return min_idx;
}

int update(int** m, int* dist_arr, int* check, int min_idx, int node){
	for(int i=0;i<node;i++){
		// continue if it is checked or the min_idx'node has not connect to the i's node
		if(check[i]==1 || m[min_idx][i]==INF){continue;}
		if(dist_arr[i]>dist_arr[min_idx]+m[min_idx][i]){
			dist_arr[i]=dist_arr[min_idx]+m[min_idx][i];
		}
	}
	return 0;
}


int main(void){

	int node;
	int edge;
	int start=0;
	int count=0;
	int a,b;
	scanf("%d",&node);
	getchar();
	scanf("%d",&edge);
	getchar();


	//generate matrix for the weighted graph
	int **m= malloc(node*sizeof(int *));

	for(int i=0;i<node;i++){
		m[i]=malloc(node*sizeof(int));
	}
	
	
	//initialize the matrix with inifinty 
	for(int i=0; i<node;i++){
		for(int j=0;j<node;j++){
			m[i][j]=INF;
		}
		
	}



	//for check 
	int *check_start = malloc(node*(sizeof(int)));
	int *check_a = malloc(node*(sizeof(int)));
	int *check_b = malloc(node*(sizeof(int)));
	for(int i=0;i<node;i++){
		check_start[i]=0;
		check_a[i]=0;
		check_b[i]=0;
	}

	

	//start, end, weight 
	//do input_index -1
	int s_e_w[3];
	for(int i=0;i<edge;i++){
		for(int j=0;j<3;j++){
			scanf("%d",&s_e_w[j]);
			getchar();
		}
		//undirected node
		m[s_e_w[0]-1][s_e_w[1]-1]=s_e_w[2];
		m[s_e_w[1]-1][s_e_w[0]-1]=s_e_w[2];
	}

	//specific nodes
	scanf("%d",&a);
	getchar();
	scanf("%d",&b);
	getchar();
	a=a-1;
	b=b-1;

	//array for shortest distance from starting point,a,b
	int * dist_from_start = malloc(sizeof(int)*node);
	int * dist_from_a = malloc(sizeof(int)*node);
	int * dist_from_b = malloc(sizeof(int)*node);

	//initizalize it 
	for( int i =0;i<node;i++){
		dist_from_start[i] = m[start][i];
		dist_from_a[i] = m[a][i];
		dist_from_b[i] = m[b][i];
	}


	for(int i=0; i<node;i++){
		for(int j=0;j<node;j++){
			printf("%d ",m[i][j]);
		}
		printf("\n");
	}

	

	printf("dijkstra \n");
	//dijkstra
	check_start[start]=1;
	while(check_sum(check_start,node)!=1){
		int min_idx = find_min_idx(node,check_start, dist_from_start);
		//printf("%d\n",min_idx);
		check_start[min_idx]=1;
		update(m, dist_from_start, check_start, min_idx, node);
	}

	check_a[start]=1;
	while(check_sum(check_a,node)!=1){
		int min_idx = find_min_idx(node,check_a, dist_from_a);
		//printf("%d\n",min_idx);
		check_a[min_idx]=1;
		update(m, dist_from_a, check_a, min_idx, node);
	}

	check_b[start]=1;
	while(check_sum(check_b,node)!=1){
		int min_idx = find_min_idx(node,check_b, dist_from_b);
		//printf("%d\n",min_idx);
		check_b[min_idx]=1;
		update(m, dist_from_b, check_b, min_idx, node);
	}


	printf("result \n");
	/*
	//print the result 
	for(int i=0;i<node;i++){
		if(i==0){printf("%d \n",0);continue;}
		if(dist_from_start[i]==INF){printf("INF \n");continue;}
		printf("%d \n",dist_from_start[i]);
	}
	*/

	//a to b
	int val1 = dist_from_start[a] + dist_from_b[node-1];

	int val2 = dist_from_start[b] + dist_from_a[node-1];
	
	//no path
	if(val1<=0 || val2<=0){
		printf("%d \n",-1);
	}
	else{
		//print the lowest path value
		if(val1<val2){
			printf("%d \n",val1+m[a][b]);
		}
		else{
			printf("%d \n",val2+m[a][b]);
		}
	}


}