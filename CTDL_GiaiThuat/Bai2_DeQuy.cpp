#include<iostream>
using namespace std;

int dem(char s[], int x)
{
	if(s[x] == '\0')
		return x;
		
	return dem(s,x+1);	
}

int main()
{
	cout << dem("KHOAAAAAAAAAAAAAA",0);
	return 0;
}

