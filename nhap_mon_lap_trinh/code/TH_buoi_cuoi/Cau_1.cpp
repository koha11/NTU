#include<stdio.h>
#include<string.h>
void nhapChuoi(char s[]);
void xuatChuoiDaoNguoc(char s[]);
void reverse(char s[]);

int main(){
	char s[50];
	nhapChuoi(s);
	xuatChuoiDaoNguoc(s);
	reverse(s);
}

void nhapChuoi(char s[]){
	printf("Nhap chuoi ky tu: ");
	gets(s);
}
void xuatChuoiDaoNguoc(char s[]){
	int i;
	printf("\nChuoi da dao nguoc la: ");
	for(i = strlen(s) - 1; i >= 0; i--)
		printf("%c", s[i]);
}
void reverse(char s[]){
	strrev(s);
	printf("\nChuoi da dao nguoc la: %s", s);
}


