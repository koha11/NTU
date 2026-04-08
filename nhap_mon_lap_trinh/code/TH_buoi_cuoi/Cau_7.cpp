#include<stdio.h>
#include<string.h>
int main(){
	char s1[50];
	char s2[50];
	
	printf("Nhap s1: ");
	gets(s1);
	printf("Nhap s2: ");
	gets(s2);

	printf("%s", s1);
	fflush(stdin);
	printf(" + ");
	printf("%s", s2);
	printf(" = %s", strcat(s1,s2));
}

