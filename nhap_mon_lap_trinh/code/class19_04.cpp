#include<stdio.h>
#include<string.h>

void nhapChuoiChuan(char s[]){
  printf("Nhap chuoi chuan: ");
  gets(s);
}

void proper(char s[]){
  int i;
  for(i = 0; i < strlen(s); i++)
  {
    if(s[i-1] == ' ' || i == 0)
    {
      if(s[i] >= 97)
        s[i] = s[i] - 32;
    }
    else{
      if(s[i] < 97 && s[i] != 32)
        s[i] = s[i] + 32;
    }
  }
}

int dem(char s[]){
  int i, count = 0;
  for(i = 0; i < strlen(s); i++)
  {
    if(s[i] == 'n')
      count++;
  }

  return count;
}

void inChuoi(char s[]){
  int i;
  printf("\nChuoi da nhap la: %s", s);
}

int main(){
  char s[100];

  nhapChuoiChuan(s);
  inChuoi(s);
  printf("\nTrong chuoi co %d ky tu 'n' ", dem(s));
  proper(s);
  inChuoi(s);
}