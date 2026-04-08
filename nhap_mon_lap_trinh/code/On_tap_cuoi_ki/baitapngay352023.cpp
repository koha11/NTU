#include<stdio.h>
#include<string.h>
#define max 50
//cau truc hoc phan
struct hocphan{
	char maHP[10];
	char tenHP[40];
	int soTC;
	float dtb;
};
// nhap n hoc phan
void SLHP(int &n){
	do{
		printf("Nhap so luong hoc phan: ");
		scanf("%d",&n);
	}while(n<=0||n>=10);
}
//nhap thong tin hp
void nhap(hocphan dshp[],int n){
	printf("Nhap thong tin hoc phan:\n");
	int i;
	for (i=0;i<n;i++){
		printf("Hoc phan thu %d",i+1);
		printf("\nNhap ma hoc phan: ");
		scanf("%s",dshp[i].maHP);
		fflush(stdin);
		printf("Nhap ten hoc phan: ");
		gets(dshp[i].tenHP);
		printf("Nhap so tin chi: ");
		scanf("%d",&dshp[i].soTC);
		printf("Nhap diem trung binh: ");
		scanf("%f",&dshp[i].dtb);
	}
}
//xuat thong tin
void xuat(hocphan dshp[],int n){
	printf("\nThong tin hoc phan vua nhap");
	int i;
	printf("\nma hoc phan\tten hoc phan\tso tin chi\tdtb");
	for(i=0;i<n;i++){
//		char maHP[10], tenHP[40];
////		strcpy(maHP,dshp[i].maHP);
////		strcpy(tenHP,dshp[i].tenHP);
//		int soTC = dshp[i].soTC;
//		float dtb = dshp[i].dtb;
		printf("\n%s\t%s\t%d\t%f",dshp[i].maHP,dshp[i].tenHP,dshp[i].soTC,dshp[i].dtb);
//		printf("\n%s\t%s\t%d\t%f",maHP,tenHP,soTC,dtb);
	}
}
//xuat diem trung binh dat
void xuat_DTB(hocphan dshp[],int n){
	printf("\nDanh sach cac hoc phan dat:");
	int i;
	char maHP[10], tenHP[40];
	printf("\nmaHP\ttenHP\tsoTC\tdtb");
	for(i=0;i<n;i++){
		strcpy(maHP,dshp[i].maHP);
		strcpy(tenHP,dshp[i].tenHP);
		int soTC = dshp[i].soTC;
		float dtb = dshp[i].dtb;
		if(dtb>=5){
			printf("\n%s\t%s\t%d\t%f",maHP,tenHP,soTC,dtb);
		}
	}
}
int main(){
	int n;
	hocphan hp;
	hocphan dshp[max];
	SLHP(n);
	nhap(dshp,n);
	xuat(dshp,n);
	xuat_DTB(dshp,n);	
}
