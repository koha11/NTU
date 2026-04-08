#include<stdio.h>
#include<math.h>
#define MAX 10

void nhapMT(int mt[][MAX], int &m, int &n);
void xuatMT(int mt[][MAX], int m, int n);
void tbcDuongBien(int mt[][MAX], int m, int n);
void tongSCPTrenDong(int mt[][MAX], int m, int n);
void xoaDong(int mt[][MAX], int &m, int n);
int tongUoc(int num);
int kiemTraCotCoCapSoTT(int mt[][MAX], int m, int n);

int main(){
	int mt[MAX][MAX], m, n;
	
	nhapMT(mt,m,n);
	xuatMT(mt,m,n);
	tbcDuongBien(mt,m,n);
	tongSCPTrenDong(mt,m,n);
	xoaDong(mt,m,n);
	xuatMT(mt,m,n);
	
	if(kiemTraCotCoCapSoTT(mt,m,n) == 1)
		printf("Trong cot ban vua nhap co cap so than thiet!");
	else
		printf("Trong cot ban vua nhap khong co cap so than thiet!");	
}

void nhapMT(int mt[][MAX], int &m, int &n){
	int i, j;
	do{
		printf("Nhap so hang m: ");
		scanf("%d", &m);
		printf("Nhap so cot n: ");
		scanf("%d", &n);		
	}
	while(n < 3 || n > 10 || m < 3 || m > 10);
	for(i = 0; i < m; i++)
		for(j = 0; j < n; j++)
		{
			printf("mt[%d][%d] = ", i, j);
			scanf("%d", &mt[i][j]);
		}
}

void xuatMT(int mt[][MAX], int m, int n){	
	int i, j;
	
	printf("\nMt vua nhap la: \n");
	for(i = 0; i < m; i++)
	{
		for(j = 0; j < n; j++)
			printf("%5d", mt[i][j]);
		printf("\n");
	}
}

void tbcDuongBien(int mt[][MAX], int m, int n){
	float tbc;
	int i, j, tong = 0;
	
	for(i = 0; i < m; i++)
		for(j = 0; j < n; j++)
		{
			if(i == 0 || i == m - 1)
				tong+=mt[i][j];
			else if(j == 0 || j == n - 1)
				tong+=mt[i][j];
		}
		
	tbc = (float)tong/(2*n+(m-2)*2);
	
	printf("TBC cua cac ptu nam tren duong bien la: %.5f", tbc);
}

void tongSCPTrenDong(int mt[][MAX], int m, int n){
	int j, d, temp, tong = 0;
	do{
		printf("\nNhap dong d: ");
		scanf("%d", &d);
	}
	while(d >= m || d < 0);
	
	for(j = 0; j < n; j++)
	{
		temp = sqrt(mt[d][j]);
		if(temp*temp == mt[d][j])
			tong += mt[d][j];
	}
		
	if(tong == 0)
		printf("Dong thu %d khong co so chinh phuong!", d);
	else
		printf("Tong so chinh phuong tren dong thu %d la: %d", d, tong);
}

void xoaDong(int mt[][MAX], int &m, int n){
	int i, j, d1;
	do{
		printf("\nNhap dong d1: ");
		scanf("%d", &d1);
	}
	while(d1 > m || d1 < 0);
	
	m--;
	for(i = d1; i < m; i++)
		for(j = 0; j < n; j++)
			mt[i][j] = mt[i+1][j];
}

int tongUoc(int num){
	int tong = 0, uoc[30], count = 0, j = 1;
	
		while(j != num){
			if(num % j == 0)
			{
				uoc[count] = j;
				count++;
			}
			j++;
		}
		
		for(j = 0; j < count; j++)
			tong += uoc[j];
			
	return tong;	
}


int kiemTraCotCoCapSoTT(int mt[][MAX], int m, int n){
	int i, j, c;
	
	do{
		printf("\nNhap cot c: ");
		scanf("%d", &c);
	}
	while(c < 0 || c > n);
	
	for(i = 0; i < m; i++)
		for(j = 0; j < m; j++) 
			if(tongUoc(mt[i][c]) == mt[j][c])
				if(tongUoc(mt[j][c]) == mt[i][c])
					return 1;
	
	return 0;
}

