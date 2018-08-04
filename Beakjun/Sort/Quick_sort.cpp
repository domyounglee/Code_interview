#include <cstdio>
#include <iostream>
#include <algorithm>

#define ARRAY_LEN 1000001
using namespace std;

int arr[ARRAY_LEN];

void swap(int array[],int idx1, int idx2){
	int temp = temp=array[idx1];
	array[idx1] = array[idx2];
	array[idx2] = temp;

}

void QuickSort(int array[], int f, int l){
	
	//탈출조건
	if(l-f<=0) return;

	int left=f;
	int right=l;
	int pivot = array[(f + l)/2];

	while(left<=right){
		//자기자신은 지나가지 못하게 등호 사용안함
		while(array[left]<pivot){
			left++;
		}
		while(array[right]>pivot){
			right--;
		}
		//바뀌면 어짜피 left right 이동하게되어있음
		if(left<=right){
			//printf("%d %d %d\n",pivot,left,right);
			swap(array,left,right);
			left++;
			right--;
		
		}
	}

	QuickSort(array,f,right);
	QuickSort(array,left,l);

}



int main(void){

	int T,num;
	scanf("%d",&T);

	for(int i=0;i<T;i++){
		scanf("%d",&num);
		arr[i]=num;
	}

	QuickSort(arr,0,T-1);

	for(int i=0;i<T;i++){
		printf("%d\n",arr[i]);
	
	}
}