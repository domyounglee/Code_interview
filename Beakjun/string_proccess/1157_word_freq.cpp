#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <map>
using namespace std;

map<char,int> m;
map<char,int>::iterator it;

string str;

int main(void){
	cin >> str;
	for(int i=0;i<str.size();i++){
		char chr = tolower(str[i]);

		if(m.find(chr)!=m.end())
			m[chr]+=1;
		else
			m[chr]=1;

	}
	//m전체를 순회하며 key와 value 출력
	int max=-1;
	char max_char ;
	int max_count=0;
	for(it = m.begin(); it != m.end(); it++){
	    //cout << it->first << ' ' << it->second << '\n';
		if(max == it->second) max_count +=1;
		if(max < it->second) {
			max = it->second;
			max_char = it->first;
			max_count = 1;
		}
	}

	if(max_count == 1) printf("%c",toupper(max_char));
	else printf("?");
	 
	
	return 0;

}