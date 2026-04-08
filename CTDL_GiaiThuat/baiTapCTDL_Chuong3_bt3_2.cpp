#include<iostream>
using namespace std;

struct nut
{
	int data;
	nut *next;
};

struct nut typedef  Node;

struct List
{
	Node *first;
	Node *tail;
};

void init(List &l1);
void input(List &l1);
void output(List l1);
void hookList(List &l1, List l2);
void insertX(List &l1, int x);
List mergeList_1(List l1, List l2);
void uniqueDataList(List &l1);
void countAppearOfDatas(List l1);


int main()
{
	List l1, l2, l3;
	int x;

	init(l1);
	input(l1);
	output(l1);
	
	init(l2);
	input(l2);
	hookList(l1,l2);
	output(l1);
	
	cout << "x = ";
	cin >> x;
	insertX(l1,x);
	output(l1);
	
	init(l1);
	input(l1);
	output(mergeList_1(l1,l2));
	
	uniqueDataList(l1);
	output(l1);
	
	countAppearOfDatas(l1);
	
	
	return 0;
}

void init(List &l1)
{
	l1.first = NULL;
	l1.tail = NULL;
}

void input(List &l1)
{
	Node *p, *q;
	do
	{
		p = new Node;
		cin >> p->data;
					
		if(p->data != 0)
		{
			p->next = NULL;
			if(l1.first == NULL)
				l1.first = p;
			else
				q->next = p;
			q = p;
		}		
	}	
	while(p->data != 0);
	
	l1.tail = q;
}

void output(List l1)
{
	Node *p = l1.first;
	
	do
	{
		cout << p->data << " ";
		p = p->next;
	}
	while(p != NULL);
	
	cout << endl;
}

void hookList(List &l1, List l2)
{
	l1.tail->next = l2.first;
	l1.tail = l2.tail;
}

void insertX(List &l1, int x)
{
	Node *p = l1.first;
	Node *q = p;
	do
	{
		if(p == NULL || x < p->data)
		{	
			p = new Node;
			
			p->data = x;
							
			if(q == l1.first) //Neu x be nhat
			{
				l1.first = p;
				p->next = q;		
			}
			else
			{
				p->next = q->next;
				q->next = p;
			}							
				
			if(p->next == NULL)
				l1.tail = p;
				
			return;
		}
		else // neu x van lon hon hoac chua o cuoi thi lap tiep
		{
			q = p;
			p = p->next;
		}
	}
	while(1);
}

List mergeList_1(List l1, List l2)
{
	Node *p = l1.first, *q = l2.first, *p_temp, *q_temp;
	
	List l3;
	init(l3);
		
	do
	{
		p_temp = new Node;
		
		if(p == NULL || (q != NULL && p->data > q->data)) //nhap gia tri cua l2 vo l3
		{
			p_temp->data = q->data;
			q = q->next;
		}		
		else
		{
			p_temp->data = p->data; //nhap gia tri cua l1 vo l3
			p = p->next;
		}
		
		p_temp->next = NULL;
			
		if(l3.first == NULL)
			l3.first = p_temp;
		else
			q_temp->next = p_temp;
		
		q_temp = p_temp;
	}
	while(p != NULL || q != NULL); // Khi p va q cung` ko ton tai thi ngung

	l3.tail = p_temp;	
	
	return l3;
}

void uniqueDataList(List &l1)
{
	Node *p = l1.first, *q, *temp;
	
	while(p->next != NULL)
	{
		q = p->next;
		temp = p; // node truoc q
		while(q != NULL)
		{
			if(p->data == q->data) //kiem tra xem no bang
			{
				cout << p->data << " " << temp->data << endl;
				temp->next = q->next;
				delete q; // neu bang thi xoa
			}
			temp = q;
			q = q->next;
		}
		p = p->next;
	}
	
	l1.tail = temp;
}

//b1: ktra xem so do da co chua
//b2: dem
void countAppearOfDatas(List l1)
{
	Node *p = l1.first, *q, *p_t, *q_t;
	int count = 1;
	List l_t;
	
	init(l_t);

	
	while(p != NULL)
	{
		p_t = l_t.first;
		while(p_t != NULL) //duyet qua xem thu da xuat hien chua
		{
			if(p->data == p_t->data)
				break;
			p_t = p_t->next;
		}
		
		if(p_t == NULL) //chua thi xu ly 
		{
			p_t = new Node;
			p_t->data = p->data;
			p_t->next = NULL;
			
			if(l_t.first == NULL)
				l_t.first = p_t;
			else
				q_t->next = p_t;
				
			q_t = p_t;
			
			q = p->next;
			while(q != NULL) //bat dau dem
			{
				if(p->data == q->data)
					count++;
				q = q->next;
			}
			cout << p->data << ": " << count << endl; //in ra mh so luong cua 1 so
			count = 1;
		}		
		p = p->next;		
	}
}

