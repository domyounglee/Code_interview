#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int T,R;
string str;

int main(void){

	scanf("%d",&T);
	for(int i=0;i<T;i++){

		scanf("%d",&R);
		cin >> str;

		for(int i=0;i<str.size();i++){
			for(int j=0;j<R;j++) printf("%c",str[i]);

		}
		printf("\n");

	}

	return 0;

}