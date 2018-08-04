#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <map>
using namespace std;




string str;

int T,check=0;

int main(void){

	scanf("%d",&T);

	for(int i = 0;i< T ; i++){
		map<char,int> m;

		cin >> str;
		for(int i=0;i<str.size();i++){
		char chr =str[i];

		//already exist
		if(m.find(chr)!=m.end() ){
			//but if it is not grouped
			if(str[i-1] != chr){
				
				check+=1;
				break; 
			}

		}
		//not exist
		else
			m[chr]=1;

		}

	}

	printf("%d",T-check);
	 
	
	return 0;

}