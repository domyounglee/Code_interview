#include <cstdio>
#include <algorithm>
#define MAX 1000001	

using namespace std;

int N,dp[MAX];

int main(void){

	scanf("%d",&N);

	dp[1]=0;
	for(int i=2;i<=N;i++){

		dp[i]=dp[i-1]+1;
		if(i%3==0){dp[i] = min(dp[i],dp[i/3]+1);}		
		if(i%2==0){dp[i] = min(dp[i],dp[i/2]+1);}

	}

	printf("%d\n",dp[N]);
}