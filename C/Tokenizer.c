#include <stdio.h>
#include <string.h> 

int main()
{
	char s1[30]="The Little Prince";
	char *tokens[30]={NULL,}; //포인터 배열 
	char* ptr= strtok(s1," ");

	int count=0;

	while(ptr!=NULL){
		tokens[count]=ptr;
		count++;
		ptr=strtok(NULL," ");

	}

	for (int i = 0; i < count - 1; i++)
    {
        printf("%s %s\n", tokens[i], tokens[i + 1]);    // 현재 문자열과 그다음 문자열 출력
    }

 




	return 0;
}