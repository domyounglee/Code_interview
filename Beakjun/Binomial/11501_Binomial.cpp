#include <cstdio>
#include <algorithm>
#define MAX 1010
using namespace std;

int dp[MAX][MAX];

int binomial(int N,int K){

	if(K==0 || K==N) return 1;
	
	if(dp[N][K] != -1) return dp[N][K];

	int result = (binomial(N-1,K) + binomial(N-1, K-1))%10007;

	dp[N][K] = result;

	return result;

}

int main(void){
	int N,K;

	scanf("%d %d",&N,&K);

	for(int i=0 ; i<MAX ;i++){
	
		for(int j=1; j<MAX-1; j++) {
			dp[i][j]=-1;
		}

	}
	
	int result = binomial(N,K);
	printf("%d",result);
}