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
	while(s_t != "0");
	
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

void xoa(Node *&head, Node *&tail, int i, int j)
{
	int count = 1;
	Node *p = head, *q;
	while(count != i)
	{
		count++;
		p = p->next;
	}
	
	do
	{
		q = p->next;
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
		
		p = q;
		count++;	
	}
	while(count != j);
}

int main()
{
	Node *head1 = NULL, *tail1 = NULL;
	
	nhap(head1,tail1);
	xuat(head1,tail1);
	themcuoi(tail1);
	xuat(head1,tail1);
	xoa(head1,tail1,1,3);
	xuat(head1,tail1);
	

	return 0;
}

