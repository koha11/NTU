#include<iostream>
#include<string.h>
using namespace std;

struct SV
{
	char mssv[9];
	char hoVaTen[30];
	char lop[10];
	float dtk;
	char hanhKiem[11];
};

struct Node
{
	SV sv;
	Node *next;	
};

Node *dau;

void init(Node *&dau)
{
	dau = NULL;
}

void nhap(Node *&dau)
{
	Node *p, *q;
	int n;
	
	cout << "n = ";
	cin >> n;
	
	for(int i = 0; i < n; i++)
	{	
		p = new Node;
			
		cout << "mssv = ";		
		fflush(stdin);
		gets(p->sv.mssv);
		
		cout << "Ho va ten = ";
		fflush(stdin);
		gets(p->sv.hoVaTen);
		
		cout << "Lop = ";
		fflush(stdin);
		gets(p->sv.lop);
		
		cout << "Diem tong ket = ";
		fflush(stdin);
		cin >> p->sv.dtk;
		
		cout << "Hanh Kiem = ";
		fflush(stdin);
		gets(p->sv.hanhKiem);		
		
		if(dau == NULL)
			dau = p;
		else
			q->next = p;
			
		q = p;		
	}	
}

void xuat(Node *dau)
{
	Node *p = dau;
	
	if(p != NULL)
	{
		cout << p->sv.mssv << " " << p->sv.hoVaTen << " " << p->sv.lop << " " << p->sv.dtk << " " << p->sv.hanhKiem << endl;	
		xuat(p->next);
	}
}

bool kiemTraRong(Node *dau)
{
	if(dau == NULL)
		return 1;
	else
		return 0;
}

void them(Node *&dau)
{
	Node *p, *q;
	int option;
	
	cout << "1. Them sinh vien vao dau DS" << endl;
	cout << "2. Them sinh vien vao cuoi DS" << endl;
	cin >> option;
	
	switch(option)
	{
		case 1:
		{
			p = new Node;
			
			cout << "mssv = ";		
			fflush(stdin);
			gets(p->sv.mssv);
		
			cout << "Ho va ten = ";
			fflush(stdin);
			gets(p->sv.hoVaTen);
		
			cout << "Lop = ";
			fflush(stdin);
			gets(p->sv.lop);
		
			cout << "Diem tong ket = ";
			fflush(stdin);
			cin >> p->sv.dtk;
		
			cout << "Hanh Kiem = ";
			fflush(stdin);
			gets(p->sv.hanhKiem);
			
			q = dau;
			dau = p;
			dau->next = q;		
		}
			break;
		case 2:
		{
			p = dau;
			while(p->next != NULL)
				p = p->next;
			
			q = p;
			p = new Node;
			
			cout << "mssv = ";		
			fflush(stdin);
			gets(p->sv.mssv);
		
			cout << "Ho va ten = ";
			fflush(stdin);
			gets(p->sv.hoVaTen);
		
			cout << "Lop = ";
			fflush(stdin);
			gets(p->sv.lop);
		
			cout << "Diem tong ket = ";
			fflush(stdin);
			cin >> p->sv.dtk;
		
			cout << "Hanh Kiem = ";
			fflush(stdin);
			gets(p->sv.hanhKiem);
			
			q->next = p;
			p->next = NULL;
		}			
	}
}

void tim(Node *dau)
{
	Node *p, *q;
	int option;
	char x[30];
	
	cout << "Tim dua tren: " << endl;
	cout << "1. MSSV" << endl;
	cout << "2. TEN" << endl;
	cout << "3. LOP" << endl;
	cin >> option;
	
	cout << "u want find: ";
	fflush(stdin);
	gets(x);
	
	p = dau;
	
	cout << x << endl;
	switch(option)
	{
		case 1:			
			while(!(strcmp(p->sv.mssv,x) == 0) && p != NULL)
				p = p->next;
			
			if(p == NULL)
				cout << "Ko co MSSV nay trong danh sach" << endl;
			else
				cout << p->sv.mssv << " " << p->sv.hoVaTen << " " << p->sv.lop << " " << p->sv.dtk << " " << p->sv.hanhKiem << endl;					
				
			break;		
		case 2:
			while(!(strcmp(p->sv.hoVaTen,x) == 0) && p != NULL)
				p = p->next;
			
			if(p == NULL)
				cout << "Ko co ten SV nay trong danh sach" << endl;
			else
				cout << p->sv.mssv << " " << p->sv.hoVaTen << " " << p->sv.lop << " " << p->sv.dtk << " " << p->sv.hanhKiem << endl;					
				
			break;	
		case 3:
			while(!(strcmp(p->sv.lop,x) == 0) && p != NULL)
				p = p->next;
			
			if(p == NULL)
				cout << "Ko co SV thuoc lop nay trong danh sach" << endl;
			else
				cout << p->sv.mssv << " " << p->sv.hoVaTen << " " << p->sv.lop << " " << p->sv.dtk << " " << p->sv.hanhKiem << endl;				
	}
}

void xoaSvCuoi(Node *dau)
{
	Node *p = dau, *q;
	
	while(p->next->next != NULL)
		p = p->next;
	
	q = p->next;
	p->next = NULL;
	
	delete q;	
}

int main()
{
	init(dau);
	nhap(dau);
	cout << "Cac hoc sinh co ten trong danh sach la: " << endl;
	xuat(dau);
	them(dau);
	xuat(dau);
	tim(dau);
	tim(dau);
	tim(dau);
	xoaSvCuoi(dau);
	xuat(dau);

	
	return 0;
}

