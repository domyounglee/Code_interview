#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <map>
using namespace std;

map<char,int> m;

string str;

int main(void){

	int num;
	int n=0;
	scanf("%d",&num);

	
	while(3*n*n+3*n+1<num){
		n++;
	}

	printf("%d",n+1);

	
	return 0;

}