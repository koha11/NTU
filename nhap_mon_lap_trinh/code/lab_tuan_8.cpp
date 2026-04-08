#include<stdio.h>

#define maxcot 4

void nhapmatran(int a[][maxcot], int &sohang, int &socot);
void inmatran(int a[][maxcot], int hang, int cot);
void tonghang(int a[][maxcot], int hang, int cot);
void tongcot(int a[][maxcot], int hang, int cot);
int isMaPhuong(int a[][maxcot], int hang, int cot);
int isDoiXung(int a[][maxcot], int hang, int cot);
void nhanHaiMaTran();

int main(){
	int sohang, socot;
	int a[maxcot][maxcot];
	
	nhapmatran(a,sohang,socot);
	inmatran(a,sohang,socot);
	tonghang(a,sohang,socot);
	tongcot(a,sohang,socot);
	if(isMaPhuong(a,sohang,socot))
		printf("\nMa tran nay la ma phuong");
	else
		printf("\nMa tran nay khong la ma phuong");
		
	if(isDoiXung(a,sohang,socot))
		printf("\nMa tran nay la ma tran doi xung");
	else
		printf("\nMa tran nay khong la ma tran doi xung");
	nhanHaiMaTran();
}

void nhapmatran(int a[][maxcot], int &sohang, int &socot){
	int i, j;
	
	do{
		printf("Nhap so hang: ");
		scanf("%d", &sohang);
		printf("Nhap so cot: ");
		scanf("%d", &socot);
	}
	while(sohang < 1 || sohang >= 5);
	
	printf("Nhap cac phan tu mang: \n");
	for(i = 0; i < sohang; i++)
		for(j = 0; j < socot; j++)
		{
			printf("a[%d][%d] = ", i, j);
			scanf("%d", &a[i][j]);
		}
}

void inmatran(int a[][maxcot], int hang, int cot){
	int i, j;

	printf("\nMang vua nhap la: \n");
	for(i = 0; i < hang; i++)
	{
		for(j = 0; j < cot; j++)
			printf("%d ", a[i][j]);
		printf("\n");
	}
}

void tonghang(int a[][maxcot], int hang, int cot){
	int i, j, sum = 0;
	
	for(i = 0; i < hang; i++)
	{
		for(j = 0; j < cot; j++)
			sum+=a[i][j];
					
		printf("\nTong cua hang thu %d la: %d", i, sum);
		sum = 0;
	}			
}

void tongcot(int a[][maxcot], int hang, int cot){
	int i, j, sum = 0;
	
	for(j = 0; j < cot; j++)
	{
		for(i = 0; i < hang; i++)
			sum+=a[i][j];
					
		printf("\nTong cua cot thu %d la: %d", j, sum);
		sum = 0;
	}			
}

int isMaPhuong(int a[][maxcot], int hang, int cot){
	int i, j, sum, sumDCC = 0, sumDCP = 0;
	
	int count = 0;
	int tong[hang*2 + 2];
	
	//cach 2
	for(i = 0; i < hang; i++)
	{
		sum = 0;
		for(j = 0; j < cot; j++){
			sum+=a[i][j];
			sumDCC += a[i][i];
			sumDCP +=a[i][hang-i-1];	
		}
			
		tong[count++] = sum;
	}
	
	tong[count++] = sumDCC;
	
	tong[count++] = sumDCP;
	
	for(j = 0; j < cot; j++)
	{		
		sum = 0;
		for(i = 0; i < hang; i++)	
			sum+=a[i][j];
			
		tong[count++] = sum;
	}	
	
	for(i = 0; i < count - 1; i++)
	{
		if(tong[i] != tong[i+1])
			return 0;
	}
	return 1;
}

int isDoiXung(int a[][maxcot], int hang, int cot){
	int i,j;
	for(i = 0; i < hang; i++)
		for(j = 0; j < cot; j++)
		{
			if(a[i][j] != a[j][i])
				return 0;
		}
	
	return 1;	
}

void nhanHaiMaTran(){
	int i,j, k, sum;
	int mta[maxcot][maxcot],mtb[maxcot][maxcot];
	int hangA, cotA, hangB,cotB;
	int mtc[maxcot][maxcot];
	
	printf("\nNhap mt A: \n");
	nhapmatran(mta,hangA,cotA);
	printf("\nNhap mt B: \n");
	nhapmatran(mtb,hangB,cotB);
	
//	int mta[3][3]={{1,2,3},{4,5,6},{7,8,9}};
//	int mtb[3][2]={{1,1},{0,1},{1,0}};
		
	if(cotA != hangB)
		printf("Khong thoa quy tac nhan 2 ma tran");
	else
	{
		for(i = 0; i < hangA; i++)
			for(j = 0; j < cotB; j++)
			{
				sum = 0;
				for(k = 0; k < hangA;k++)
				{
					sum+=mta[i][k]*mtb[k][j];
				}
				
				mtc[i][j] = sum;
			}
		inmatran(mtc,hangA,cotB);
	}
	
}




