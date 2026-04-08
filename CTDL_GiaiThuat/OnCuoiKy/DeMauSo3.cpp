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

int demNutChan(Node *goc)
{
	if(goc == NULL)
		return 0;
		
	if(goc->data % 2 == 0)
		return 1 + demNutChan(goc->left) + demNutChan(goc->right);
	else
		return demNutChan(goc->left) + demNutChan(goc->right);
}

void swap(Node *goc)
{
	Node *temp;
	if(goc != NULL)
	{
		temp = goc->left;
		goc->left = goc->right;
		goc->right = temp;
	}
	
	if(goc->left != NULL)
		swap(goc->left);
	if(goc->right != NULL)
		swap(goc->right);
}

int sum(Node *dau)
{	
	if(dau->left == NULL && dau->right == NULL)
		return 0;
		
	if(dau->left == NULL)
		return sum(dau->right);
	if(dau->right == NULL)
		return sum(dau->left);
	if(dau->right->data == dau->left->data + 2)
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
	cout << demNutChan(goc) << endl;
	swap(goc);
	LNR(goc);
	cout << endl;
	cout << sum(goc) << endl;
	
	
	return 0;
}

