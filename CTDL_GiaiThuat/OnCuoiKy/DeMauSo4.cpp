#include<iostream>
using namespace std;

struct Node
{
	Node *left;
	Node *right;
	int data;
};

void mocNut(Node *&goc, int x)
{
	if(goc == NULL)
	{
		goc = new Node;
		goc->data = x;
		goc->left = NULL;
		goc->right = NULL;
	}
	else if(goc->data > x)
		mocNut(goc->left,x);
	else
		mocNut(goc->right,x);
}

void taoCay(Node *&goc)
{
	int temp;
	do
	{
		cin >> temp;
		if(temp != 0)
			mocNut(goc,temp);
	}
	while(temp != 0);
}

void LNR(Node *goc)
{
	if(goc != NULL)
	{
		LNR(goc->left);
		cout << goc->data << " ";
		LNR(goc->right);
	}
}

int demCoPhaiKoTrai(Node *goc)
{
	if(goc == NULL)
		return 0;
	if(goc->left == NULL && goc->right != NULL)
		return 1 + demCoPhaiKoTrai(goc->right);
	else
		return demCoPhaiKoTrai(goc->left) + demCoPhaiKoTrai(goc->right);
}

void inNutMucI(Node *goc, int i, int count)
{
	if(goc == NULL)
		return;	
	if(count == i)
		cout << goc->data << " ";
	else
	{
		inNutMucI(goc->left,i,count+1);
		inNutMucI(goc->right,i,count+1);
	}
}

int sum(Node *dau)
{	
	if(dau->left == NULL && dau->right == NULL)
		return 0;
		
	if(dau->left == NULL)
		return sum(dau->right);
	if(dau->right == NULL)
		return sum(dau->left);
	if(dau->right->data % dau->left->data == 0)
		return dau->data + sum(dau->left) + sum(dau->right);
	else
		return sum(dau->left) + sum(dau->right);
}

int main()
{
	Node *goc = NULL;
	taoCay(goc);
	LNR(goc);
	cout << endl;
	cout << demCoPhaiKoTrai(goc) << endl;
	inNutMucI(goc,3,1);
	cout << endl;
	cout << sum(goc);

	return 0;
}
