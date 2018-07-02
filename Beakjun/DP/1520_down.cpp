#include <cstdio>
#include <algorithm>

#define MAX 1000000
using namespace std;

int M,N;
int val[510][510];
int dp[510][510];

int search_route(int x,int y){
	
	if(x==N && y==M) {return 1;}
	
	if(dp[x][y] !=0) return dp[x][y];

	int v_x[5] = { 0, 1, 0, -1, 0 };
    int v_y[5] = { 0, 0, 1, 0, -1 };
    

    for(int i=1; i<=4; i++){

    	int next_x = x+v_x[i];
    	int next_y = y+v_y[i];
    	if(dp[next_x][next_y] == -1) continue;

    	if(val[x][y]>val[next_x][next_y]){
			//printf("[%d %d]\n",x,y);
			//printf("\t[%d %d]\n",next_x,next_y);
    		dp[x][y] += search_route(next_x,next_y);
    	}

    }
   

    return dp[x][y]; 

}

int main(){

	scanf("%d %d",&N,&M);
	
	//initialize dp
	// the boundary is initialized to -1 
	for(int i=0;i<=N+1;i++){
		for(int j=0;j<=M+1;j++) {
			if (i==0 || j==0 || i==N+1 || j ==M+1){
				dp[i][j]=-1;
				continue;
			}
			dp[i][j]=0;
		}
	}	


	for(int i=1;i<=N;i++){
		for(int j=1;j<=M;j++) scanf("%d",&val[i][j]);
	}		
	
		
	printf("%d\n",search_route(1,1));
}