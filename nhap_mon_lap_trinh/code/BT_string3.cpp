#include<stdio.h>
#include<string.h>

int main(){
	char s[50];
	int count = 0, i = 0, j;
	bool logic;
	char nguyen_am[] = "aeiou";
	
	do{
		printf("Nhap chuoi chuan: ");
		gets(s);
	
		for(j = 0; j < strlen(s); j++)
			logic = false;
			if(s[j] == ' ' && s[j+1] == ' '){
        		logic = true;
        		break;
			}
	}
	while(s[0] == ' ' || s[strlen(s)-1] == ' ' || logic);
	
	while (s[i]!='\0')
	{
		for(j=0; j<strlen(nguyen_am); j++)
		{
			if (s[i] == nguyen_am[j] || s[i]+32 == nguyen_am[j]) 
				count++;
		}
		i++;
	}
	
	printf("So luong ky tu nguyen am la: %d", count);

		
}
