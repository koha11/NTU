#include<iostream>
using namespace std;

struct nut               //B1: Khai bao cau truc nut
{
	int gtri;
	nut *tiep;
};

typedef nut Node; //Dat ten lai struct nut == Node


void khoitao(Node *&dau)  //B3: Khoi tao danh sach
{
	dau = NULL;
}

//Tao 1 dslk chua cac gtri nhap tu ban phim, ket thuc go 0

void taods(Node *&dau)
{
	int tam;
	Node *p, *q;
	p = NULL; q = NULL;
	do
	{
		cout << "Nhap 1 so nguyen, 0 de dung : ";
		cin >> tam;
		if(tam != 0)	
		{
			p = new Node; //CAP PHAT DIA CHI CHO P, dia chi nay chua kieu du lieu Node
			p->gtri = tam; //GAN GIA TRI CHO P
			p->tiep = NULL; // DIA CHI TIEP THEO LA NULL (CHUA CO)
			//MOC NUT VAO DS
			if(dau == NULL) //NEU LA PTU DAU THI GAN DAU = P
				dau = p;
			else
				q->tiep = p; //KO THI MOC NOI VOI PTU TRC NO ( = Q)
				
			q = p; //SAO CHEO DIA CHI CUA PTU HIEN TAI DE MOC NOI CHO PTU TIEP THEO
		}
	}
	while(tam != 0);
}

void duyetds(Node *dau) //duyet ds = de quy
{
	if(dau != NULL)
	{
		cout << dau->gtri << " ";
		duyetds(dau->tiep);
	}
	else
		cout << endl;
}

int sumNode(Node *dau) // de quy
{
	if(dau != NULL)
		return dau->gtri + sumNode(dau->tiep);
	else
		return 0;
}

int tongLe(Node *dau) // de quy
{
	if(dau != NULL)
		if(dau->gtri % 2 != 0)
			return dau->gtri + tongLe(dau->tiep);
		else
			return tongLe(dau->tiep);
	else
		return 0;
}

Node *lastNode(Node *dau)
{
	if(dau == NULL)
		return NULL;
	else
		if(dau->tiep != NULL)
			return lastNode(dau->tiep);
		else
			return dau;
}

void inPtuCuoiCung(Node *dau)
{
	if(dau == NULL)
		cout << "Danh sach ko co phan tu nao!" << endl;
	else
		if(dau->tiep != NULL)
			inPtuCuoiCung(dau->tiep);
		else
			cout << "Phan tu cuoi = " << dau->gtri << endl;;			
}

void inPtuKeCuoi(Node *dau)
{
	Node *p = dau;
	if(dau != NULL)
	{
		if(dau->tiep == NULL)
			cout << "danh sach ko co ptu ke cuoi" << endl;
		else	
		{
			while(p->tiep->tiep != NULL)
				p = p->tiep;
			
			cout << "Phan tu ke cuoi = " << p->gtri << endl;
		}	
	}
	else
		cout << "Danh sach ko co phan tu nao!" << endl;
}

void inRaGiaTriThu3(Node *dau)
{
	Node *p = dau;
	int count = 1;
	
	if(dau != NULL)
	{
		while(count != 3)
		{
			p= p->tiep;
			count++;
		}
	
		cout << "Phan tu thu 3: " << p->gtri << endl;
	}
}

Node *findNode(Node *dau, int x)
{ 
	Node *p;
	p=dau;
	while ((p!=NULL) && (p->gtri!=x))
		p=p->tiep;
	return p; 
}

void insertNode(Node *&dau)
{
	Node *p = dau, *q = p;
	int choice, temp, x;
	cout << "1. Chen vao dau DS" << endl;
	cout << "2. Chen vao cuoi DS" << endl;
	cout << "3. Chen vao sau x" << endl;
	cout << "4. Chen vao truoc x" << endl;
	cin >> choice;
	cout << "value = ";
	cin >> temp;
	switch(choice)
	{
		case 1:			
			p = new Node;
			p->gtri = temp;
			p->tiep = q;
			dau = p;			
			break;
		case 2:			
			p = new Node;
			p->gtri = temp;
			p->tiep = NULL;
			if(dau == NULL)
				dau = p;
			else
			{
				while(q->tiep != NULL)
					q = q->tiep;
					
				q->tiep = p;
			}	
			break;
		case 3:
			cout << "x = ";
			cin >> x;
			while(q != NULL && q->gtri != x)
				q = q->tiep;
			if(q == NULL)
				cout << "Khong co Node " << x << " trong DS" << endl;
			else
			{
				p = new Node;
				p->gtri = temp;
				p->tiep = q->tiep;
				q->tiep = p;
			}
			break;	
		case 4:
			cout << "x = ";
			cin >> x;		
			while(p != NULL && p->gtri != x)
			{				
				q = p;
				p = p->tiep;
			}
			if(p == NULL)
				cout << "Khong co Node " << x << " trong DS" << endl;
			else
			{
				p = new Node;
				p->gtri = temp;
			
				if(q == dau)
				{
					p->tiep = q;
					dau = p;
				}
				else
				{
					p->tiep = q->tiep;
					q->tiep = p;
				}					
			}
	}	
}

void deleteNode(Node *&dau)
{
	Node *p = dau, *q = p;
	int x, choice;
	cout << "1. Xoa node dau DS" << endl;
	cout << "2. Xoa node cuoi DS" << endl;
	cout << "3. Xoa node x bat ky" << endl;
	cout << "4. Xoa node sau x bat ky" << endl;
	cout << "5. Xoa node  x bat ky" << endl;
	cin >> choice;

	
	if(dau == NULL)
	{
		cout << "DS khong co phan tu nao" << endl;
		return;
	}
	
	switch(choice)
	{
		case 1:
			dau = p->tiep;
			delete p;
			break;
		case 2:
			while(p != NULL && p->tiep != NULL)
			{
				q = p;
				p = p->tiep;
			}
			if(p == dau)
				dau = p->tiep;
			else 
				q->tiep = NULL;
			delete p;
			break;			
		case 3: 
			cout << "x = ";
			cin >> x;
			while(p != NULL && p->gtri != x)
			{
				q = p;
				p = p->tiep;
			}
				
			if(p == NULL)
				cout << "Khong co Node " << x << " trong DS" << endl;
			if(p == dau)
			{
				dau = p->tiep;
				delete p;
			}		
			else
			{
				q->tiep = p->tiep;
				delete p;
			}	
			break;
		case 4:
			break;
		case 5:
			break;
	}
}

void bubbleSort(Node *&dau)
{
	Node *p = dau, *q;
	int temp;
	
	while(p->tiep != NULL)
	{
		q = p->tiep;
		while(q != NULL)
		{		
			if(p->gtri > q->gtri)
			{
				temp = p->gtri;
				p->gtri = q->gtri;
				q->gtri = temp;
			}
			q = q->tiep;
		}
		p = p->tiep;
	}
}

void reverseNode(Node *&dau)
{
	Node *p, *q = NULL;
	
	while(dau != NULL)
	{
		p = dau;
		dau = dau->tiep;
		p->tiep = q;
		q = p;
	}
	
	dau = p;
}

Node *mergeList(Node *dau1, Node *dau2)
{
	Node *p = dau1, *q = dau2, *temp_p, *temp_q;
	Node *result = NULL;
	if(p == NULL || q == NULL)
		result = (p == NULL) ? q : p;
	
	while(p != NULL && q != NULL)
	{			
		if(p->gtri < q->gtri)
		{	
			temp_p = p;
			p = p->tiep;
		}
		else
		{
			temp_p = q;
			q = q->tiep;
		}
		
		if(result == NULL)
			result = temp_p;
		else
			temp_q->tiep = temp_p;
				
		temp_q = temp_p;
	}
	
	while(p != NULL)
	{
		temp_p = p;
		p = p->tiep;
		temp_q->tiep = temp_p;
		temp_q = temp_p;
	}
	
	while(q != NULL)
	{
		temp_p = q;
		q = q->tiep;	
		temp_q->tiep = temp_p;
		temp_q = temp_p;
	}
			
	return result;	
}

void deleteMultiNumber(Node *dau)
{
	Node *p = dau,*q, *temp;
	
	while(p->tiep != NULL)
	{
		q = p->tiep;
		temp = p;
		while(q != NULL)
		{
			if(p->gtri == q->gtri)
			{
				temp->tiep = q->tiep;
				delete q;
				q = temp->tiep;				
			}
			else
			{
				temp = q;
				q = q->tiep;
			}			
		}
		p = p->tiep;
	}	
}

int main(){
	Node *dau, *dau1;  //B2: Khai bao bien con tro chua d/c nut dau ds
	khoitao(dau);
	taods(dau);
	duyetds(dau);
	khoitao(dau1);
	taods(dau1);
	duyetds(dau1);
//	cout << "sum = " << sumNode(dau) << endl;	
//	cout << "sum le = " << tongLe(dau) << endl;	
//	if(lastNode(dau)) //lastNode de quy
//		cout << "Last Node = " << lastNode(dau)->gtri << endl;
//	else
//		cout << "Danh sach khong co phan tu nao" << endl;
//	inPtuKeCuoi(dau);
//	inRaGiaTriThu3(dau);
//	insertNode(dau);
//	duyetds(dau);
//	insertNode(dau);
//	duyetds(dau);
//	deleteNode(dau);
//	duyetds(dau);	
//	bubbleSort(dau);
//	duyetds(dau);
//	reverseNode(dau);
//	duyetds(dau);

	bubbleSort(dau);
	bubbleSort(dau1);
//	duyetds(dau);
//	duyetds(dau1);
	duyetds(mergeList(dau,dau1));

//	deleteMultiNumber(dau);
//	duyetds(dau);
	
	return 0;
}

