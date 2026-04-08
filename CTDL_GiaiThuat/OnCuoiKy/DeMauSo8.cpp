#include<iostream>
using namespace std;

struct nut {
	int data;
    nut *left, *right;
};
typedef nut Node;

void mocNut(Node *&goc, int x, int i, int count)
{
	if(count > i)
		return;
	if(goc == NULL)
	{
		goc = new Node;
		goc->data = x;
		goc->left = NULL;
		goc->right = NULL;
	}
	else 
	{
		if(count * 2 == i)
			mocNut(goc->left,x,i,count);
		else if(count * 2 + 1 == i)
			mocNut(goc->right,x,i,count);
		else
		{
			mocNut(goc->left,x,i,count+1);
			mocNut(goc->right,x,i,count+2);
		}			
	}
}

void taoCay(Node *&goc)
{
	int temp;
	int i = 1;
	do
	{
		cin >> temp;
		if(temp != 0)
		{
			mocNut(goc,temp,i,1);
			i++;
		}
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

int isBST(Node *goc)
{
	if(goc == NULL)
		return 0;
	if(goc->left != NULL && goc->data < goc->left->data)
		return 1 + isBST(goc->left);
	if(goc->right != NULL && goc->data >= goc->right->data)
		return 1 + isBST(goc->right);
	if(goc->left != NULL && goc->right != NULL)
		return isBST(goc->left) + isBST(goc->right);
	else
		return 0;		
}

int heightTree(Node *dau)
{
	if(dau == NULL)
		return 0;
	
	return 1 + max(heightTree(dau->left),heightTree(dau->right));
}


int main()
{
	Node *goc = NULL;
	taoCay(goc);
	LNR(goc);
	cout << endl;
	if(!isBST(goc))
		cout << "LA BST" << endl;
	else
		cout << "KHONG LA BST" << endl;
	
	cout << heightTree(goc) << endl;

	return 0;
}

