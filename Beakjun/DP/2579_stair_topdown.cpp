#include <cstdio>
#include <algorithm>

#define MAX 1000000
using namespace std;

int N , val[301], dp[301][3];
int stair(int num,int check){
	//printf("(%d %d) \n",num,check);
	int result=0;
	//escape
	if(num==0){return 0;}

	if(dp[num][check] != -1){return dp[num][check];}

	if(num>=2){
		
		result = stair(num-2, 0) + val[num];
		//printf("2: %d %d/ ",result,val[num]);
	}
	if(num>=1 ){
		//in case of first step or not consecutive step1 
		if(check<1 || num==1){
			result = max(result, stair(num-1, check+1) + val[num]);
			//printf("1: %d %d/ ",result, val[num]);
		}
		

	}
	//printf("[%d %d %d]\n",num,check,result);

	dp[num][check] = result;

	return result;

}

int main(){
	int N;
	scanf("%d",&N);
	val[0]=0;
	for(int i=1;i<=N;i++){
		scanf("%d",&val[i]);
	}
	
	for(int i=0;i<=N;i++){
		for(int j=0; j<3;j++) dp[i][j]=-1;
	}
	printf("%d\n",stair(N,0));
}