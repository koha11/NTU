#include<stdio.h>
#include<string.h>
void tuDaiNhat(char s[]);
int main(){
	char s[50];
	
	printf("Nhap: ");
	gets(s);
	tuDaiNhat(s);
}
void tuDaiNhat(char s[]){
	int max = 0,max_index = 0, temp, i;
	
	for(i = 0; i < strlen(s); i++){
		if(s[i-1] == ' ' && s[i] != ' ')
			temp = i;			
		else if(i == 0)
			temp = i;
		else if((s[i] == ' ' && s[i-1] != ' ') || s[i+1] == '\0')
		{
			int count = i - temp;
			if(count > max)
			{
				max = count;
				max_index = temp;
				printf("%d\n", max);
				printf("%d\n", max_index);
			}
				
		}				
	}
	
	printf("Tu dai nhat la: ");
	for(i = max_index; i < max_index+max; i++)
		printf("%c", s[i]);
	printf(", co %d ky tu", max);
}


