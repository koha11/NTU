#include <stdio.h>
#include <math.h>
#define MAX 100

void nhapMang(int a[], int &n);
void xuatMang(int a[], int n);
void dichPhaiMang(int a[], int n, int y);
void nhapY(int &y, int n);
void nhapX(int &x);
int chenMang(int a[], int n, int y, int x);
int chenVaoMangDaSapXep(int a[], int n, int x);
void dichTraiMang(int a[], int n, int i);
int xoaPhanTu(int a[], int n, int y);
int isSNT(int x);
int xoaSNT(int a[], int n);


int main(){
	int a[MAX], n, y,x;
	nhapMang(a,n);
	xuatMang(a,n);
	nhapX(x);
	nhapY(y,n);
	n = chenMang(a,n,y,x);
	nhapX(x);
	n = chenVaoMangDaSapXep(a,n,x);
	nhapY(y,n);
	n = xoaPhanTu(a,n,y);
	printf("\nMang sau khi xoa phan tu thu %d: ", y);
	xuatMang(a,n);
	n = xoaSNT(a,n);
}

void nhapMang(int a[], int &n){
	do{
		printf("Nhap n: ");
		scanf("%d", &n);
	}
	while(n < 2 || n > 50);
	
	printf("Nhap mang: \n");
	for(int i = 0; i < n; i++){
		printf("a[%d] = ", i);
		scanf("%d", &a[i]);
	}
}
void xuatMang(int a[], int n){
	int i;
	for(i = 0; i < n; i++){
		printf("%d ", a[i]);
	}
}
void nhapX(int &x){
	printf("\nNhap x: ");
	scanf("%d", &x);
}
void nhapY(int &y, int n){
	do{
		printf("\nNhap y: ");
		scanf("%d", &y);			
	}
	while(y < 0 || y >= n);
}
void dichPhaiMang(int a[], int n, int y){
	int i;
	
	for(i = n - 1; i > y; i--){
		a[i] = a[i-1];
	}
}
int chenMang(int a[], int n, int y, int x){
	int i;
	

	n++;
	dichPhaiMang(a,n,y);
			
	a[y] = x;
	
	printf("\nMang da chen: ");
	xuatMang(a,n);
	
	return n;	
}
void sapXep(int a[], int n){
	int i, j;
	
	for(i = 0; i < n-1; i++){
		for(j = i+1; j < n; j++)
			if(a[i] > a[j])
			{
				int tam = a[i];
				a[i] = a[j];
				a[j] = tam;
			}
	}	
}
int chenVaoMangDaSapXep(int a[], int n, int x){
	int i;
	
	sapXep(a,n);
	printf("\nMang sau khi sap xep: ");
	xuatMang(a,n);

	for(i = 0; i < n; i++){
		if(x <= a[i])
			break;			
	}
	
	return chenMang(a,n,i,x);	
}

void dichTraiMang(int a[], int n, int i){
	for(; i < n ; i++){ 
		a[i] = a[i+1]; 
	}
}
int xoaPhanTu(int a[], int n, int y){
	int i;
	
	n--;
	dichTraiMang(a,n,y);
	
	return n;
}
int isSNT(int x){
	int i;
	
	if(x < 2)
		return 0;
	else
	{
		for(i = 2; i <= x; i++){
			if(x % i == 0)
				break;
		}
		
		if(x == i)
			return 1;
		else
			return 0;
	}
}
int xoaSNT(int a[], int n){
	int i;
	for(i = 0; i < n; i++){
		if(isSNT(a[i]))
		{
			n = xoaPhanTu(a,n,i);
			i--;
		}
	}
	
	printf("\nMang sau khi xoa tat ca so nguyen to: ");
	xuatMang(a,n);
	
	return n;
}
