#include<iostream>
#include<math.h>
using namespace std;

void qs(int a[], int l, int r)
{
	int mid, key;
	
	mid = (l+r)/2;
	key = a[mid];
	int i = l, j = r;
	
	while(i < j)
	{
		while(a[i] < key)
			i++;
		while(a[j] > key)
			j--;
		if(i < j)
		{
			int temp = a[i];
			a[i] = a[j];
			a[j] = temp;
		}
		i++;
		j--;
	}
	
	if(i < r)	
		qs(a,i,r);
	if(j > l)
		qs(a,l,j);
}

void output(int a[], int n)
{
	for(int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}

int main()
{
	int a[] = {4,54,235,1,5431,432,542,534,15};
	int n = sizeof(a)/sizeof(a[0]);
	output(a,n);
	qs(a,0,n-1);
	output(a,n);
}
