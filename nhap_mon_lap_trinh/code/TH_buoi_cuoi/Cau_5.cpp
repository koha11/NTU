#include<stdio.h>
#include<string.h>

void xoaKyTuTrang(char s[]);
int main(){
	char s[50];
	
	printf("Nhap: ");
	gets(s);
	
	xoaKyTuTrang(s);
}
void xoaKyTuTrang(char s[]){
	int i;
	
	for(i = 0; i < strlen(s); i++)
		if(s[i] == ' ' && s[i+1] == ' ')
		{
			strcpy(&s[i], &s[i+1]);
			i--;
		}
			
	printf("Chuoi da xoa ky tu trang thua: %s", s);
}


