#include<stdio.h>
#include<string.h>
int main(){
	char s[50];
	
	printf("Nhap: ");
	gets(s);
	
	printf("\nChuoi sau khi in hoa la: %s", strupr(s));
	printf("\nChuoi sau khi viet thuong la: %s", strlwr(s));

}

