#include <cstdio>
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

priority_queue<int , vector<int>, greater<int> > pq;

int main(void){

	int T,num;
	scanf("%d",&T);

	for(int i=0;i<T;i++){
		scanf("%d",&num);
		pq.push(num);
	}

	for(int i=0;i<T;i++){
		printf("%d\n",pq.top());
		pq.pop();
	}
}