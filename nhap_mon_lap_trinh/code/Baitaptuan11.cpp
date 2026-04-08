#include<stdio.h>
#include<string.h>
#define MAX 100

void nhap(char s[]);
void chuanHoa(char s[]);
void in(char s[]);
void kiemTraKyTu(char s[]);
void kiemTraChuoi(char s[]);
void ghepChuoi(char s[]);

int main(){
	char s[MAX];
	
	nhap(s);
	chuanHoa(s);
	in(s);
	kiemTraChuoi(s);
	kiemTraKyTu(s);
	ghepChuoi(s);
	in(s);
	
	return 1;
	
}

void nhap(char s[]){
	printf("Nhap ho va ten: ");
	gets(s);
}

void chuanHoa(char s[]){
	int i;
	
	while(s[0] == ' ') 
		strcpy(&s[0], &s[1]);
	while(s[strlen(s)-1 ] == ' ') 
		s[strlen(s)-1 ] = '\0';
		
	for(i = 0; i < strlen(s); i++)
		if(s[i] == ' ' && s[i+1] == ' '){
        	strcpy(&s[i], &s[i+1]);
			i--;
		}
}

void in(char s[]){
	printf("%s", s);
}

void kiemTraKyTu(char s[]){
  int i;
  char c;
  bool hasC = false;
  printf("\nNhap ky tu c: ");
  scanf("%c", &c);

  printf("Vi tri cua ky tu %c: \n", c);
  for(i = 0; i < strlen(s); i++)
    if(s[i] == c) 
    {
      hasC = true;
      printf("%d ", i);
    }    
  if(!hasC)
    printf("Khong co ky tu %c trong chuoi!", c);
}
void kiemTraChuoi(char s[]){
	char s1[MAX];

	printf("\nNhap chuoi con s1: ");
	fflush(stdin);
	gets(s1);
  	
	if(strstr(s,s1))
		printf("Co chuoi s1 trong chuoi s");
	else
		printf("Khong co chuoi s1 trong chuoi s");
}
void ghepChuoi(char s[]){
  char s2[MAX];

  printf("\nNhap chuoi con s2: ");
	fflush(stdin);
  gets(s2);

  strcat(s,s2);
}
