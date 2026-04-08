#include<stdio.h>
#include<string.h>

int main(){
	char s[50];
	int i;
	
	printf("Nhap chuoi: ");
	gets(s);
	
	for(i = 0; i < strlen(s); i++){
		if(s[i] > 47 && s[i] < 58)
			s[i] = 63;
	}
	
	printf("%s", s);
}
