#include<stdio.h>
#include<string.h>

void kmer(char s[], int length);

int main(){
	char s[50];
	int length;
	
	printf("Nhap: ");
	scanf("%s", &s);
	printf("Nhap chieu dai: ");
	scanf("%d", &length);
	
	kmer(s,length);
}
void kmer(char s[], int length){
	int i, j, count = 0;
	for(i = 0; i <= strlen(s) - length; i++)
	{
		printf(" ");
		for(j = 0; j < length; j++)
		{
			printf("%c", s[count+j]);
		}
		count++;	
		printf("\n");
	}
}


