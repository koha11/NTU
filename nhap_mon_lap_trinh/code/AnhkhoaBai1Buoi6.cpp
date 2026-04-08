#include <stdio.h>
#include <math.h>
#define MAX 100

void nhapMang(int a[], int &n);
void xuatMang(int a[], int n);
int soAmLonNhat(int a[], int n);
void hoanVi(int *x, int *y);
void sapXep(int a[], int n); //so am tang, so duong giam 
void tachMang(int a[], int n);
void convert(int a[], int n);

int main(){
	int a[MAX], n;
	nhapMang(a,n);
	printf("\nmang vua nhap la: ");
	xuatMang(a,n);
	if(soAmLonNhat(a,n))
		printf("\nSo am lon nhat trong mang la: %d", soAmLonNhat(a,n));
	else 
		printf("\nKhong co so am trong mang!");
	sapXep(a,n);
	printf("\nMang vua sap xep la: ");
	xuatMang(a,n);
	tachMang(a,n);
	convert(a,n);
	printf("\nMang sau khi doi gia tri: ");
	xuatMang(a,n);
}

void nhapMang(int a[], int &n){
	do{
		printf("Nhap n: ");
		scanf("%d", &n);
	}
	while(n < 3 || n > 100);
	
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
int soAmLonNhat(int a[], int n){
	int max = 0, i;
	
	for(i = 0; i < n; i++){
		if(a[i] < 0){
			if(max == 0)
				max = a[i];
			else if(a[i] > max)
				max = a[i];
		}
	}
	
	return max;
}
void hoanVi(int *x, int *y){
	int tam = *x;
	*x = *y;
	*y = tam;
}
void sapXep(int a[], int n){
	int b[MAX], c[MAX], b_count = 0, c_count = 0, i, j;
	for(i = 0; i < n; i++){
		if(a[i] < 0){
			b[b_count] = i;
			b_count++;
		}
		else if(a[i] > 0){
			c[c_count] = i;
			c_count++;
		}
	}
	
	for(i = 0; i < b_count - 1; i++){
		for(j = i+1; j < b_count; j++){
			if(a[b[i]] > a[b[j]])
			hoanVi(&a[b[i]],&a[b[j]]);
		}
	}
	
	for(i = 0; i < c_count - 1; i++){
		for(j = i+1; j < c_count; j++){
			if(a[c[i]] < a[c[j]])
			hoanVi(&a[c[i]],&a[c[j]]);
		}
	}
}
void tachMang(int a[], int n){
	int b[MAX], c[MAX], b_count = 0, c_count = 0, i;
	
	for(i = 0; i < n; i++){
		if(a[i] < 0){
			b[b_count] = a[i];
			b_count++;
		}
		else if(a[i] > 0){
			c[c_count] = a[i];
			c_count++;
		}
	}
	
	printf("\nMang nguyen duong: ");
	xuatMang(c,c_count);
	printf("\nMang nguyen am: ");	
	xuatMang(b,b_count);
}

void convert(int a[], int n){
	int i;
	
	for(i = 0; i < n; i++){
		if(a[i] < 0)
			a[i] = -1;
		if(a[i] > 0)
			a[i] = 1;
	}
}


