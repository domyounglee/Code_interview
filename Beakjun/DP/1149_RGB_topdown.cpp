#include <cstdio>
#include <algorithm>
#define MAX 1001	
#define INF 1000001
using namespace std;

int N,dp[MAX][3], cost[MAX][3];


int RGB(int house_id,int rgb){

	if(house_id == N){return 0;}

	if(dp[house_id][rgb]!=-1){return dp[house_id][rgb];}


	int min_result=INF;

	for(int i=0;i<3;i++){
		if(house_id !=0 && i==rgb){continue;} //skip it 
		//printf("%d ",cost[house_id][i]);
		int result = RGB(house_id+1, i) + cost[house_id][i];
		//printf("%d ,",result);
		if(min_result > result){min_result = result;}
			
	}
	
	//printf("&");		
	//printf("%d=%d /\n",house_id,min_result);
	dp[house_id][rgb] = min_result;
	return min_result;
}
int main(void){

	scanf("%d",&N);

	for(int i=0; i<N; i++){
		for(int j=0 ; j<3; j++){
			dp[i][j] = -1;
			scanf("%d",&cost[i][j]);
		}
	}
	
	printf("%d\n",RGB(0,0));
}