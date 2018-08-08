#include <cstdio>
#include <algorithm>

using namespace std;

int T,N,dp_cnt[41][2], cnt[2];


int fib(int num){


    if(num==0){
    	cnt[0]++;
    	return 0;}
    if(num==1){
    	cnt[1]++;
    	return 0;}

    // if num exist
   	if(dp_cnt[num][0]!=0){
   		cnt[0]=cnt[0]+dp_cnt[num][0];
   		cnt[1]=cnt[1]+dp_cnt[num][1];
   		return 0;}


   	fib(num-1)+fib(num-2);
   	dp_cnt[num][0] = cnt[0];
   	dp_cnt[num][1] = cnt[1];

    return 0;

}

int main(){
    scanf("%d",&T);

    for(int t=0;t<T;t++){
    	for(int i=0; i<41; i++){
    		for(int j=0; j<2; j++){
    			dp_cnt[i][j]=0;
    		}
    	}
    	for(int i=0;i<2;i++){cnt[i]=0;}

    	
    	scanf("%d",&N);
    	fib(N);
    	printf("%d %d\n",cnt[0],cnt[1]);
    	
    }
    

}