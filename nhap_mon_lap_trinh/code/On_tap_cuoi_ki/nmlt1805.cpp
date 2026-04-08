#include<stdio.h>
#include<string.h>
#define MAX 100

void nhapChuoi(char s[]);
void demKyTu(char s[]);
void thayTheKyTuNA(char s[]);
void tuDaiNhat(char s[]);
void daoNguocTu(char s[]);
int demTu(char s[], char s1[]);

int main(){
	char s[MAX];
	
	nhapChuoi(s);
	demKyTu(s);
	thayTheKyTuNA(s);
	printf("\n");
	nhapChuoi(s);
	tuDaiNhat(s);
	printf("\n");
	nhapChuoi(s);
	daoNguocTu(s);
}

void nhapChuoi(char s[]){
	printf("Nhap chuoi s: ");
	fflush(stdin);
	gets(s);
	printf("%s", s);
}
void demKyTu(char s[]){
	int i, count = 0;
	char x;
	printf("\nNhap x: ");
	scanf("%c", &x);
	
	for(i = 0; i < strlen(s); i++)
		if(x == s[i])
			count++;
			
	printf("Co %d ky tu %c trong chuoi s!", count, x);
}
void thayTheKyTuNA(char s[]){
	int i,j;
	char na[] = {'a','e','u','o','i'};
	
	for(i = 0; i < strlen(s); i++)
		for(j = 0; j < strlen(na); j++)
			if(s[i] == na[j] || s[i] == na[j] - 32)
			{
				s[i] = '*';
				break;
			}
	
	printf("\nChuoi sau khi thay the nguyen am: ");
	printf("\n%s", s);
}

int demTu(char s[], char s1[]){
	int i, count = 0, length = 0, index = 0;
	char s2[MAX];
	
	//Lap qua chuoi de tim tu trung nhau
	for(i = 0; i < strlen(s); i++)
	{	
		if(s[i] != ' ')
			length++;
		if(s[i] == ' ' || s[i+1] == '\0')
		{
			strncpy(s2,s + index,length); // trim tu trung voi s1 vao s2
			s2[length] = '\0';			
			if(strcmp(s1,s2) == 0) //Neu trung` nhau thi xoa tu do va` cong bien dem
			{
				count++;
				if(s[i+1]=='\0') // neu la` ptu cuoi cung phai tang i len de xoa ptu cuoi dc dung
					i++;					
				strcpy(&s[index-1],&s[i]); //XOA TU DA DEM
				i= i - length - 1; //Chinh lai gia tri i --> vi tri nay` la vi tri cua khoang trang trc khi sang tu moi
			}
			index = i+1; //index la diem bat dau cua tu tiep theo
			length = 0;
		}	
	}
	
	return count;				
}

void tuDaiNhat(char s[]){
	int maxLength = 0, i, j, length = 0, count;
	
	//Tim do dai tu lon nhat trong chuoi
	for(i = 0; i < strlen(s); i++)
	{	
		if(s[i] != ' ')
			length++;
		if(s[i] == ' ' || s[i+1] == '\0') // neu gap khoang trang hoac ptu ke tiep la '\0' thi` la da ket thuc 1 tu`
		{
			if(length > maxLength)
				maxLength = length;
			length = 0;
		}				
	}
	
	char s1[maxLength];
	
	//TIM TU DAI NHAT
	printf("\n");
	for(i = 0; i < strlen(s); i++)
	{ 			
		if(s[i] != ' ')
			length++;
		if(s[i] == ' ' || s[i+1] == '\0')
		{
			if(length == maxLength)
			{
				if(s[i+1] == '\0')
					i++;
				strncpy(s1,s + (i-length),length); //trim phan tu co do dai bang voi do dai lon nhat
				s1[length] = '\0'; //gan ky tu cuoi cung = '\0' de tranh loi
				count = demTu(s,s1); //tan suat cua tu vua tim dc, va xoa tu do ra khoi chuoi ban dau
				printf("%s %d ", s1, count);
				strcpy(s1," "); // reset s1
				i = i - length - 1; // Chinh lai gia tri i --> vi tri nay` la vi tri cua khoang trang trc khi sang tu moi
			}
			length = 0;
		}		
	}
	
	// tim do dai --> tim tu --> tim tu giong nhau --> tan suat
}

void daoNguocTu(char s[]){
	int i, length = 0;
	char s1[MAX];
	
	printf("\nChuoi sau khi dao nguoc: \n");
	for(i = strlen(s) - 1; i >=0; i--)
	{
		if(s[i] != ' ')
			length++;
		if(s[i] == ' ' || i == 0)
		{
			if(i == 0)
				i--;
			strncpy(s1,s+i+1,length);
			s1[length] = '\0';
			printf("%s ",s1);
			strcpy(s1, " ");
			length = 0;
		}			
	}
}
