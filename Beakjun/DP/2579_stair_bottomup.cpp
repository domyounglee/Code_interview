#include <cstdio>
#include <algorithm>

#define MAX 1000000
using namespace std;

int N , val[301], dp[301][3];


int main(){
	int N;
	scanf("%d",&N);
	
	for(int i=1;i<=N;i++){
		scanf("%d",&val[i]);
	}
	//initialize 
	dp[0][0] = 0;
	dp[0][1] = 0;
	dp[1][0] = val[1];
	dp[1][1] = val[1];

	for(int i=0;i<=N-2;i++){
		dp[i+2][0] = max(dp[i][0], dp[i][1]) + val[i+2];
		dp[i+2][1] = dp[i+1][0]+ val[i+2];
 	}	
	printf("%d\n",max(dp[N][0],dp[N][1]));
}