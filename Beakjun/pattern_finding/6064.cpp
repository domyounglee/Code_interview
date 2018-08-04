
//풀이 : M,N  둘중 작은 것을 고르고 둘 차이를 구한다. 
//		M 이 작다고 한다면 x값부터 시작해서 차이를 y 에 계속 빼나간다. 
//      N 만큼했을때 원하는 답이 나온다면 뱉고 안나오면 -1

#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <map>
using namespace std;


int main(void){
	int T,M,N,x,y;
	scanf("%d",&T);
	for(int i=0; i<T ; i++){

		scanf("%d %d %d %d",&M,&N,&x,&y);

		int min_val,diff;
		int count = -1;

		if (M<N) {
			diff=N-M;
			int next_y=x;
			//M*N is the maximum value
			for(int j=0;j<N;j++){
				if(next_y < 1) next_y+=N;
				if(next_y == y){
					count=j;
					break;
				}
				else next_y -= diff;
			}

			if(count==-1) printf("-1\n");
			else printf("%d\n",count*M+x);
		}
		else{

			diff=M-N;
			int next_x=y;
			//M*N is the maximum value
			for(int j=0;j<M;j++){
				if(next_x < 1) next_x+=M;
				if(next_x == x){
					count=j;
					break;
				}
				else next_x -= diff;
			}

			if(count==-1) printf("-1\n");
			else printf("%d\n",count*N+y);
		}


	}


	
	return 0;

}
