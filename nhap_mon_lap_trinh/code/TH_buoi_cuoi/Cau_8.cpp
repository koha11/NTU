#include<stdio.h>
#include<string.h>

void catChuoi(char s[]);
int main(){
	char s[50];
	
	printf("Nhap: ");
	gets(s);
	catChuoi(s);
}
void catChuoi(char s[]){
	int a,b, count = 0, temp;
	
	printf("Vi tri cat chuoi la: ");
	scanf("%d", &a);
	temp = a;
	printf("Chieu dai can cat la: ");
	scanf("%d", &b);
	char s2[50];
	for(; count < b; count++)
	{
		s2[count] = s[a];
		a++;
	}
	s2[count] = '\0';
	printf("Chuoi con duoc sinh ra tu vi tri %d voi do dai %d ky tu cua chuoi ban dau la: %s", temp, b, s2);

}


