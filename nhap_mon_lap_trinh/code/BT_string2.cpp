#include<stdio.h>
#include<stddef.h>
#include<string.h>



int main(){
	char s[50];
	int i;
	printf("Nhap ho va ten: ");
	gets(s);
	while( s[0] == ' ' ) 
		strcpy(&s[0], &s[1]);
	while(s[strlen(s)-1 ] == ' ') 
		s[strlen(s)-1 ] = '\0';
		
	for(i = 0; i < strlen(s); i++)
		if(s[i] == ' ' && s[i+1] == ' '){
        	strcpy(&s[i], &s[i+1]);
			i--;
		}
		
	printf("%s", s);		 
}
