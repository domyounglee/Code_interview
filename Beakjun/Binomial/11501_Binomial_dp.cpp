#include <cstdio>
#include <algorithm>
#define MAX 1001
using namespace std;

int dp[MAX][MAX];



int main(void){
	int N,K;

	scanf("%d %d",&N,&K);

	for(int i=0 ; i<MAX ;i++){
		dp[i][0]=dp[i][MAX-1]=1;
	}
	
	for(int i=1 ; i<MAX-1 ;i++){
		for(int j=1; j<MAX-1; j++) dp[i][j] = (dp[i-1][j] + dp[i-1][j-1])%10007;
	}
	printf("%d",dp[N][K]);
}