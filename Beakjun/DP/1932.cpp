#include <cstdio>
#include <algorithm>
#define MAX 501	
#define INF 1000001
using namespace std;

int N,dp[MAX][501], cost[MAX][501];


int main(void){

	scanf("%d",&N);



	for(int i=0; i<N; i++){
		for(int j=0 ; j<=i; j++){
			scanf("%d",&cost[i][j]);
		}
	}
	
	//dp
	for(int i=0;i<N;i++){
		dp[i+1][0] = dp[i][0]+cost[i][0];
		//printf("%d ",dp[i+1][0]);
		
		for(int j=1; j<=i; j++){

			if(dp[i][j-1] + cost[i][j-1] > dp[i][j]  + cost[i][j]) dp[i+1][j] = dp[i][j-1] + cost[i][j-1];
			else dp[i+1][j] = dp[i][j] + cost[i][j];
			//printf("%d ",dp[i][j]);
		
		}
		dp[i+1][i+1] = dp[i][i]+cost[i][i];
		//printf("%d ",dp[i+1][i+1]);
		//printf("\n");
	}
	int max=-1;
	for(int i=0;i<=N;i++){
		if(max<dp[N][i]) max=dp[N][i];
	}
	printf("%d\n",max);
}