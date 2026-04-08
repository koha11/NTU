#include<iostream>
#include<math.h>
using namespace std;

struct NODE
{
	int data;
	NODE *next;
};

struct LIST
{
	NODE *first;
	NODE *tail;
};

void input(LIST &ds);
void output(LIST ds);
int sum(NODE *p);
void countOddOrEven(LIST ds);
int isPrime(int x);
int maxPrime(LIST ds);
void newPrimeList(LIST ds1, LIST &ds2);
void ordinalNumbers(LIST ds);
void deleteNode(LIST &ds);
int findSquareNum(int x);
void insertAferPrime(LIST &ds);
	
int main()
{
	LIST ds1, ds2;
	ds1.first = NULL;
	
	input(ds1);
	output(ds1);
	
	cout << "SUM = " << sum(ds1.first) << endl;
	
	countOddOrEven(ds1);
	
	if(maxPrime(ds1) != 0)
        cout << "MAX PRIME = " << maxPrime(ds1) << endl;
	else 
		cout << "No Prime in this list" << endl;	
	
	if(maxPrime(ds1) != 0)
    {
    	newPrimeList(ds1,ds2);
    	output(ds2);
	}
	else 
		cout << "No Prime in this list" << endl;	
			
	ordinalNumbers(ds1);
	
	deleteNode(ds1);
	output(ds1);
	
	insertAferPrime(ds1);
	output(ds1);
	
	return 0;
}

void input(LIST &ds)
{
	NODE *p, *q;	
	
	do
	{
		p = new NODE;
		
		cin >> p->data;
		
		if(p->data != 0)
		{
			if(ds.first == NULL)
				ds.first = p;
			else
				q->next = p;			
			q = p;
		
			ds.tail = p;
			p->next = NULL;
		}
	}
	while(p->data != 0);
}

void output(LIST ds)
{
	NODE *p; 
	p = ds.first;

	do
	{
		cout << p->data << " ";	 
		p = p->next;
	}
	while(p != NULL);
	cout << endl;
}

int sum(NODE *p)
{
	if(p->next == NULL)
		return 0;
	return p->data + sum(p->next);
}

void countOddOrEven(LIST ds)
{
	NODE *p; 
	p = ds.first;
	int evenCount = 0, oddCount = 0;
	do
	{
		if(p->data % 2 == 0)
			evenCount++;
		else
			oddCount++;
			
		p = p->next;
	}
	while(p != NULL);
	
	cout << "EVEN = " << evenCount << endl;
	cout << "ODD = " << oddCount << endl;
}

int isPrime(int x){ 
	if(x <=1)
		return 0;
		
	for(int i = 2; i <= sqrt(x); i++)
		if(x%i== 0)
   			return 0;
   			
	return 1;
}
int maxPrime(LIST ds)
{
    NODE *p;
	p = ds.first;
	int max = 0;
	do
	{	
		if(isPrime(p->data) && p->data > max)
  			max = p->data;
		p=p->next;
	}
	while(p!=NULL);
	
	return max;
}
void newPrimeList(LIST ds1, LIST &ds2)
{
    NODE *p, *q, *temp;
	p = ds1.first;
	ds2.first = NULL;

	do
	{
		if(isPrime(p->data))
 		{
 			q = new NODE;
			q->data = p->data; 
			
			if(ds2.first == NULL)
   				ds2.first = q;
			else
  				temp->next = q;
  				
			temp = q;
			q->next = NULL;
			ds2.tail = q;
		}
		
		p=p->next;
	}
	while(p!=NULL);
}

void ordinalNumbers(LIST ds)
{
	NODE *p, *q;
	p = ds.first;
	cout << "Ordinal numbers: " << endl;
	do
	{	q = p->next;
		if(p->data < q->data)
  			cout << p->data << " ";
  		else
  			cout << p->data << " " << endl;
 		
		if(q->next == NULL) 			
			cout << q->data;  		
  				
		p=p->next;
	}
	while(p->next!=NULL);
}

void deleteNode(LIST &ds)
{
	NODE *p, *q;
	int x;
	p = ds.first;
	cout << endl << "Delete ";
	cin >> x;
	do	
	{	
		if(p->data == x)
		{
			if(p == ds.first)
				ds.first = p->next;
			else if(p == ds.tail)
			{
				q->next = NULL;
				ds.tail = q;
			}
			else
				q->next = p->next;		
				
			delete p;	
		}
		else
			q = p;
			
		p = p->next;
	}
	while(p!=NULL);
}

int findSquareNum(int x)
{
	int temp;
	
	do
	{
		temp = sqrt(x);
		if(temp*temp == x)
			return x;
		x++;
	}
	while(1);
}

void insertAferPrime(LIST &ds)
{
	NODE *p, *q;
	p = ds.first;

	do
	{
		if(isPrime(p->data))
		{
			q = new NODE;
			q->data = findSquareNum(p->data);
			q->next = p->next;
			p->next = q;		
		}
		
		p=p->next;
	}
	while(p!=NULL);
}


