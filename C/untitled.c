#include <stdio.h>
#include <stdlib.h>    
#include <string.h> 
#include <math.h>

int main()
{
	int word_len,str_hash;
	unsigned long long word_hash;
	//string에 공백 있으면 걍 fgets (str, 100, stdin); 이거 써라
	printf("str 길이 : ");
	scanf("%d", &str_len);
	char* str=malloc(sizeof(char) * (str_len+1));
	printf("str ");
	scanf("%s", str);
	printf("%s\n", str);
	printf("word 길이 : ");
	scanf("%d", &word_len);
	char* word=malloc(sizeof(char) * (word_len+1)); 
	printf("word ");
	scanf("%s", word);



	
}