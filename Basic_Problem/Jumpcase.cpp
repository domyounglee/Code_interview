#include <cstdio>
#include <algorithm>

#define MAX 100000

using namespace std;

int N ;
long long  dp[MAX];

int JumpCase(int N){

	if(N==1) return 1;
	if(N==2) return 2;

	if(dp[N]!=-1) return dp[N];

	int result = JumpCase(N-1) + JumpCase(N-2);
	//memoization
	dp[N]=result;

	return result;

}
int main(){

	scanf("%d",&N);
	fill(dp,dp+MAX,-1);

	printf("%d",JumpCase(N));
}
