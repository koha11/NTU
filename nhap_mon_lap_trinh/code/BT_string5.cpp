#include<stdio.h>
#include<string.h>

int main(){
	char s[50], s2[50];
	int i, j = 0, logic = 0;
	
	printf("Nhap chuoi: ");
	gets(s);
	
	for(i = 0; i < strlen(s); i++){
		if(s[i] == 32 && s[i+1] == 32) 
			continue;		
		else 
		{
			if(s[i] != 32)
			{
				printf("%c", s[i]);
				logic = 1;
			}			
			else if(logic == 1) 
				break;
		}			
	}
	
	printf(" ");
	
	for(i = strlen(s)-1;; i--){
		if(s[i] == 32 && s[i-1] == 32) 
			continue;		
		else 
		{
			if(s[i] != 32)
			{	
				s2[j] = s[i];
				j++;
			}
			else if(j != 0)
				break;
		}			
	}
	
	strrev(s2);
	printf("%s", s2);
}
