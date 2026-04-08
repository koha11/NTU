#include<stdio.h>
#include<math.h>
#define MAX 10

void input(int matrix[][MAX], int &m, int &n);
void output(int matrix[][MAX], int m, int n);
void findMaxPrimeNum(int matrix[][MAX], int m, int n);
int sumCol(int matrix[][MAX], int m, int n, int c);
void findMaxSquareNum(int matrix[][MAX], int m, int n);
int sumRow(int matrix[][MAX], int m, int n, int r);

int main(){
	int matrix[MAX][MAX], m, n, i, j;
	input(matrix,m,n);
	output(matrix,m,n);
	findMaxPrimeNum(matrix,m,n);
	
	int cMaxIndex = 0, cMax = sumCol(matrix,m,n,0), sumC;
	for(j = 1; j < n; j++)
	{
		sumC = sumCol(matrix,m,n,j);
		if(sumC > cMax)
		{
			cMax = sumC;
			cMaxIndex = j;
		}			
	}
	
	printf("\nChi so cua cot co tong lon nhat la %d voi tong la %d", cMaxIndex, cMax);
	
	findMaxSquareNum(matrix,m,n);

	int sum = 0;
	for(i = 0; i < m; i++){
		sum+= sumRow(matrix,m,n,i);
	}
	printf("\nTong ma tran la: %d", sum);
	
}

void input(int matrix[][MAX], int &m, int &n){
	int i,j;
	do{
		printf("Nhap so hang: ");
		scanf("%d", &m);
		printf("Nhap so cot: ");
		scanf("%d", &n);
	}
	while(m <= 2 || m >=10 || n <= 2 || n >=10);
	
	printf("Nhap ma tran: \n");
	for(i = 0; i < m; i++)
		for(j = 0; j < n; j++)
		{
			printf("matrix[%d][%d] = ", i, j);
			scanf("%d", &matrix[i][j]);	
		}	
}

void output(int matrix[][MAX], int m, int n){
	int i,j;
	printf("Ma tran hien co la: \n");
	for(i = 0; i < m; i++)
	{
		for(j = 0; j < n; j++)
			printf("%d\t", matrix[i][j]);
			
		printf("\n");
	}		
}
void findMaxPrimeNum(int matrix[][MAX], int m, int n){
	int i, j, k, max = 0;
	for(i = 0; i < m; i++)
		for(j = 0; j < n; j++)
		{
			if(matrix[i][j] > 0)
			{
				for(k = 2; k < matrix[i][j]; k++)
					if(matrix[i][j] % k == 0)
						break;				
				if(k == matrix[i][j] || matrix[i][j] == 1)
					max = max > matrix[i][j] ? max : matrix[i][j]; 
			}
		}	
	if(max != 0)
		printf("\nSo nguyen to lon nhat la: %d", max);
	else
		printf("\nKhong co so nguyen to nao");
}
int sumCol(int matrix[][MAX], int m, int n, int c){
	int i, sum = 0;
	
	for(i = 0; i < m; i++)
		sum+=matrix[i][c];
		
	return sum;
}
void findMaxSquareNum(int matrix[][MAX], int m, int n){
	int i,j,max = 0,temp;
	
	for(i = 0; i < m; i++)
		for(j = 0; j < n; j++)
		{
			temp = sqrt(matrix[i][j]);
			if(temp*temp == matrix[i][j])
				if(max == 0)
					max = matrix[i][j];
				else 
					max = max > matrix[i][j] ? max : matrix[i][j];

		}	
	if(max != 0)
		printf("\nSo chinh phuong lon nhat la: %d", max);
	else
		printf("\nKhong co so chinh phuong nao");
}

int sumRow(int matrix[][MAX], int m, int n, int r){
	int j, sum = 0;
	
	for(j = 0; j < n; j++)
		sum+=matrix[r][j];
		
	return sum;
}
