#include<iostream>
using namespace std;

struct Node
{
	Node *left;
	int data;
	Node *right;
};

void khoitao(Node *&goc)
{
	goc = NULL;
}

void mocnut(Node *&goc, int temp)
{
	if(goc == NULL)
	{
		goc = new Node;
		goc->data = temp;
		goc->right = NULL;
		goc->left = NULL;
	}
	else
		if(goc->data >= temp)
			mocnut(goc->left,temp);
		else
			mocnut(goc->right,temp);
}

void taocay(Node *&goc)
{
	int data;
	do
	{
		cin >> data;
		if(data != 0)
			mocnut(goc,data);
	}
	while(data != 0);
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

void LRN(Node *goc)
{
	if(goc != NULL)
	{
		LRN(goc->left);
		LRN(goc->right);
		cout << goc->data << " ";
	}
}

int treeHeight(Node *goc)
{
	if(goc == NULL)
		return 0;
	else
		return 1 + max(treeHeight(goc->left), treeHeight(goc->right));
}

void cacNutMucI(Node *goc, int i, int count)
{
	if(goc != NULL)
	{
		count++;
		cacNutMucI(goc->left,i,count);
		if(count == i)
			cout << goc->data << " ";
		cacNutMucI(goc->right,i,count);
	}
}

//void saoChep

int main()
{
	Node *goc;
	
	khoitao(goc);
	taocay(goc);
	LNR(goc);
	cout << endl;
	LRN(goc);
	cout << endl;
	cout << treeHeight(goc) << endl;
	cacNutMucI(goc,2,0);

	return 0;
}

