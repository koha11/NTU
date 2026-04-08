#include<stdio.h>
#include<string.h>
int isDoiXung(char s[]);
int main(){
	char s[50];
	
	printf("Nhap: ");
	gets(s);
	if(isDoiXung(s))
		printf("KQ: la chuoi doi xung");
	else
		printf("KQ: khong la chuoi doi xung");

}
int isDoiXung(char s[]){
	int i, j ;
	j = strlen(s) - 1;
	for(i = 0; i < strlen(s); i++)
	{
		if(s[i] != s[j])
			break;
		j--;
	}
	if(i > j)
		return 1;
	else
		return 0;		
}


