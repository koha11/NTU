#include<iostream>
#include<cstdio>
using namespace std;

struct Node
{
	Node *next;
	int data;
};

void khoitao(Node *&first)
{
	first == NULL;		
}

void nhap(Node *&first)
{
	int temp;
	char c;
	Node *p, *q;
	do
	{
		cin >> temp;	
		p = new Node;
		p->data = temp;
		p->next = NULL;
		
		if(first == NULL)
			first = p;
		else
			q->next = p;	
		q = p;
		
		c = getchar();
		if(c == '\n')
			break;
	}
	while(1);
}

void xuat(Node *first)
{
	if(first != NULL)
	{
		cout << first->data << " ";
		xuat(first->next);
	}	
}

void chenTruoc(Node *&first)
{
	int x, y;
	Node *p = first, *q, *temp;	
	cin >> x >> y;
	
	do
	{
		if(p->data == y)
		{
			temp = new Node;
			temp->data = x;
			temp->next = p;
			
			if(p == first)
				first = temp;
			else
				q->next = temp;
			
			break;
		}
		else
		{
			q = p;
			p = p->next;
		}					
	}
	while(p != NULL);
	
	if(p == NULL)
		cout << "Khong co nut mang gia tri " << y << " trong ds!" << endl;
}

void sapXepTangDan(Node *first)
{		
	Node *p = first, *q;
	int temp;
	
	do
	{
		q = p->next;
		do
		{
			if(p->data > q->data)
			{
				temp = p->data;
				p->data = q->data;
				q->data = temp;
			}
			q = q->next;
		}
		while(q != NULL);
		p = p->next;
	}	
	while(p->next != NULL);
}

void trungNhau(Node *first)
{
	Node *p = first, *q;	
	
	do
	{		
		q = p->next;
		
		if(p->data == q->data)
		{
			p->next = q->next;
			delete q;
		}
	
		p = p->next;
	}	
	while(p->next != NULL);
}

void daoNguoc(Node *&first)
{
	Node *p, *q = NULL;
	
	while(first != NULL)
	{
		p = first;
		first = first->next;
		p->next = q;
		q = p;
	}
	
	first = p;
}

int main()
{
	Node *first;
	khoitao(first);
	nhap(first);
	xuat(first);
	cout << endl;	
	chenTruoc(first);	
	xuat(first);
	cout << endl;	
	sapXepTangDan(first);
	xuat(first);
	cout << endl;
	trungNhau(first);
	xuat(first);
	cout << endl;
	daoNguoc(first);
	xuat(first);
	cout << endl;

	return 0;
}

