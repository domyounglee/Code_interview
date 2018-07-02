#include <cstdio>
#include <algorithm>

#define MAX 100001
using namespace std;

int N,val[MAX],dp[MAX],maxm;

int main(){

	scanf("%d",&N);

	for(int i=0;i<N;i++){scanf("%d",&val[i]);}

	maxm=val[0];
	dp[0] = val[0];
	for(int i=0;i<N-1;i++){
		if(val[i+1] < dp[i] + val[i+1]){
			dp[i+1] = dp[i]+ val[i+1];
		}
		else{
			dp[i+1] = val[i+1];
		}

		//check if it is the maxm value 
		if(maxm < dp[i+1]) maxm = dp[i+1];

	}

	printf("%d",maxm);
}