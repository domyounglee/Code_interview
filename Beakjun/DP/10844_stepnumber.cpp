#include <cstdio>
#include <algorithm>

#define mod 1000000000

int N ;
long long  dp[101][10];
int main(){

	scanf("%d",&N);
	//
	// the first dimension is N which starts form 1(자릿수), and the second is the number 0~9 (숫자)
	dp[1][0]=0;
	for(int j=1;j<=9;j++) dp[1][j]=1;

	for(int i=2;i<=N;i++){
		for(int j=0; j<=9; j++){
			if(j==0) {
				dp[i][j] = dp[i-1][j+1]%mod;
				continue;
			}
			if(j==9) {
				dp[i][j] = dp[i-1][j-1] % mod;
				continue;
			} 
			dp[i][j] = (dp[i-1][j-1] +  dp[i-1][j+1])%mod; 
		}
	}	

	// sum all the last N
	long long sum=0;	
	for(int i=0;i<=9;i++){
		//printf("/%d", dp[N][i]);
		sum+=dp[N][i] % mod;
	}
	printf("%lld",sum% mod);
}
