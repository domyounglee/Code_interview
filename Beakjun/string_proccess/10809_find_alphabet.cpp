#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int str_arr[26];

int main(void){

	int str_arr[26];

	string str;


	for(int i=0;i<26;i++) str_arr[i]=-1;
	

	cin >> str;

	for(int i=0;i<str.size();i++){
		int ascii = str[i];
		if(str_arr[ascii-97]==-1) str_arr[ascii-97]=i;
		
	}



	for(int i=0;i<26;i++){
		printf("%d ",str_arr[i]);
	}


	return 0;

}