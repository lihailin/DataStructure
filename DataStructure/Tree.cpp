#include <iostream>
#include "tree.h"
using namespace std;

/*//////////////////////////////////////////////////////////////////////////
一、树的度、树的深度
二、二叉树性质5条：
	1.深度为k二叉树，最多有2^k-1个节点
	2.二叉树的第i层，最多有2^(i-1)个节点
	3.n0=n2+1
	
	4.节点数为n的完全二叉树，深度为：[logn]+1 或者 ceil(log(n+1))
	5.完全二叉树，2*i 2*i+1 n/2
三、顺序存储 二叉链表


  1.遍历
  2.线索化
  3.等价划分
  4.赫夫曼编码
  5.KMP
//////////////////////////////////////////////////////////////////////////*/

typedef void (*Visit)(int);

void inOrder_traverse(Tree t,Visit visit){
	if (NULL==t)
	{
		return ;
	}
	if (NULL!=t->lchild)
	{
		inOrder_traverse(t->lchild,visit);
	}
	visit(t->data);
	if (NULL!=t->rchild)
	{
		inOrder_traverse(t->rchild,visit);
	}
}

TNode *makeThreadNode(){
	TNode *nd=(TNode*)malloc(sizeof(TNode));
	nd->lchild=nd->rchild=NULL;
	nd->ltype=nd->rtype=link;
	return nd;
}

void subInOrder_threading(Tree t,NodePos &pre){
	if (NULL==t)
	{
		return ;
	}

	if (NULL!=t->lchild)
	{
		subInOrder_threading(t->lchild,pre);
	}else{
		t->ltype=thread;
		t->lchild=pre;
		if (NULL==pre->rchild)
		{
			pre->rtype=thread;
			pre->rchild=t;
		}
	}
	
	pre=t;

	if (NULL!=t->rchild)
	{
		subInOrder_threading(t->rchild,pre);
	}
}

void inOrder_threading(Tree *th,Tree t){
	NodePos fn;
	NodePos pre;

	*th	= makeThreadNode();
	pre=fn=*th;
	fn->rchild=t;
	
	subInOrder_threading(t,pre);
	
	fn->ltype=thread;
	fn->lchild=pre;
	if (NULL==pre->rchild)
	{
		pre->rtype=thread;
		pre->rchild=fn;
	}
}

NodePos getNextPos(Tree t){
	if (thread==t->rtype)
	{
		return t->rchild;
	}

	for (t=t->rchild;NULL!=t->lchild;t=t->lchild);
	return t;
}

void inOrder_traverseThread(Tree t,Visit visit){
	if (NULL==t)
	{
		return ;
	}
	NodePos p=getNextPos(t);
	while (t!=p)
	{
		visit(p->data);
		p=getNextPos(p);
	}
	
}

int getSetId(int data[],int i){
	while (-1!=data[i])
	{
		i=data[i];
	}
	return i;
}

void mergeSet(int data[],int i,int j){
	data[i]=j;
}

void partation_equal(int data[],int n,int equal[][2],int m){
	int i;
	for (i=0;i<n;i++)
	{
		data[i]=-1;
	}

	int k;
	int j;
	for (i=0;i<m;i++)
	{
		k=getSetId(data,equal[i][0]);	
		j=getSetId(data,equal[i][1]);	
		mergeSet(data,k,j);
	}
}

void showSet(int data[],int n){
	int i;
	int j;
	int *flag=(int*)malloc(sizeof(int)*n);
	memset(flag,0,sizeof(int)*n);
	for (i=0;i<n;i++)
	{
		if (0==flag[i])
		{
			j=i;
			while (j!=-1)
			{
				printf("%d ",j);
				flag[j]=1;
				j=data[j];
			}
			printf("\n");
		}
	}
}

struct hfmnode {
	int w;
	int parent;
	int lchild;
	int rchild;
};

typedef struct hfmnode *HfmTree;

void selectMin2(HfmTree t,int n,int &i,int &j){
	if (n<2)
	{
		i=j=-1;
		return ;
	}

	int k;
	i=j=-1;
	for (k=0;k<n;k++)
	{
		if (-1!=t[k].parent)
		{
			continue;
		}

		if (-1==i || t[k].w < t[i].w)
		{
			j=i;
			i=k;
		}else if(-1==j || t[k].w < t[j].w){
			j=k;
		}
	}

}

void hfmCode(int w[],int n,char *code[]){
	//init hfm tree
	HfmTree tree=(HfmTree)malloc(sizeof(struct hfmnode)*n*2);
	int i;
	for (i=0;i<n;i++)
	{
		tree[i].lchild=tree[i].rchild=tree[i].parent=-1;
		tree[i].w=w[i];
	}
	for (i=n;i<n*2;i++)
	{
		tree[i].lchild=tree[i].rchild=tree[i].parent=-1;
	}
	//create hfm tree
	int j,k;
	for (i=n;i<2*n-1;i++)
	{
		selectMin2(tree,i,j,k);
		tree[k].parent=tree[j].parent=i;
		tree[i].lchild=k;
		tree[i].rchild=j;
		tree[i].w=tree[k].w+tree[j].w;
	}
	//coding hfm code
	char *buf=(char*)malloc(n);
	int bn=0;
	for (i=0;i<n;i++)
	{
		code[i]=(char*)malloc(n);
	}

	for (i=0;i<n*2;i++)
	{
		tree[i].w=0;
	}
	i=2*n-2;
	while (i!=-1)
	{
		switch(tree[i].w) {
		case 0:
			tree[i].w=1;
			if (-1!=tree[i].lchild)
			{
				buf[bn++]='1';
				i=tree[i].lchild;
			}else if(-1==tree[i].rchild){
				buf[bn]='\0';
				strcpy(code[i],buf);
			}
			break;
		case 1:
			tree[i].w=2;
			if (-1!=tree[i].rchild)
			{
				buf[bn++]='0';
				i=tree[i].rchild;
			}
			break;
		case 2:
			tree[i].w=3;
			bn--;
			i=tree[i].parent;
			break;
		}
	}
	free(buf);
}

void fillNextReal(char *s,int n,int nextReal[]){
	int i=0;
	int j=-1;
	nextReal[i]=j;

	while (i<n-1)
	{
		if (-1==j || s[j] == s[i])
		{
			i++;
			j++;
			if (s[i]!=s[j])
			{
				nextReal[i]=j;
			}else{
				nextReal[i]=nextReal[j];		
			}
		}else{
			j=nextReal[j];
		}
	}
}

int indexOfStr(char *s,char *cmp,int nextval[]){
	int i=0;
	int j=0;

	while ('\0'!=s[i] && '\0'!=cmp[j])
	{
		if (-1==j || cmp[j]==s[i])
		{
			i++;
			j++;
		}else{
			j=nextval[j];
		}
	}
	if ('\0'!=cmp[j])
	{
		return -1;
	}
	return i-j;
}
//
//int main(){
////	int data[11];
////	int equal[][2]={{1,2},{1,3},{4,5},{5,6},{7,8},{8,9}};
////	partation_equal(data,11,equal,6);
//// 	showSet(data,11);
//
////	int w[]={1,2,3,4,5,6};
////	char *code[6];
////	hfmCode(w,6,code);
////	for (int i=0;i<6;i++)
////	{
////		printf("%s\n",code[i]);
//// 	}
//	char *s="aaaab";
//	int next[5];
//	fillNextReal(s,5,next);
//	for (int i=0;i<5;i++)
//	{
//		printf("%d ",next[i]);
//	}
//	printf("\n");
//
//	printf("%d\n",indexOfStr("aabaaaab",s,next));
//	return 0;
//}
