// you can write to stdout for debugging purposes, e.g.
// printf("this is a debug message\n");

int solution(int A[], int N) {
    // write your code in C99 (gcc 6.2.0)
    
    int max=-1;
    int non_neg=0 ; 
    int check=0;
    for(int i = 0; i<N ;i++){
        if(A[i]>=0){
            non_neg+=A[i];
            check+=1;
        }
        else{

            if(max<non_neg) max=non_neg;
            non_neg=0;
            continue;
        }
    }
    
    if(max<non_neg) max=non_neg;
    
    if(check==0) return -1;
    else return max;
}