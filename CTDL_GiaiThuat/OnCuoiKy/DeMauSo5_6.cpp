#include<iostream>
using namespace std;

struct Node
{
	string s;
	Node *prev;
	Node *next;
};

void nhap(Node *&head, Node *&tail)
{
	string s_t;
	Node *p, *q;
	do
	{		
		getline(cin,s_t);
		if(s_t != "0")
		{
			p = new Node;
			p->next = NULL;		
			p->s = s_t;
			if(head == NULL) 
			{
				head = p;
				p->prev = NULL;
			}
			else
			{
				q->next = p;
				p->prev = q;
			}			
			q = p;
		}
	}
	while(s_t != "0"); //sua lai thanh dung khi nhan enter
	
	tail = p;
}

void xuat(Node *head, Node *tail)
{
	if(head == tail->next)
	{
		cout << endl;
		return;
	}
		
	cout << head->s << endl;
	xuat(head->next,tail);
}

void xoa(Node *&head, Node *&tail, int i)
{
	Node *p = head;
	int count = 1;
	
	while(count != i)
	{
		count++;
		p = p->next;
	}
	
	if(p == head)
	{
		head = p->next;
		p->next->prev = NULL;
	}
	else if(p == tail)
	{
		p->prev = tail;
		p->prev->next = NULL;
	}		
	else
	{
		p->prev->next = p->next;
		p->next->prev = p->prev;
	}
			
	delete p;
}

void overwrite(Node *&dau, Node *&tail, int i, int j)
{
	int count = 1;
	Node *p, *q, *temp = dau;	
	while(count <= max(i,j))
	{
		if(count == i)
			p = temp;
		if(count == j)
			q = temp;
		count++;
		temp = temp->next;
	}
	
	p->s = q->s;
}

void themcuoi(Node *&tail)
{
	string s_t;
	getline(cin,s_t);
	Node *p = new Node;
	p->s = s_t;
	p->next = NULL;
	tail->next = p;
	p->prev = tail;
	tail = p;
}

int main()
{
	Node *head = NULL, *tail;
	nhap(head,tail);
	xuat(head,tail);
	xoa(head,tail,2);
	xuat(head,tail);
	overwrite(head,tail,2,4);
	xuat(head,tail);
	themcuoi(tail);
	xuat(head,tail);

	return 0;
}

