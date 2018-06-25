#include <stdio.h>
//수열에서 제일 큰 덩어리 골라내라
int main(void)
{	
	int array_size=1000;
	//forward index
	int i=0;
	// backward index
	int j=0;
	//whether there exisit difference zero. if exist start at that point
	int seq_size,seq_diff_size,count,start_diff,start_index,zero_diff;
	int max_count=0;	
	int max_index=0;
	printf("insert the size of the sequence\n");
	scanf("%d", &seq_size);
	seq_diff_size=seq_size-1;
    int seq[array_size];
    printf("insert the number\n");
    for(int i=0;i<seq_size;i++){scanf("%d", &seq[i]);}
    printf("this is your sequence\n");
    for(int i=0;i<seq_size;i++){printf("%d\t", seq[i]);}
    printf("\n");
	printf("\n");
	int seq_diff[array_size-1];
	for(int i=0;i<seq_size;i++){seq_diff[i]=seq[i]-seq[i+1];}
	
    printf("\n");
	printf("max sequence is \n");
	while(i<seq_diff_size){
		count=1;
		start_diff=seq_diff[i];
		start_index=i;
		//forward search
		while(start_diff*seq_diff[i+1]>=0 && i<seq_diff_size-1){

			count+=1;
			i+=1;

			if(start_diff==0){start_diff=seq_diff[i];}
		}
		
		//backward search  
		j=start_index;
		while(seq_diff[j-1]==0 && j-1!=0){
			count+=1;
			j-=1;
		}
		
		//update
		if(count>max_count){
			max_count=count;
			max_index=i-count+1;
		}
		i+=1;
	}

	for(int j=0;j<=max_count;j++){
		printf("%d \t",seq[max_index+j]);
	}
	printf("\n");
	printf("%d numbers\n",max_count+1);
	
    return 0;
}

