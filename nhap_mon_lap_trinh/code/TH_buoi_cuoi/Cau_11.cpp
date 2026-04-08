#include<stdio.h>
#include<string.h>
void demDNA(char s[]);
int main(){
	char s[50];
	
	printf("Nhap: ");
	scanf("%s", &s);
	demDNA(s);
}

void demDNA(char s[]){
	int i, a = 0, t = 0, g = 0, c = 0;
	
	for(i = 0; i < strlen(s), i++)
		switch(s[i]){
			case 'A':
				a++;
				break;
			case 'T':
				t++;
				break;
			case 'G':
				g++;
				break;
			case 'C':
				c++;
		}
	printf("Bazo    Tan So");
	printf("\nA    %d", a);
	printf("\nT    %d", t);
	printf("\nG    %d", g);
	printf("\nC    %d", c);
	printf("Phan tram (GC) la: ");

}


