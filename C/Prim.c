#include <stdio.h>
#include <stdlib.h>    // malloc, free 함수가 선언된 헤더 파일
#include <limits.h>

int cost_update(int* row_m,int* cost,int*fixed, int col){
    int min_val=INT_MAX;
    int min_index=INT_MAX;

    for(int j=0;j<col;j++){
        //continue if it is not linked
        if(row_m[j]==0){continue;}

        //if it is not fixed and matrix is lower than cost element 
        if(fixed[j]!=1 && cost[j]>row_m[j]){
            //update the cost 
            cost[j]=row_m[j];
        }
        //find the minimum value for index 
        if(fixed[j]!=1 && min_val>cost[j]){
            min_val=cost[j];
            min_index=j;
        }
    }

    return min_index;
}

int main()
{
    int row, col;

    scanf("%d", &row);
    col=row;
    //matrix
    int **m = malloc(sizeof(int *) * row);   // 이중 포인터에 (int 포인터 크기 * row)만큼
                                             // 동적 메모리 할당. 배열의 세로

    for (int i = 0; i < row; i++)            // 세로 크기만큼 반복
    {
        m[i] = malloc(sizeof(int) * col);    // (int의 크기 * col)만큼 동적 메모리 할당. 배열의 가로
    }

    for (int i = 0; i < row; i++)    // 세로 크기만큼 반복
    {
        for (int j = 0; j <= i; j++)    // 가로 크기만큼 반복
        {
            scanf("%d",&m[i][j]);
            m[j][i]=m[i][j];
                        // 2차원 배열의 각 요소에 i + j 값을 할당
        }
    }

    /*
    printf("print matrix\n");

    for (int i = 0; i < row; i++)    // 세로 크기만큼 반복
    {
        for (int j = 0; j < col; j++)    // 가로 크기만큼 반복
        {
            printf("%d ", m[i][j]);      // 2차원 배열의 인덱스에 반복문의 변수 i, j를 지정
        }
        printf("\n");                // 가로 요소를 출력한 뒤 다음 줄로 넘어감
    }
    */
    //cost
    int *cost=malloc(sizeof(int)*col);
    int *fixed=malloc(sizeof(int)*col);

    // initialize cost
    for(int i=0;i<row;i++){
        cost[i]=INT_MAX;
        fixed[i]=0;
    }

    int count=0;
    int i=0;
    int next_i=0;
    cost[i]=0;
    //prim algorithm
    while(count<col-1){

        //fix the zero
        fixed[i]=1;
        //update the cost and return the maxium value's index 
        next_i=cost_update(m[i],cost,fixed,col);
        // update the index 
        printf("______%d\n",next_i);
        i=next_i;
        count++;
    }

    int sum = 0;
    for(int i = 0; i < col ; i++){
        sum+=cost[i];
    }

    printf("%d\n",sum);
    //let it free 
    for (int i = 0; i < row; i++)    // 세로 크기만큼 반복
    {
        free(m[i]);                  // 2차원 배열의 가로 공간 메모리 해제
    }

    free(m);    // 2차원 배열의 세로 공간 메모리 해제

    return 0;
}