//이 문제에서 중요한 부분은 첫 번째 띄어쓰기와 마지막에 나오는 띄어쓰기를 생각해야하는 것이다.

#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <map>

using namespace std;

string s;
int cnt=0;

int main(void){

	
	getline(cin, s);   
	//cout << s <<"\n";

	int i=0;
	while(s[i]!='\0'){
		
		if(isspace(s[i])){cnt+=1;}
		i++;
	}
	
	if(s.at(0)==' ') cnt-=1;
	if(s.at(s.size()-1)==' ') cnt-=1;


	printf("%d",cnt+1);
	 
	
	return 0;

}