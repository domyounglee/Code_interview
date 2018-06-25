#include <stdio.h>
#include <stdlib.h>    // malloc, free 함수가 선언된 헤더 파일
#include <limits.h>
int update_row0(int** m,int* check,int idx,int col){

    for(int j=0;j<col;j++){
        // continue if it is checked or the idx has not connect to the j's node
        if(check[j]==1 || m[idx][j]==INT_MAX) continue;
        if(m[0][idx]+m[idx][j] < m[0][j]){
            m[0][j]=m[0][idx]+m[idx][j];
          
        }
    }

    return 0;
}
int find_min_idx_from_row0(int* row_m, int* check,int col){
    int min=INT_MAX;
    int min_idx=-1;
    for(int j=0;j<col;j++){
        if(check[j]==1 ) continue;
        if(row_m[j]<min){
            min=row_m[j];
            min_idx=j;
        }
    }
    return min_idx;
}

int main()
{
    int row, col;
    int temp;
    int count=0;
    scanf("%d", &row);
    col=row;
    //matrix
    int **m = malloc(sizeof(int *) * row);   // 이중 포인터에 (int 포인터 크기 * row)만큼
                                     // 동적 메모리 할당. 배열의 세로

    for (int i = 0; i < row; i++)            // 세로 크기만큼 반복
    {
        m[i] = malloc(sizeof(int) * col);    // (int의 크기 * col)만큼 동적 메모리 할당. 배열의 가로
    }

    for (int i = 0; i < row; i++)    // 가로 크기만큼 반복
    {
        for (int j = 0; j < col; j++)    // 세로 크기만큼 반복
        {
            scanf("%d",&temp);
            if(temp==0) m[i][j]=INT_MAX;
            else m[i][j]=temp;
                        
        }
    }

    //make check array
    int *check = malloc(sizeof(int ) * row); 

    for(int i = 0; i<row ;i++){
        check[i]=0;
    }

    int idx=0;
    check[0]=1;
    while(count<row-1){
        
        
        //find the lowest value's index based on present index
        idx=find_min_idx_from_row0(m[0],check,col);
        printf("---%d\n",idx);
        //check the idx 
        check[idx]=1;
        update_row0(m,check,idx,col);
        for(int j=0; j<col;j++){
            printf("+%d\n",m[0][j]);
        }
        count++;
    }







    printf("print matrix\n");

    for (int i = 0; i < row; i++)    // 세로 크기만큼 반복
    {
        for (int j = 0; j < col; j++)    // 가로 크기만큼 반복
        {
            printf("%d ", m[i][j]);      // 2차원 배열의 인덱스에 반복문의 변수 i, j를 지정
        }
        printf("\n");                // 가로 요소를 출력한 뒤 다음 줄로 넘어감
    }
    
    
    



    //let it free 
    for (int i = 0; i < row; i++)    // 세로 크기만큼 반복
    {
        free(m[i]);                  // 2차원 배열의 가로 공간 메모리 해제
    }

    free(m);    // 2차원 배열의 세로 공간 메모리 해제

    return 0;
}