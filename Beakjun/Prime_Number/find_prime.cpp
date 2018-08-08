#include <cstdio>
#include <algorithm>

using namespace std;

int arr[101] ;
int main(void){
	int T,num;
	int count=0;
	scanf("%d",&T);
	for(int i=0;i<T;i++){
		scanf("%d",&num);
		arr[i]=num;
	}

	for(int i=0;i<T;i++){
		int temp=0;
		num = arr[i];

		for(int j=1; j<=num; j++){
			if(num%j==0) temp++;
		}

		if(temp==2) count++;

	}

	printf("%d",count);
}