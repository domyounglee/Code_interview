
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;


int main(void){

	int a=0;
	int b=0;

	cin >> a;
	cin >> b;

	int new_a = a%10*100+(a%100-a%10)+a/100;
	int new_b = b%10*100+(b%100-b%10)+b/100;

	if(new_a < new_b) printf("%d",new_b);
	else printf("%d",new_a);

	
	return 0;

}