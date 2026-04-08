#include<stdio.h>
#include<string.h>
#define MAX 30

void nhap(char s[]);
void chuanHoa(char s[]);
void in(char s[]);
int demTu(char s[]);
int demKyTuKhacNA(char s[]);
void inHoSV(char s[]);
void inTenSV(char s[]);
void inTuDaiNhat(char s[]);


int main(){
	char s[30];
	
	nhap(s);
	chuanHoa(s);
	in(s);
	printf("\nSo tu co trong chuoi: %d", demTu(s));
	printf("\nSo ky tu khong phai nguyen am: %d", demKyTuKhacNA(s));
	inHoSV(s);
	inTenSV(s);
	inTuDaiNhat(s);	
	
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

int demTu(char s[]){
	int i, count = 0;;
	
	for(i = 0; i < strlen(s); i++)
		if(s[i] != ' ')
			count++;
	
	return count;
}

int demKyTuKhacNA(char s[]){
	int i, j, count = 0;
	bool haveNA = true;
	char nguyen_am[] = "aeiou";
	
	for(i = 0; i < strlen(s); i++)
	{
		for(j = 0; j < strlen(nguyen_am); j++)
		{
			haveNA = true;
			if(s[i] == nguyen_am[j] || s[i] == nguyen_am[j]-32 || s[i] == ' '){
				haveNA = false;
				break;
			}	
		}		
		if(haveNA)		
			count++;	
	}
	
	return count;				
}

void inHoSV(char s[]){
	int i;
	
	printf("\nHo cua sinh vien la: ");
	for(i = 0; i < strlen(s); i++)
		if(s[i] != ' ')
			printf("%c", s[i]);
		else
			break;			
}

void inTenSV(char s[]){
	int i, j = 0;
	char s1[MAX] = "";
	printf("\nTen cua sinh vien la: ");
	for(i = strlen(s) - 1;; i--){
		if(s[i] != ' ')
		{			
			s1[j] = s[i];
			j++;
		}
		else
			break;
	}	
	printf("%s", strrev(s1));		
}

void inTuDaiNhat(char s[]){
	char s1[MAX], s2[MAX];
	int i, count = 0, index = 0, max_index, max = 0;
	
	for(i = 0; i <= strlen(s); i++){	
		if(s[i] != ' ' && s[i] != '\0'){
			count++;
		}
		else
		{
			if(max < count)
			{
				max = count;
				max_index = index;
			}			
			count = 0;
			index = i + 1;
		}
	}
	
	printf("\nTu dai nhat la: ");
	for(i = max_index; i < max+max_index; i++)
		printf("%c", s[i]);			
}





