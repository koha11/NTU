#include<iostream>
using namespace std;
#include<stdio.h>

struct nut{
    int info;
    nut *left;
	nut *right;
};

typedef nut Node;

Node *goc, *newGoc;

void khoitao(Node *&goc){
    goc = NULL;
}
//Lan luot nhap cac so nguyen,dung khi go 0
//Cac so nguyen nhap vao duoc luu tru thanh cay nhi phan tim kiem


//Moc nut gia tri x vao cay
void mocnut(Node *&goc,int x){
    //Cay chua co nut,thi tao nut moi co gia tri la x
    if(goc==NULL){
        goc = new Node;
        goc->info=x;
        goc->left=NULL;
        goc->right=NULL;
    }
    //nguoc lai
    else{
        if(goc->info>=x){
            mocnut(goc->left,x);
        }
        else{
            mocnut(goc->right,x);
        }
    }
}

//tao cay
void taocay(Node *&goc){
    int tam;
    do{
        cout << "Nhap 1 so nguyen, 0 se dung: ";
        cin >> tam;
        if(tam!=0){
            mocnut(goc,tam);
        }
    }
	while(tam!=0);
}

//Duyet cay
void LNR(Node *goc)
{
	if(goc != NULL)
	{
		LNR(goc->left);
		cout << goc->info << " ";
		LNR(goc->right);
	}
}

void NLR(Node *goc)
{
	if(goc != NULL)
	{
		cout << goc->info << " ";
		NLR(goc->left);		
		NLR(goc->right);
	}
}

int tongnut(Node *goc)
{
	if(goc == NULL)
		return 0;
	else
		if(goc->info % 2 == 0)
			return goc->info + tongnut(goc->left) + tongnut(goc->right);
		else
			return tongnut(goc->left) + tongnut(goc->right);
}

int demnut(Node *goc)
{
	if(goc == NULL)
		return 0;
	else		
		return 1 + demnut(goc->left) + demnut(goc->right);
}

int sonutcophaiktrai(Node *goc)
{
	if(goc == NULL)
		return 0;
	else
		if((goc->right != NULL) && (goc->left == NULL))
			return 1 + sonutcophaiktrai(goc->right);
		else
			return sonutcophaiktrai(goc->right) + sonutcophaiktrai(goc->left);
}

int chieucao(Node *goc)
{
	if(goc == NULL)
		return 0;
	else
		return 1 + max(chieucao(goc->left),chieucao(goc->right));
}

int sumLevelNode(Node *goc, int level, int count)
{
	if(count == level)
		return goc->info;
	return sumLevelNode(goc->left,level,count+1) + sumLevelNode(goc->right,level,count+1);
}

void copyTree(Node *&newGoc, Node *oldGoc)
{
	if(oldGoc == NULL)
		return;
	mocnut(newGoc,oldGoc->info);
	copyTree(newGoc,oldGoc->left);
	copyTree(newGoc,oldGoc->right);
}

//--------Hàm tìm ph?n t? th? m?ng------------------------ 
void phantuthemang(Node *&p,Node *&q)
{ 
	if (q->left)
		phantuthemang(p,q->left); 
	else 
	{ 
		p->info=q->info; 
		p=q; 
		q=q->right; 
	} 
} 
//---------------Xóa nút có giá tr? là k---------------------- 
int xoanut(Node *&root,int k) 
{ 
	if(root==NULL) 
		return 0; 
	if(root->info>k) 
		return xoanut(root->left,k); 
	if(root->info<k)
		return xoanut(root->right,k); 
	else 
	{ 
		Node *p=root; 
		if(root->right==NULL) 
			root=root->left; 
		else 
			if(root->left==NULL) 
				root=root->right; 
			else
			{
				Node *q=root->right; 
				phantuthemang(p,q);
			}
		
		delete(p); 
	}
	return 1; 
}

void hoanDoiCayCon(Node *&goc)
{
	if(goc == NULL)
		return;
	
	Node *temp = goc->left;
	goc->left = goc->right;
	goc->right = temp;
	hoanDoiCayCon(goc->left);
	hoanDoiCayCon(goc->right);
}


int main()
{
	khoitao(goc);	
	taocay(goc);
//	cout << "Duyet LNR: " << endl;
//	LNR(goc);
//	cout << endl;
	cout << "Duyet NLR: " << endl;
	NLR(goc);
	cout << endl;
//	cout << "SUM NODE = " << tongnut(goc) << endl;
//	cout << "COUNT NODE = " << demnut(goc) << endl;
//	cout << "COUNT NODE HAS ONLY RIGHT = " << sonutcophaiktrai(goc) << endl;
//	cout << "HEIGHT NODE = " << chieucao(goc) << endl;
//	cout << "sum level node = " << sumLevelNode(goc,2,0) << endl;
//	khoitao(newGoc);
//	copyTree(newGoc,goc);
//	cout << "Duyet NLR: " << endl;
//	NLR(newGoc);
//	cout << endl;
	xoanut(goc,15);
	NLR(goc);
//	hoanDoiCayCon(goc);
//	NLR(goc);



	return 0;
}
