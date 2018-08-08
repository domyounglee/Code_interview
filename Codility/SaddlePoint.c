

int solution(int **A, int N, int M) {
    // write your code in C99 (gcc 6.2.0)
    int count =0;
    for(int i=1; i<N-1 ;i++){
        for(int j=1; j<M-1; j++){
            if(A[i-1][j] > A[i][j] && A[i][j] < A[i+1][j]){
                if(A[i][j-1] < A[i][j] && A[i][j] > A[i][j+1]){
                    count++;
                }
            }
            
            if(A[i-1][j] < A[i][j] && A[i][j] > A[i+1][j]){
                if(A[i][j-1] > A[i][j] && A[i][j] < A[i][j+1]){
                    count++;
                }
            }
        }
        
    }
    
    return count;
}