#include<iostream>
using namespace std;

int giaiThua(int x)
{
	if(x == 1) // DK dung
		return 1; 
	return x*giaiThua(x-1); // DE QUY
}

int main(){
	int x = 4;
	cout << giaiThua(x);

	return 0;
}

