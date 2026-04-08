#include<iostream>
#include<math.h>
using namespace std;

struct Node
{
	int a;
	int b;
	Node *next;
};

void nhap(Node *&dau)
{
	int a_t,b_t;
	Node *p, *q;
	do
	{
		cin >> a_t >> b_t;
		if(a_t != 0)
		{
			p = new Node;
			p->next = NULL;
			p->a = a_t;
			p->b = b_t;
			if(dau == NULL) 
				dau = p;
			else
				q->next = p;
			
			q = p;
		}
	}
	while(a_t != 0);
}

void xuat(Node *dau)
{
	if(dau == NULL)
	{
		cout << endl;
		return;
	}
	
	if(dau->a > 0)
		cout << "+";
	
	cout << dau->a << "x^" << dau->b;
	xuat(dau->next);
}

float giatri(Node *dau, float x)
{
	if(dau == NULL)
		return 0;
	else
		return dau->a * pow(x,dau->b) + giatri(dau->next,x);
}

void daoHam(Node *&dau)
{
	if(dau == NULL)
		return;
	if(dau->next != NULL && dau->next->b == 0)
	{
		Node *temp = dau->next->next;
		delete dau->next;
		dau->next = temp;
	}
	dau->a = dau->a * dau->b;
	dau->b = dau->b - 1;
	daoHam(dau->next);
}

void congDaThuc(Node *dau1, Node *dau2, Node *&res, Node *lastRes)
{
	Node *p;
	if(dau1 == NULL && dau2 == NULL)
		return;
	if(dau1 != NULL && (dau2 == NULL || dau1->b > dau2->b))
	{
		p = dau1;
		if(res == NULL)
			res = p;
		else
			lastRes->next = p;						
		congDaThuc(dau1->next,dau2,res,p);
	}
	else if(dau2 != NULL && (dau1 == NULL || dau1->b < dau2->b))
	{
		p = dau2;
		if(res == NULL)
			res = p;
		else
			lastRes->next = p;						
		congDaThuc(dau1,dau2->next,res,p);
	}
	else
	{
		p = new Node;
		p->a = dau1->a+dau2->a;
		p->b = dau1->b;
		if(res == NULL)
			res = p;
		else
			lastRes->next = p;						
		congDaThuc(dau1->next,dau2->next,res,p);		
	}
}

int main()
{
	Node *dau1 = NULL, *dau2 = NULL, *res = NULL;
	nhap(dau1);
	xuat(dau1);
	cout << giatri(dau1,2) << endl;
	daoHam(dau1);
	xuat(dau1);
	nhap(dau2);
	xuat(dau2);
	congDaThuc(dau1,dau2,res,0);
	xuat(res);

	return 0;
}

