#include <iostream>
#include "Tree.h"
using namespace std;

int simple_search(int data[],int n,int key){
	int i;
	for (i=0;i<n;i++)
	{
		if (data[i]==key)
		{
			return i;
		}
	}
	return -1;
}

int binary_search(int data[],int n,int key){
	int l;
	int h;
	int m;

	l=0;
	h=n-1;
	m=(l+h)/2;
	while (l<=h)
	{
		if (data[m]==key)
		{
			return m;
		}
		if (data[m]>key)
		{
			h=m-1;
			m=(l+h)/2;
		}else{
			l=m+1;
			m=(l+h)/2;
		}
	}
	return -1;
}

//int hash_search(int data[],int n,int value){
//	int hashKey=getHashKey(value);
//	while (data[hashKey]!=NONE)
//	{
//		if (data[hashKey]==value)
//		{
//			return hashKey;
//		}
//		hashKey=conflict(hashKey);
//	}
//	return -1;
// }

TNode *binaryTree_search(Tree t,int key){
	if (t->data==key)
	{
		return t;
	}
	if (t->data>key)
	{
		return binaryTree_search(t->lchild,key);
	}else{
		return binaryTree_search(t->rchild,key);
	}
}

TNode *makeTNode(int data){
	TNode *nd=(TNode*)malloc(sizeof(TNode));
	nd->rchild=nd->lchild=NULL;
	nd->data=data;
	nd->bw=TIE;
	return nd;
}

void insert_TNode(Tree *t,int key){
	TNode *root=*t;
	if (root==NULL)
	{
		*t=makeTNode(key);
		return;
	}

	if (root->data>key)
	{
		insert_TNode(&(root->lchild),key);
	}else{
		insert_TNode(&(root->rchild),key);
	}
}

void delete_TNode(NodePos *t){
	TNode *nd=*t;
	if (nd==NULL)
	{
		return ;
	}

	if (nd->lchild==NULL)
	{
		*t=nd->rchild;
		free(nd);
		return ;
	}

	if (nd->rchild==NULL)
	{
		*t=nd->lchild;
		free(nd);
		return ;
	}

	NodePos p;
	NodePos pre;
	pre=nd;
	p=pre->lchild;
	while (NULL!=p->rchild)
	{
		pre=p;
		p=p->rchild;
	}

	nd->data=p->data;
	if (pre==nd)
	{
		pre->lchild=p->lchild;
	}else{
		pre->rchild=p->lchild;
	}
	free(p);
}

void right_rotate(Tree *t){
	NodePos root=*t;
	*t=root->lchild;
	root->lchild=(*t)->rchild;
	(*t)->rchild=root;
}

void left_rotate(Tree *t){
	NodePos root=*t;
	*t=root->rchild;
	root->rchild=(*t)->lchild;
	(*t)->lchild=root;
}

void leftBlance(Tree *t){
	NodePos root=*t;
	Blacne bw=root->lchild->bw;

	switch(bw) {
		case LH:
			right_rotate(t);
			(*t)->bw=(*t)->rchild->bw=TIE;
			break;
		case RH:
			bw=root->lchild->rchild->bw;
			left_rotate(&(root->lchild));
			right_rotate(t);
			switch(bw) {
				case RH:		
					(*t)->bw=(*t)->rchild->bw=TIE;
					(*t)->lchild->bw=LH;
					break;
				case LH:
					(*t)->bw=(*t)->lchild->bw=TIE;
					(*t)->rchild->bw=RH;
					break;
			}
			break;
	}
}

void rightBlance(Tree *t){
	NodePos root=*t;
	Blacne bw=root->rchild->bw;
	switch(bw) {
		case RH:
			left_rotate(t);
			(*t)->bw=(*t)->lchild->bw=TIE;
			break;
		case LH:
			bw=root->rchild->lchild->bw;
			right_rotate(&(root->rchild));
			left_rotate(t);
			switch(bw) {
				case RH:
					(*t)->bw=(*t)->lchild->bw=TIE;
					(*t)->rchild->bw=RH;
					break;
				case LH:
					(*t)->bw=(*t)->rchild->bw=TIE;
					(*t)->lchild->bw=LH;
					break;
			}
			break;
	}
}

void insert_Key(Tree *t,int key,int &taller){
	TNode *root=*t;
	if (root==NULL)
	{
		*t=makeTNode(key);
		taller=1;
		return ;
	}

	if (key<root->data)
	{
		insert_Key(&(root->lchild),key,taller);
		if (taller)
		{
			switch(root->bw) {
			case LH:
				leftBlance(t);
				taller=0;
				break;
			case RH:
				root->bw=TIE;
				taller=0;
				break;
			case TIE:
				root->bw=LH;
				taller=1;
				break;
			}
		}
	}else{
		insert_Key(&(root->rchild),key,taller);
		if (taller)
		{
			switch(root->bw) {
				case RH:
					rightBlance(t);
					taller=0;
					break;
				case TIE:
					root->bw=RH;
					taller=1;
					break;
				case LH:
					root->bw=TIE;
					taller=0;
					break;
			}
		}
	}
}
