#include<iostream>
#include<string.h>
#define MAX 30

using namespace std;

struct NV
{
	char maNV[9];
	char hoVaTen[21];
	char phongBan[11];
	int luongCB;
	int thuong;
	int thucLanh;
};

void nhap(NV nv[MAX], int &n);
void xuat(NV nv[MAX], int n);
int tongThucLanh(NV nv[MAX], int n, int i);
void dsLuongCBThap(NV nv[MAX], int n);
int countThuongMoreThan1m2(NV nv[MAX], int n);
void swap(NV &nv1, NV &nv2);
void sapXep(NV nv[MAX], int n); //tang dan theo phong ban || cung phong ban thi` giam dan theo msnv


int main()
{
	NV nv[MAX];
	int n;
	
	nhap(nv,n);
	xuat(nv,n);
	
	cout << "Tong thuc lanh = " << tongThucLanh(nv,n,0) << endl;
	
	dsLuongCBThap(nv,n);
	
	cout << "So NV co thuong >= 1tr2: " << countThuongMoreThan1m2(nv,n) << endl;
	
	sapXep(nv,n);
	xuat(nv,n);

	return 0;
}

void nhap(NV nv[MAX], int &n)
{
	cout << "n = ";
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		cout << "Ma NV: ";
		fflush(stdin);
		gets(nv[i].maNV);
		
		cout << "Ho va ten: ";
		fflush(stdin);
		gets(nv[i].hoVaTen);
		
		cout << "Phong ban: ";
		fflush(stdin);
		gets(nv[i].phongBan);				
		
		cout << "Luong CB: ";
		cin >> nv[i].luongCB;	
		
		cout << "Thuong: ";
		cin >> nv[i].thuong;
		
		nv[i].thucLanh = nv[i].luongCB+nv[i].thuong;
	}
}

void xuat(NV nv[MAX], int n)
{     	
	cout << "Ma NV\t Ho va ten\t Phong ban\t Luong CB\t Thuong\t Thuc lanh" << endl;
	for(int i = 0; i < n; i++)
		cout<<nv[i].maNV<<"\t "<< nv[i].hoVaTen <<"\t "<<nv[i].phongBan<<"\t "<<nv[i].luongCB<<"\t "<<nv[i].thuong<<"\t "<<nv[i].thucLanh<< endl;
}


int tongThucLanh(NV nv[MAX], int n, int i)
{
	if(i == n)
		return 0;
	return nv[i].thucLanh + tongThucLanh(nv,n,i+1);
}

void dsLuongCBThap(NV nv[MAX], int n)
{
	int min = nv[0].luongCB;
	
	for(int i = 1; i < n; i++)
		if(min > nv[i].luongCB)
			min = nv[i].luongCB;
		
	cout << "Ma NV\t Ho va ten\t Phong ban\t Luong CB\t Thuong\t Thuc lanh" << endl;
	for(int i = 0; i < n; i++)
		if(min == nv[i].luongCB)
			cout<<nv[i].maNV<<"\t "<< nv[i].hoVaTen <<"\t "<<nv[i].phongBan<<"\t "<<nv[i].luongCB<<"\t "<<nv[i].thuong<<"\t "<<nv[i].thucLanh<< endl;			
}

int countThuongMoreThan1m2(NV nv[MAX], int n)
{
	int count = 0;
	
	for(int i = 0; i < n; i++)
		if(nv[i].thuong >= 1200000)
			count++;
			
	return count;			
}

void swap(NV &nv1, NV &nv2)
{
	NV temp = nv1;
	nv1 = nv2;
	nv2 = temp;
}

void sapXep(NV nv[MAX], int n)
{
	for(int i = 0; i < n-1; i++)
		for(int j = i+1; j < n; j++)
			if(strcmp(nv[i].phongban,nv[j].phongban) > 0 || (strcmp(nv[i].phongban,nv[j].phongban)==0 && strcmp(nv[i].manv,nv[j].manv)<0))
				swap(nv[i],nv[j]);		
}
