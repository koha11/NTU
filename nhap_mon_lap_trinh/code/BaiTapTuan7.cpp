#include <stdio.h>
#define MAX 15

void nhapMang(int a[][MAX], int &n);
void xuatMang(int a[][MAX], int n);
void nhapX(int &x);
void timViTriX(int a[][MAX], int n, int x);
int soNguyenToDCChinh(int a[][MAX], int n);
int isSoNguyenTo(int x);
float tbcDCPhu(int a[][MAX], int n);
int maxTamGiacDuoi(int a[][MAX], int n);
void nhapP(int &p);
void isCotToanSoLe(int a[][MAX], int n, int p);
float tbcBoi3DuongBien(int a[][MAX], int n);

int main(){
	int n,x,p;
	int a[MAX][MAX];

	nhapMang(a,n);
	xuatMang(a,n);
	nhapX(x);
	printf("Vi tri cua so %d trong ma tran la: \n", x);
	timViTriX(a,n,x);
	printf("\nSo luong cac so nguyen to duong cheo chinh: %d", soNguyenToDCChinh(a,n));
	printf("\nTrung binh cong duong cheo phu: %.5f", tbcDCPhu(a,n));
	printf("\nMax tam giac duoi DCP la: %d", maxTamGiacDuoi(a,n));
	nhapP(p);
	isCotToanSoLe(a,n,p);
	printf("\nTBC cac phan tu thuoc duong bien la boi cua 3: %.5f", tbcBoi3DuongBien(a,n));

	return 0;
}

void nhapMang(int a[][MAX], int &n){
	int i,j;

	do
	{
		printf("Nhap n: ");
		scanf("%d", &n);
	}
	while (n <= 2|| n >= 15);
	
	printf("Nhap mang: \n");
	for(i = 0; i < n; i++){
		for(j = 0; j < n; j++){
			scanf("%d", &a[i][j]);
		}
	}
}

void xuatMang(int a[][MAX], int n){
	int i,j;

	printf("mang vua nhap: ");
	for(i = 0; i < n; i++){
		printf("\n");
		for(j = 0; j < n; j++){
			printf("%d ", a[i][j]);
		}
	}
}

void nhapX(int &x){
	printf("\nNhap x: ");
	scanf("%d", &x);
}

void timViTriX(int a[][MAX], int n, int x){
	int i,j,k = 0;

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			if(a[i][j] == x){
				printf("(%d,%d) ",i,j);
				k = 1;
			}
		}	
	}

	if(!k)
		printf("Khong co so %d trong ma tran!", x);
}

int isSoNguyenTo(int x){
	int i;

	if (x < 2)
		return 0;
	else
	{
		for (i = 2; i < x; i++)
		{
			if(x % i == 0) 
				break;
		}
		if(x == i)
			return 1;
		else 
			return 0;
	}	
}

int soNguyenToDCChinh(int a[][MAX], int n){
	int count = 0;

	for (int i = 0; i < n; i++)
	{
		if(isSoNguyenTo(a[i][i]))
			count++;
	}

	return count;
}

float tbcDCPhu(int a[][MAX], int n){         
	float sum = 0;

	for (int i = 0; i < n; i++)
	{
		sum += a[i][n - 1 - i];		
	}

	return sum/n;
} 

int maxTamGiacDuoi(int a[][MAX], int n){
	int max, k=1;
	for (int i = n - 1; i > 0; i--)
	{
		for (int j = 0; j < i; j++)
		{
			if(k){
				max = a[i][j];
				k = 0;
			}
			else
				max = max > a[i][j] ? max : a[i][j];
		}				
	}

	return max;
}

void nhapP(int &p){
	printf("\nNhap p: ");
	scanf("%d", &p);
}

void isCotToanSoLe(int a[][MAX], int n, int p){
	int k = 1;
	for (int i = 0; i < n; i++)
	{
		if(a[i][p] % 2 == 0)
			k = 0;
	}

	if(k)
		printf("Tat ca phan tu trong cot %d deu la so le", p);
	else
		printf("Tat ca phan tu trong cot %d khong han la so le", p);		
}

float tbcBoi3DuongBien(int a[][MAX], int n){
	float sum = 0;
	int count = 0;
	
	for(int i = 0; i < n; i++){		
		for(int j = 0; j < n; j++){
			if(i == 0 || i == n - 1)
			{
				if(a[i][j] % 3 == 0)
				{
					sum += a[i][j];
					printf("\n%d\n",a[i][j]);
					count++;
				}
			}
			else if(j == 0 || j == n - 1)
				if(a[i][j] % 3 == 0)
				{
					sum += a[i][j];
					printf("\n%d x\n",a[i][j]);
					count++;
				}
		}
	}

	return sum/count;
}



