#include<iostream>
#define MAX 10000
using namespace std;

/* NHAP
	a = 12345;
	b =  4467;
	1:     '2
	2:    '12 
	3:    812   
	4:   6812
	5:  16812
	
	n = res_leng = max(a_leng,b_leng)
	soNho = (a[i] + b[i] + soNho) / 10
	
*/

int main(){
	int a[MAX],b[MAX],c[MAX];
	int a_leng,b_leng;
	
	cout << "a_leng = ";
	cin >> a_leng;
	cout << "b_leng = ";
	cin >> b_leng;
	
	//Set max de lay so da`i hon de do'ng le` ben phai?
	int max = a_leng > b_leng ? a_leng : b_leng;
	
	//input
	for(int i = max-a_leng+1; i <= max; i++) //index bat dau = 1, vi phai chua` 1 o cho so nho (neu 2 phan tu cuoi cung + lai co nho)
		cin >> a[i];
	for(int i = max-b_leng+1; i <= max; i++)
		cin >> b[i];
		
	int soNho = 0;
	for(int i = max; i > 0; i--)
	{
		c[i] = (a[i]+b[i]+soNho)%10;   //mod 10 tuc la se lay phan du, 3+6 = 9%10 = 9(ko du)|| 3+9=12%10=2 (nho 1);
		soNho = (a[i]+b[i]+soNho)/10; //cong lai lon hon 10 thi la` du 1			
	}
	c[0] = soNho;
	
	cout << "result = ";
	
	for(int i = 0; i <= max; i++)
	{
		if(c[i] == 0 && i == 0) //neu c[0] = 0 thi ko in
			continue;
		cout << c[i];
	}			
	
	return 0;
}

