#include<iostream>
#include<conio.h>
using namespace std;
#define MAX 1000

int main(){
	char s[80];
	do
	{
		s = getche();
		cout << s[0];
		if(s == 0x0D)
			break;		
	}
	while(1);
}
