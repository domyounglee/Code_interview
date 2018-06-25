#include <stdio.h>
#include <stdlib.h>    
#include <string.h> 
#include <math.h>
unsigned long long hash(char* str_arr, int start_idx, int length){

	unsigned long long hash_val=0;
	unsigned long long power_of_two=1;
	int i;
	for(i=(length-1)+start_idx;i>=start_idx;i--){
		hash_val+=str_arr[i]*power_of_two;
		power_of_two<<=1;
	}
	return hash_val;
}
int main()
{
	int i,j;
	int same_count=0;
	int same_index;
	int str_len;
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
	word_hash=hash(word,0,word_len);
	str_hash=hash(str,0,word_len);
	printf("%lld\n",word_hash);
	for(i = 0;i<str_len-word_len+1;i++){
		
		//hash값 같으면 
		if(str_hash==word_hash){
			if(!strncmp(&str[i],word,word_len)){
				same_count++;
				same_index=i;
			}
			/* same as above
			for(j = 0;j<word_len;j++){
				if(str[i+j] != word[j]) break;
				if(j==word_len-1){
					same_count++;
					same_index=i;
				}
			}
			*/
		}
		//update hash 
		str_hash=2*(str_hash-str[i]*pow(2,word_len-1))+str[i+word_len];
		
	}
	printf("%d\n",same_count);
	printf("%d\n",same_index);

	/*
	for(i = 0;i<str_len-word_len+1;i++){
		for(j = 0;j<word_len;j++){
			if(str[i+j] != word[j]) break;
			if(j==word_len-1){
				same_count++;
				same_index=i;
			}
		}
		
	}

	*/
	free(str);
	free(word);
	return 0;


	
}