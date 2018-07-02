#include <cstdio>
#include <algorithm>
#include <limits>
#define MAX_MONEY 10002
#define MAX_VAL 102

using namespace std;
int val_count, total_money;
int val[MAX_VAL], dp[MAX_MONEY][MAX_VAL];
int MAXM = 1000000000;
int min_depth=MAXM;
int coin(int money,int v_idx,int depth){
	if(v_idx==0){
		if(money%val[v_idx]==0){
			depth+=money/val[v_idx];
			//printf("[%d, %d, %d]",money,v_idx,depth);
			if(depth < min_depth) min_depth = depth;
			return 1;
		}
		else return 0;
	}	

	
	if(dp[money][v_idx]!=-1){return dp[money][v_idx];}


	int count=0;
	int t= money/val[v_idx];

	for(int i=0; i<=t; i++){
		count+=coin(money-i*val[v_idx],v_idx-1,depth+i);
	}

	dp[money][v_idx]=count;

	return count;
}

int main(){
	scanf("%d %d",&val_count, &total_money);

	for(int i=0; i<val_count; i++){
		scanf("%d",&val[i]);
	}

	for(int i=0 ; i<= total_money; i++){
		for(int j=0; j<=val_count;j++) dp[i][j]=-1;
	}
	int result = coin(total_money,val_count-1,0);
	if(result == 0 || total_money > 10000) printf("-1\n");
	else printf("%d\n",min_depth);
	
}