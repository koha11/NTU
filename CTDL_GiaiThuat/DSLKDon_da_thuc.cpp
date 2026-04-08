#include<iostream>
using namespace std

struct DonThuc
{
	int x;
	int n;
	DonThuc *next;
};

struct DaThuc
{
	DonThuc *first;
	DonThuc *tail;
};

void init(DaThuc &fx);
void input(DaThuc &fx);
void output(DaThuc fx);
void sortN(DaThuc &fx);
void rutGon(DaThuc &fx);
DaThuc tong(DaThuc fx1, DaThuc fx2);
DaThuc daoHam(DaThuc fx);

int main()
{
	DaThuc fx1, fx2;
	
	init(fx1);
	input(fx1);
	output(fx1);
	
	init(fx2);
	input(fx2);
	output(fx2);

	output(tong(fx1,fx2));
	output(daoHam(fx1));

	return 0;
}

void init(DaThuc &fx)
{
	fx.first = NULL;
	fx.tail = NULL;
}

void input(DaThuc &fx)
{
	DonThuc *p, *q;
	
	do
	{
		p = new DonThuc;
		cout << "Nhap don thuc: ";
		cin >> p->x;
		cin >> p->n;	
		
		if(p->x != 0)
		{
			p->next = NULL;
			if(fx.first == NULL)
				fx.first = p;
			else
				q->next = p;			
			q = p;
			fx.tail = p;
		}
	}	
	while(p->x != 0);
}

void output(DaThuc fx)
{
	DonThuc *p = fx.first;
	while(p != NULL)
	{
		if(p->x > 0)
			cout << "+" << p->x << "x^" << p->n << " ";
		else
			cout << p->x << "x^" << p->n << " ";
		
		p = p->next;
	}
	cout << endl;
}

void sortN(DaThuc &fx)
{
	DonThuc *p = fx.first, *q;
	int temp;
	
	while(p->next != NULL)
	{
		q = p->next;
		while(q != NULL)
		{
			if(p->n < q->n)
			{
				temp = p->n;
				p->n = q->n;
				q->n = temp;
				
				temp = p->x;
				p->x = q->x;
				q->x = temp;
			}
			q = q->next;
		}
		p = p->next;
	}
}

void rutGon(DaThuc &fx)
{
	DonThuc *p = fx.first, *q;
	int temp;
	
	while(p->next != NULL)
	{
		q = p->next;
		if(p->n == q->n)
		{
			p->x += q->x;			
			p->next = q->next;
			delete q;
		}
		else
			p = p->next;
	}
}


// c1: sort 2 da thuc theo n -> so sanh va cong
// c2: so sanh tung cai cua fx1 voi fx2, bang n thi cong roi add vo fx3 (interchange)
DaThuc tong(DaThuc fx1, DaThuc fx2)
{
	DaThuc fx3;
	DonThuc *p = fx1.first, *q = fx2.first, *p_t, *q_t;
	int logic;
	
	init(fx3);
	
	//Sort theo mu n
	sortN(fx1);
	cout << "sort" << endl;
	output(fx1);
	sortN(fx2);
	output(fx2);
	//T/hop chua rut gon
	rutGon(fx1);
	cout << "RG" << endl;
	output(fx1);
	rutGon(fx2);
	output(fx2);


	
	//Bat dau xu li de them vao da thuc moi
	
	do
	{
		p_t = new DonThuc; //cap dia chi cho p_t
		p_t->next = NULL;
		
		if(p == NULL) //neu p = NULL -> chuyen q vo fx3
		{
			p_t->n = q->n;
			p_t->x = q->x;
			q = q->next;
		}
		if(q == NULL) //neu q = NULL -> chuyen p vo fx3
		{
			p_t->n = p->n;
			p_t->x = p->x;
			p = p->next;
		}
		else 
		{
			logic = p->n > q->n;
			p_t->n = logic == 1 ? p->n : q->n; //kco cai nao` NULL thi so sanh mu n
			
			if(p->n == q->n) //mu bang nhau thi cong he so lai roi tang p,q
			{
				p_t->x = p->x + q->x;
				p = p->next;
				q = q->next;
			}
			else 
			{
				p_t->x = logic == 1 ? p->x : q->x; //mu nao` lon hon thi bang he so cua mu do
			
				if(logic) //mu nao` cao hon thi them vao fx3 truoc
					p = p->next;
				else
					q = q->next;
			}
		}		
		
		if(fx3.first == NULL)
			fx3.first = p_t;
		else
			q_t->next = p_t;
			
		q_t = p_t;
	}
	while(p != NULL || q != NULL);	
	
	return fx3;
}

DaThuc daoHam(DaThuc fx)
{
	DonThuc *p = fx.first;
	
	while(p != NULL)
	{
		if(p->n == 0)
		{
			p = NULL;
			break;
		}
		else
		{
			p->x *= p->n;
			p->n--;
		}
									
		p = p->next;
	}
	
	return fx;
}

