#include<stdio.h>
#include<string.h>
void xoaNA(char s[]);
int main(){
	char s[50];
	
	printf("Nhap: ");
	gets(s);
	xoaNA(s);

}
void xoaNA(char s[]){
	char na[] = {'e','u','a','o','i'};
	int i, j;
	
	for(i = 0; i < strlen(s); i++)
		for(j = 0; j < strlen(na); j++)
			if(s[i] == na[j] - 32 || s[i] == na[j])
			{
				strcpy(&s[i], &s[i+1]);
				i--;
			}	
	
	printf("Chuoi da xoa NA: %s", s);
}

