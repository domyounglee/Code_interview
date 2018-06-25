#include <cstdio>
#include <algorithm>
#define MAX 1000001	

using namespace std;

int N,dp[MAX];

int make_one(int num){
	if(num == 1){
		return 0;
	}

	if(dp[num]!=-1){
		return dp[num];
	}
	int result = make_one(num-1)+1;
	if(num%3 ==0){result = min(result,make_one(num/3)+1);}
	if(num%2 ==0){result = min(result,make_one(num/2)+1);}

	
	dp[num] = result;
	return result;
}

int main(void){

	scanf("%d",&N);
	fill(dp, dp+MAX, -1);
	printf("%d\n",make_one(N));
}