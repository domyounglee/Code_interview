#include <cstdio>
#include <iostream>
#include <algorithm>

#define ARRAY_LEN 1000001
using namespace std;

int arr[ARRAY_LEN];

void merge(int arr[], int f, int m, int l){

	int front = f;
	int rear = m+1;

	int t_arr[ARRAY_LEN];
	int idx=f;

	//sort the two sorted array front and rear into t_arr
	while(front <= m && rear <= l){

		if(arr[front]<arr[rear]){
			t_arr[idx] = arr[front++];
		}
		else{
			t_arr[idx] = arr[rear++];
		}
		idx++;
	}

	//remainers of front or rear
	if(front <= m){
		for(int i=front; i<=m ; i++) {
			t_arr[idx] = arr[i];
			idx++;
		}

	}
	else{
		for(int i=rear; i<=l ; i++) {
			t_arr[idx] = arr[i];
			idx++;
		}
	}

	//copy t_arr to arr
	for(int i=f; i<=l; i++){
		arr[i]=t_arr[i];
	}

}

//deliver first, last index to the function
void merge_sort(int arr[], int f, int l){

	if(f < l){

		int m = (f+l)/2;

		merge_sort(arr, f, m);
		merge_sort(arr, m+1, l);

		merge(arr,f,m,l);
	}
}

int main(void){

	int T,num;
	scanf("%d",&T);

	for(int i=0;i<T;i++){
		scanf("%d",&num);
		arr[i]=num;
	}

	merge_sort(arr,0,T-1);

	for(int i=0;i<T;i++){
		printf("%d\n",arr[i]);
	
	}
}