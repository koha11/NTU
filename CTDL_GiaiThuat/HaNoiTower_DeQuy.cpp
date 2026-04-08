#include<iostream>
using namespace std;

void HaNoi(int n, char a, char c, char b)
{
	if (n == 1) 
		cout << "disk " << n << " : " << a << " -> " << c <<endl;
	else
	{
		HaNoi(n-1, a, b, c); //(1)
		cout << "disk " << n << " : " << a << " -> " << c <<endl;
		HaNoi(n-1, b, c, a);//(2)
	}
}

/* 	HaNoi(3,'A', 'C', 'B')
	HaNoi(n-1, a, b, c) => (1) (doi vi tri c voi b) 
	HaNoi(n-1, b, c, a) => (2) (doi vi tri a voi b)
	
n = 3, a = A, c = C, b = B: 
	(1)n = 2, a = A, c = B, b = C
		(1)(0)n = 1, a = A, c = C, b = B: output => disk 1 : A -> C
		output => disk 2 : A -> B
		(2)(0)n = 1, a = C, c = B, b = A: output => disk 1 : C -> B
	output => disk 3 : A -> C
	(2)n = 2, a = B, c = C, b = A
		(1)(0)n = 1, a = B, c = A, b = C: output => disk 1 : B -> A
		output => disk 2 : B -> C
		(2)(0)n = 1, a = A, c = C, b = B: output => disk 1 : A -> C

*/

int main()
{
	HaNoi(5, 'A', 'C', 'B');
	return 0;
}
