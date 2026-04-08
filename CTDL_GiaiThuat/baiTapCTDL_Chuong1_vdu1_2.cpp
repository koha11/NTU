#include<iostream>
#define MAX 30
using namespace std;


struct PS
{
	int tuSo;
	int mauSo;
};

void nhap(PS ps[][MAX], int &m, int &n);
void xuat(PS ps[][MAX], int m, int n);
void toiGian(PS ps[][MAX], int m, int n);
int calcUCLN(int a, int b);
PS maxPs(PS ps[][MAX], int m, int n);

int main()
{
	PS ps[MAX][MAX];
	int m,n;
	
	nhap(ps,m,n);
	xuat(ps,m,n);
	
	toiGian(ps,m,n);
	xuat(ps,m,n);
	
	PS max = maxPs(ps,m,n);
	cout << "MAX = " << max.tuSo << "/" << max.mauSo << endl;

	return 0;
}

void nhap(PS ps[][MAX], int &m, int &n)
{
	cout << "m = ";
	cin >> m;
	cout << "n = ";
	cin >> n;
	
	cout << "Nhap ma tran phan so: " << endl;
	for(int i = 0; i < m; i++)
		for(int j = 0; j < n; j++)	
			cin >> ps[i][j].tuSo >> ps[i][j].mauSo;				
}
void xuat(PS ps[][MAX], int m, int n)
{
	cout << "Ma tran phan so: " << endl;
	for(int i = 0; i < m; i++)
	{
		for(int j = 0; j < n; j++)	
			cout << ps[i][j].tuSo << "/" << ps[i][j].mauSo << " ";
		cout << endl;
	}
}

void toiGian(PS ps[][MAX], int m, int n) // 3/9
{
	for(int i = 0; i < m; i++)
		for(int j = 0; j < n; j++)	
		{
			int ucln = calcUCLN(ps[i][j].tuSo,ps[i][j].mauSo);
			ps[i][j].tuSo /= ucln;
			ps[i][j].mauSo /= ucln;
		}
}

int calcUCLN(int a, int b)
{
	while(a != b)
		if(a > b)
			a -= b;
		else
			b -= a;
	return a;
}

PS maxPs(PS ps[][MAX], int m, int n)
{
	PS max = ps[0][0];
	for(int i = 0; i < m; i++)
		for(int j = 0; j < n; j++)	
		{
			if(ps[i][j].tuSo*max.mauSo > max.tuSo*ps[i][j].mauSo)
				max = ps[i][j];
		}
		
	return max;
}

