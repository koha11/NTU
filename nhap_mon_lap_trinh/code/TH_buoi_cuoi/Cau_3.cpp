#include<stdio.h>
#include<string.h>

void dem(char s[]);

int main(){
	char s[50];
	
	printf("Nhap: ");
	gets(s);
	dem(s);
}

void dem(char s[]){
	char na[] = {'e','u','a','o','i'};
	int c_na = 0, c_a = 0, c_o= 0, c_e = 0, c_u = 0, c_i = 0, i, j;
	
	for(i = 0; i < strlen(s); i++)
		for(j = 0; j < strlen(na); j++)
			if(s[i] == na[j] - 32 || s[i] == na[j])
			{
				c_na++;
				switch(j){
					case 0:
						c_e++;
						break;
					case 1:
						c_u++;
						break;
					case 2:
						c_a++;
						break;
					case 3:
						c_o++;
						break;
					case 4:
						c_i++;
				}
			}
			
	printf("\nTong so nguyen am co trong chuoi la: %d", c_na);
	printf("\nTrong do: ");
	printf("\nNguyen am a/A la: %d", c_a);
	printf("\nNguyen am e/E la: %d", c_e);
	printf("\nNguyen am i/I la: %d", c_i);
	printf("\nNguyen am o/O la: %d", c_o);
	printf("\nNguyen am u/U la: %d", c_u);



}

