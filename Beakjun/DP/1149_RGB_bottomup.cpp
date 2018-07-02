#include <cstdio>
#include <algorithm>
#define MAX 1001	
#define INF 1000001
using namespace std;

int N,dp[MAX][3], cost[MAX][3];


int main(void){

	scanf("%d",&N);



	for(int i=0; i<N; i++){
		for(int j=0 ; j<3; j++){
			dp[i][j] = 0;
			scanf("%d",&cost[i][j]);
			
		}
	}
	
	//dp
	for(int i=0;i<N;i++){
		dp[i+1][0] = min(dp[i][1]+cost[i][1], dp[i][2]+cost[i][2]);
		dp[i+1][1] = min(dp[i][0]+cost[i][0], dp[i][2]+cost[i][2]);
		dp[i+1][2] = min(dp[i][0]+cost[i][0], dp[i][1]+cost[i][1]);
	}
	printf("%d\n",min(dp[N][0],min(dp[N][1],dp[N][2])));
}