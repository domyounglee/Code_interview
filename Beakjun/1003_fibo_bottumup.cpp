#include <cstdio>
#include <algorithm>

using namespace std;

int T,N,dp_cnt[41][2];


int main(){
    scanf("%d",&T);

    for(int t=0;t<T;t++){
    	for(int i=0; i<41; i++){
    		for(int j=0; j<2; j++){
    			dp_cnt[i][j]=0;
    		}
    	}

		scanf("%d",&N);
    	
    	dp_cnt[0][0]=1;
    	dp_cnt[0][1]=0;
    	dp_cnt[1][0]=0;
    	dp_cnt[1][1]=1;
    	for(int i=2; i<= N; i++){
    		dp_cnt[i][0]=dp_cnt[i-1][0]+dp_cnt[i-2][0];
    		dp_cnt[i][1]=dp_cnt[i-1][1]+dp_cnt[i-2][1];
    	}

    	
    	printf("%d %d\n",dp_cnt[N][0],dp_cnt[N][1]);
    	
    }
    

}