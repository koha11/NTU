#include<stdio.h>
#include<string.h>

int main(){
	char s[50];
	printf("Nhap: ");
	gets(s);
	int i, count = 0;
	for(i = 0; i < strlen(s); i++){
		if(s[i] == ' ' && s[i+1] != ' ')
			count++;			
		else if(i == 0)
			count++;	
	}
	
	printf("\nSo tu cua chuoi la: %d", count);
}

