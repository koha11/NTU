#include<stdio.h>
#include<string.h>
#define MAX 30

struct Hocphan{
	char maHP[MAX];
	char tenHP[MAX];
	int soTC;
	float dtb;
};

void nhapHP(Hocphan danhSachHP[], int &n);
void xuatHP(Hocphan danhSachHP[], int n);
void demSoHPDat(Hocphan danhSachHP[], int n);

int main(){
	Hocphan danhSachHP[MAX];
	int n;
	nhapHP(danhSachHP,n);
	xuatHP(danhSachHP,n);
	demSoHPDat(danhSachHP,n);
}

void nhapHP(Hocphan danhSachHP[], int &n){
	do{
		printf("Nhap so luong hoc phan: ");
		scanf("%d",&n);
	}while(n<=2||n>=10);
	printf("Nhap thong tin hoc phan:\n");
	int i;
	for(i=0;i<n;i++){
		printf("Hoc phan thu %d",i+1);
		
		printf("\nNhap ma hoc phan: ");
		scanf("%s",danhSachHP[i].maHP);
		
		fflush(stdin);
		
		printf("Nhap ten hoc phan: ");
		gets(danhSachHP[i].tenHP);

		printf("Nhap so tin chi: ");
		scanf("%d",&danhSachHP[i].soTC);	
		
			printf("Nhap diem trung binh: ");
			scanf("%f",&danhSachHP[i].dtb);
	}
}
void xuatHP(Hocphan danhSachHP[], int n){
	printf("\nThong tin hoc phan vua nhap");
	int i;
	printf("\nmaHP\ttenHP\tsoTC\tdtb");
	for(i=0;i<n;i++)
		printf("\n%s\t%s\t%d\t%f",danhSachHP[i].maHP,danhSachHP[i].tenHP,danhSachHP[i].soTC,danhSachHP[i].dtb);
}
void demSoHPDat(Hocphan danhSachHP[], int n){
	printf("\nDanh sach cac hoc phan dat:");
	int i;
	char maHP[10], tenHP[40];
	printf("\nmaHP\ttenHP\tsoTC\tdtb");
	for(i=0;i<n;i++)
		if(danhSachHP[i].dtb>=5)
			printf("\n%s\t%s\t%d\t%f",danhSachHP[i].maHP,danhSachHP[i].tenHP,danhSachHP[i].soTC,danhSachHP[i].dtb);
}
