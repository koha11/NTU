#include <stdio.h>
#define maxcot 30
#define maxhang 30

void nhapMT(int mt[][maxcot], int &sohang, int &socot){
	do{
		printf("Nhap so hang: ");
		scanf("%d", &sohang);
		printf("Nhap so cot: ");
		scanf("%d", &socot);
	}
	while(sohang != socot || sohang < 3 || socot >= 5);
	
	for(int i = 0; i < sohang; i++){
		for(int j = 0; j < socot; j++) {
			printf("Nhap mt[%d][%d] = ", i, j);
			scanf("%d", &mt[i][j]);
		}
	}
}

void xuatMT(int mt[][maxcot], int sohang, int socot){
	for(int i = 0; i < sohang; i++){
		for(int j = 0; j < socot; j++) {
			printf("%5d", mt[i][j]);
		}
		printf("\n");
	}
}

void chuyenViMT(int mt[][maxcot], int mt_t[][maxcot], int sohang, int socot){
	for(int i = 0; i < sohang; i++){
		for(int j = 0; j < socot; j++){
			mt_t[i][j] = mt[j][i];
		}
	}
}

int searchX(int mt[][maxcot], int sohang, int socot, int X){
	int poshang = -1; 
	int poscot = -1;
	
	for(int i = 0; i < sohang; i++){
		for(int j = 0; j < socot; j++) {		
			if(mt[i][j] == X){					
				poshang = i;
				poscot = j;
				break;
			}	
		}	
	}
	
	if(poshang = -1)
		return -1;
	else
		return (poshang*3 + poscot);
}

void duongCheoChinh(int mt[][maxcot], int sohang, int socot){
	
	printf("Nua duoi cua duong cheo chinh: \n");
	for(int i = 0; i < sohang; i++){ //nua duoi
		for(int j = 0; j < socot; j++) {
			if(j >= i)
				printf("%5d", 0);
			else
				printf("%5d", mt[i][j]);
		}
		printf("\n");
	}
	
	printf("Nua tren cua duong cheo phu: \n");
	for(int i = 0; i < sohang; i++){ //nua tren
		for(int j = 0; j < socot; j++) {
			if(j <= i)
				printf("%5d", 0);
			else
				printf("%5d", mt[i][j]);
		}
		printf("\n");
	}
}

void duongCheoPhu(int mt[][maxcot], int sohang, int socot){
	
	printf("Nua duoi cua duong cheo phu: \n");
	for(int i = 0; i < sohang; i++){ //nua duoi
		for(int j = 0; j < socot; j++) {                //1 2 3    m,n=3  a[i][n-1-i] a[][] 
			if(j > sohang-1-i)										//4	5 6		
				printf("%5d", 0);						//7 8 9
			else
				printf("%5d", mt[i][j]);
		}
		printf("\n");
	}
	
	printf("Nua tren cua duong cheo phu: \n");
	for(int i = 0; i < sohang; i++){ //nua tren
		for(int j = 0; j < socot; j++) {
			if(j <= i)
				printf("%5d", 0);
			else
				printf("%5d", mt[i][j]);
		}
		printf("\n");
	}
}

int main(){
	int mt[maxhang][maxcot], mt_t[maxhang][maxcot], sohang, socot, X;
	
	nhapMT(mt,sohang,socot);
	xuatMT(mt,sohang,socot);
	chuyenViMT(mt,mt_t,sohang,socot);
	printf("MT sau khi chuyen vi: \n");
	xuatMT(mt_t,sohang,socot);
	printf("\nNhap X: ");
	scanf("%d", &X);
	
	//(1,0): (3+0): 3/3=1: 3&3 = 0
	int vt_hang_mt = searchX(mt,sohang,socot,X) / 3;         
	int vt_cot_mt = searchX(mt,sohang,socot,X) % 3;
	printf("Da tim thay X o vi tri hang %d cot %d trong mt\n", vt_hang_mt, vt_cot_mt);
	
	int vt_hang_mt_t = searchX(mt_t,sohang,socot,X) / 3;         
	int vt_cot_mt_t = searchX(mt_t,sohang,socot,X) % 3;
	printf("Da tim thay X o vi tri hang %d cot %d trong mt_t\n", vt_hang_mt_t, vt_cot_mt_t);
	
	duongCheoChinh(mt,sohang,socot);
}
