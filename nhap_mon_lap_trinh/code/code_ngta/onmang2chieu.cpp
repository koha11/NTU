#include<stdio.h>
#include<math.h>
#define max 10

//tao lap mt mxn
void taomt(int &m, int &n){
	do{
		printf("Nhap so luong cot: ");
		scanf("%d",&m);
		printf("Nhap so luong hang: ");
		scanf("%d",&n);
	}while(n<=2||n>=10||m<=2||m>=10);	
}

//nhap ma tran
void nhapmt(int a[][max], int m, int n){
	int i,j;
	printf("Nhap cac phan tu co ma tran\n");
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			printf("a[%d][%d]= ",i,j);
			scanf("%d",&a[i][j]);
		}
	}		
}

//xuat ma tran
void xuatmt(int a[][max],int m,int n){
	int i,j;
	printf("\nMa tran vua nhap la:\n");
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			printf(" %d  ",a[i][j]);
		}
		printf("\n");
	}		
}

//kiem tra so nguyen to
int testSNT(int &x){
	if(x<2){
		return 0;
	}
	for(int i=2;i<x;i++){
		if(x%i==0){
			return 0;
		}	
	}
	return 1;
}
 
//tim so nguyen to lon nhat
int SNT(int a[][max], int m, int n){
	int i,j;
	int MAX = 0; // cho MAX = 0 de ktra xem mt co SNT ko
//	for(i=0;i<m;i++){
//		for(j=0;j<n;j++){
//			if(testSNT(a[i][j])==1){
//				MAX=a[i][j];
//				break;	
//			}
//		}
//	} 
// Viet gon lai ho
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			if(testSNT(a[i][j])==1){
				if(MAX == 0)
					MAX=a[i][j]; //them 1 dong vo thoi la du
				else if(MAX<a[i][j])
					MAX=a[i][j];
			}
		}
	}
//	if(dem==0){
//		printf("\nKhong co so nguyen to trong ma tran");
//	}
	return MAX;	
}

//tinh tong 1 cot -->tim cot lon nhat
int tongcot(int a[][max],int m, int n,int c){
	int i;
	int sumcot=0; 
	for(i=0;i<m;i++){
			sumcot+=a[i][c];
	}
	return sumcot;
}

//tim so chinh phuong lon nhat
int SCP(int a[][max],int m,int n){
	int i,j,can;
	int Max=0; 
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			can= sqrt( a[i][j] );
			if(can*can==a[i][j]){
				if(Max==0){
					Max=a[i][j];	
				}
				else{
					if(Max<a[i][j]){
						Max=a[i][j];
					}
				}
				
			}
		}
	}
	if(Max!=0){
		printf("\nSo chinh phuong lon nhat trong ma tran la %d",Max);
	}
	else{
		printf("\nKhong co so chinh phuong trong ma tran");
	}
}

//tinh tong 1 hang--> tinh tong cac phan tu cua mt
int tonghang(int a[][max],int m,int n, int r){
	int j;
	int sumhang=0;
	for(j=0;j<n;j++){
		sumhang+=a[r][j];
	}
	return sumhang;
}
//chuong trinh chinh
int main(){
	int m,n,i,j;
	int a[max][max];
	taomt(m,n);
	nhapmt(a,m,n);
	xuatmt(a,m,n);
	
	if(SNT(a,m,n) == 0)
		printf("\nKhong co so nguyen to trong MT");
	else
		printf("\nSo nguyen to lon nhat trong ma tran la %d",SNT(a,m,n));
		
	int maxc=tongcot(a,m,n,0);
	int sumc,vt;	
	for(j=1;j<n;j++){
		sumc=tongcot(a,m,n,j); //cai nay may dung lon ham tong hang nen no sai dung roi
		if(sumc>maxc){
			maxc=sumc;
			vt=j;
		}
	}
	printf("\nCot %d co tong lon nhat va bang %d",vt,maxc);
	
	SCP(a,m,n);
	
	int sumMT=0;
	for(i=0;i<m;i++){
		sumMT+=tonghang(a,m,n,i);
	}
	printf("\nTong cac phan tu cua ma tran la %d",sumMT);
	
	
}
