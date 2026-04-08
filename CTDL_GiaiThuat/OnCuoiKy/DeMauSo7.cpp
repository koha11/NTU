#include<iostream>
using namespace std;

struct Node
{
	int data;
	Node *next;
};

void nhap(Node *&dau)
{
	int x;
	Node *p, *q;
	do
	{
		cin >> x;
		if(x != 0)
		{
			p = new Node;
			p->next = NULL;		
			p->data = x;
			if(dau == NULL) 
				dau = p;
			else
				q->next = p;
			
			q = p;
		}
	}
	while(x != 0);
}

void xuat(Node *dau)
{
	if(dau == NULL)
	{
		cout << endl;
		return;
	}
	
	cout << dau->data << " ";
	xuat(dau->next);
}

void sapXepTangDan(Node *&dau)
{
	Node *p = dau, *q;
	int temp;
	
	while(p->next != NULL)
	{
		q = p->next;
		while(q != NULL)
		{
			if(p->data > q->data)
			{
				temp = p->data;
				p->data = q->data;
				q->data = temp;
			}
			q = q->next;
		}
		p = p->next;
	}
}

void loaiBoNutTrung(Node *dau)
{
	Node *p = dau;
	while(p->next != NULL)
	{
		if(p->data == p->next->data)
		{
			Node *temp = p->next->next;
			delete p->next;
			p->next = temp;
		}
		else
			p = p->next;
	}
}

int main()
{
	Node *dau = NULL;
	nhap(dau);
	xuat(dau);
	sapXepTangDan(dau);
	xuat(dau);
	loaiBoNutTrung(dau);
	xuat(dau);
	return 0;
}

