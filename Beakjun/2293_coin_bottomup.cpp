#include <cstdio>
#include <algorithm>

#define MAX_MONEY 100000
#define MAX_VAL 1000
using namespace std;
int val_count, total_money;
int val[MAX_VAL], dp[MAX_MONEY]={0,};


int main(){

	scanf("%d %d",&val_count, &total_money);

	for(int i=0; i<val_count; i++){
		scanf("%d",&val[i]);
	}

	dp[0]=1;
	for(int i=0; i<val_count; i++){
		for(int j=1; j<=total_money; j++){
			if(j >= val[i]){
				dp[j]+= dp[j-val[i]];
			
			}
		}
		
	}

	printf("%d",dp[total_money]);
}