#include <cstdio>
#include <algorithm>

#define MAX 1000010
using namespace std;

int N , val[3][MAX], dp[MAX][3];


int main(){
	int T;
	scanf("%d",&T);
	for(int t=0;t<T;t++){
		scanf("%d",&N);
		//insert
		//watch out the index !!! value of i is 1,2 & value of j starts from 1
		for(int i=1; i<=2; i++){
			for(int j=1; j<=N ; j++){scanf("%d",&val[i][j]);}
		}
		
		
		for(int i=0; i<N; i++){
			dp[i+1][0] = max(dp[i][0], max(dp[i][1],dp[i][2]));
			dp[i+1][1] = max(dp[i][2] , dp[i][0]) + val[1][i+1];
			dp[i+1][2] = max(dp[i][1] , dp[i][0])  + val[2][i+1]	;
		}

		printf("%d\n", max(dp[N][0],max(dp[N][1],dp[N][2])));
	}
}