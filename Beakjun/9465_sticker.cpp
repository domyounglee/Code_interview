#include <cstdio>
#include <algorithm>

#define MAX 1000000
using namespace std;

int N , val[2][MAX], dp[MAX][3];
int sticker(int c,int status){
	if(c==N){return 0;}
	if(dp[c][status]!=-1){return dp[c][status];}

	int result = sticker(c+1 ,0);
	if(status!=1){result = max(result,sticker(c+1,1) + val[0][c]);}
	if(status!=2){result = max(result,sticker(c+1,2) + val[1][c]);}
	//set it in the dp array 
	dp[c][status] = result;

	return result;

}

int main(){
	int T;
	scanf("%d",&T);
	for(int t=0;t<T;t++){
		scanf("%d",&N);
		//insert
		for(int i=0; i<2; i++){
			for(int j=0; j<N ; j++){scanf("%d",&val[i][j]);}
		}
		// initialize
		for(int i=0; i<N; i++){
			for(int j=0; j<3; j++){dp[i][j]=-1;}
		}

		printf("%d\n",sticker(0,0));
	}
}