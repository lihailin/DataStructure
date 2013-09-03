#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

/*//////////////////////////////////////////////////////////////////////////
1.≤Â»Î≈≈–Ú
2.’€∞Î≤Â»Î≈≈–Ú
3.2-¬∑≤Â»Î≈≈–Ú
4.±Ì≤Â»Î≈≈–Ú
5.œ£∂˚≈≈–Ú
6.øÏÀŸ≈≈–Ú
7.πÈ≤¢≈≈–Ú
8.—°‘Ò≈≈–Ú
9. ˜–Œ—°‘Ò≈≈–Ú
10.∂—≈≈–Ú
11.¡¥ Ωª˘ ˝≈≈–Ú

≤Â»Î°¢—°‘Ò°¢Ωªªª°¢πÈ≤¢°¢º∆ ˝
//////////////////////////////////////////////////////////////////////////*/

void bubble_sort(int data[],int n){
	int i;
	int j;
	int temp;
	for (i=0;i<n;i++)
	{
		for (j=n-1;j>i;j--)
		{
			if (data[j-1]>data[j])
			{
				temp=data[j];
				data[j]=data[j-1];
				data[j-1]=temp;
			}
		}
	}
}

int nth_element(int data[],int n,int m){
	int i;
	int j;
	int temp;
	for (i=0;i<m;i++)
	{
		for (j=n-1;j>i;j--)
		{
			if (data[j-1]>data[j])
			{
				temp=data[j];
				data[j]=data[j-1];
				data[j-1]=temp;
			}
		}
	}
	return data[m-1];
}

void insert_sort(int data[],int n){
	int i;
	int j;
	int temp;
	for (i=1;i<n;i++)
	{
		temp=data[i];
		for (j=i;j>0&&data[j-1]>temp;j--)
		{
			data[j]=data[j-1];
		}
		data[j]=temp;
	}
}

void insertBinary_sort(int data[],int n){
	int i;
	int j;
	int temp;

	int l,h,m;
	for (i=1;i<n;i++)
	{
		temp=data[i];
		l=0;
		h=i-1;
		m=(l+h)/2;
		while (l<=h)
		{
			if (data[m]<temp)
			{
				l=m+1;
				m=(l+h)/2;
			}else{
				h=m-1;
				m=(l+h)/2;
			}
		}
		
		for (j=i;j>l;j--)
		{
			data[i]=data[i-1];
		}
		data[l]=temp;
	}
}

void insert2Road_sort(int data[],int n)
{
	int *buf=(int*)malloc(sizeof(int)*n);
	int l;
	int h;

	l=n-1;
	h=1;
	buf[0]=data[0];

	int i;
	int j;
	int temp;
	for(i=1;i<n;i++)
	{
		temp=data[i];
		if (temp>buf[0])
		{
			for (j=h-1;j>0 && buf[j]>temp;j--)
			{
				buf[j+1]=buf[j];
			}
			buf[j+1]=temp;
			h++;
		}else{
			for (j=l+1;j<n && buf[j]<temp;j++)
			{
				buf[j-1]=buf[j];
			}
			buf[j-1]=temp;
			l--;
		}
	}

	data[0]=buf[l];
	for (i=(l+1)%n,j=1;i!=l;i=(i+1)%n)
	{
		data[j++]=buf[i];
	}
	free(buf);
}

void tableInsert_sort(int data[],int n){
	int *next=(int*)malloc(sizeof(int)*n);
	int l;
	l=0;
	next[0]=-1;

	int i;
	int j;
	for (i=1;i<n;i++)
	{
		if (data[i]<data[l])
		{
			next[i]=l;
			l=i;
		}else{
			for (j=l;next[j]!=-1 && data[i]>data[next[j]];j=next[j]);
			next[i]=next[j];
			next[j]=i;
		}
	}

	int temp;
	for (i=0;i<n;i++)
	{
		for (j=l;j<i;j=next[j]);
		l=next[j];

		temp=data[i];
		data[i]=data[j];
		data[j]=temp;

		next[j]=next[i];
		next[i]=j;
	}
	free(next);
}

void showInts(int data[],int n){
	for (int i=0;i<n;i++)
	{
		printf("%d ",data[i]);
	}
	printf("\n");
}

void sub_shell_sort(int data[],int n,int wd){
	int i;
	int j;
	int temp;
	for (i=wd;i<n;i++)
	{
		temp=data[i];
		for (j=i-wd;j>=0 && data[j]>temp;j-=wd){
			data[j+wd]=data[j];
		}
		data[j+wd]=temp;
	}
}

void shell_sort(int data[],int n,int wd[],int m){
	for (int i=0;i<m;i++)
	{
		sub_shell_sort(data,n,wd[i]);
	}
}

void quick_partation(int data[],int l,int h){
	if (l>=h)
	{
		return ;
	}

	int i;
	int j;
	int middle;

	middle=data[l];
	i=l;
	j=h;
	while(i<j)
	{
		for (;i<j && data[j]>=middle;j--);
		if (i<j)
		{
			data[i]=data[j];
			i++;
		}

		for(;i<j && data[i]<=middle;i++);
		if (i<j)
		{
			data[j]=data[i];
			j--;
		}
	}

	if (i-1>l)
	{
		quick_partation(data,l,i-1);
	}	
	if (i+1<h)
	{
		quick_partation(data,i+1,h);
	}
}

void quick_sort(int data[],int n){
	quick_partation(data,0,n-1);
}

void subMerge_sort(int data[],int l,int h,int buf[]){
	if (l>=h)
	{
		return ;
	}

	int m=(h+l)/2;
	if (m>l)
	{
		subMerge_sort(data,l,m,buf);
	}
	if (m+1<h)
	{
		subMerge_sort(data,m+1,h,buf);
	}

	int i=l;
	int j=m+1;
	int k=l;
	while (i<=m && j<=h)
	{
		if (data[i]<data[j])
		{
			buf[k++]=data[i++];
		}else{
			buf[k++]=data[j++];
		}
	}
	if (i<=m)
	{
		memcpy(buf+k,data+i,sizeof(int)*(m-i+1));
	}
	if (j<=h)
	{
		memcpy(buf+k,data+j,sizeof(int)*(h-j+1));
	}

	memcpy(data+l,buf+l,sizeof(int)*(h-l+1));
}


void merge_sort(int data[],int n){
	int *buf=(int*)malloc(sizeof(int)*n);
	subMerge_sort(data,0,n-1,buf);
	free(buf);
}

void select_sort(int data[],int n){
	int i;
	int *p;
	int temp;
	for (i=0;i<n;i++)
	{
		p=min_element(data+i,data+n);
		temp=*p;
		*p=data[i];
		data[i]=temp;
	}
}

int* min_treeSelect(int data[],int l,int h){
	if (l>h)
	{
		return NULL;
	}
	if (l==h)
	{
		return data+l;
	}
	int m=(h+l)/2;
	int *pre;
	int *tail;
	pre=min_treeSelect(data,l,m);
	tail=min_treeSelect(data,m+1,h);
	
	return *pre<*tail ? pre:tail;
}

void treeSelect_sort(int data[],int n){
	int i;
	int temp;
	int *p;
	for (i=0;i<n;i++)
	{
		p=min_treeSelect(data,i,n-1);
		if (p!=(data+i))
		{
			temp=*p;
			*p=data[i];
			data[i]=temp;
		}
	}
}

void fromTop_adjustHeap(int heap[],int n,int top){
	int i=top;
	if (2*top+1<n && heap[i] > heap[2*top+1])
	{
		i= top*2+1;
	}
	if (2*top+2<n && heap[i] > heap[2*top+2])
	{
		i=top*2+2;
	}
	int temp;
	if (i!=top)
	{
		temp=heap[top];
		heap[top]=heap[i];
		heap[i]=temp;
		fromTop_adjustHeap(heap,n,i);
	}
}

void heap_sort(int data[],int n){
	//create heap
	int i;
	for (i=(n-2)/2;i>=0;i--)
	{
		fromTop_adjustHeap(data,n,i);
	}

	int temp;
	for (i=n-1;i>0;i--)
	{
		temp=data[0];
		data[0]=data[i];
		data[i]=temp;

		fromTop_adjustHeap(data,i,0);
	}
}

void count_sort(int data[],int n){
	int *buf=(int*)malloc(sizeof(int)*n);
	int i;
	int j;
	int temp;

	memset(buf,0,sizeof(int)*n);
	for(i=0;i<n;i++){
		temp=data[i];
		for(j=i+1;j<n;j++){
			if (temp>data[j])
			{
				buf[i]++;
			}else{
				buf[j]++;
			}
		}
	}
	
	for (i=0;i<n;i++)
	{
		while (i!=buf[i])
		{
			temp=data[i];
			data[i]=data[buf[i]];
			data[buf[i]]=temp;

			temp=buf[i];
			buf[i]=buf[temp];
			buf[temp]=temp;
		}
	}
}


struct node {
	struct node *next;
	int data;
};

typedef struct node Node;

Node *makeNode(int data){
	Node *nd=(Node*)malloc(sizeof(Node));
	nd->next=NULL;
	nd->data=data;
	return nd;
}

int getkey(int data,int m){
	int base=pow(10,m);
	data/=base;
	data%=10;
	return data;
}

void distribution(int data[],int n,Node tail[],int m){
	int i;
	int key;
	Node* pnode;
	for (i=0;i<n;i++)
	{
		key=getkey(data[i],m);
		pnode=makeNode(data[i]);
		tail[key].next->next=pnode;
		tail[key].next=pnode;
	}
}

void collect(int data[],int n,Node nodes[]){
	int i;
	Node *p;
	int j;
	for (j=0,i=0;i<10 && j<n;i++)
	{
		p=nodes[i].next;
		while (p!=NULL)
		{
			data[j++]=p->data;
			nodes[i].next=p->next;
			free(p);
			p=nodes[i].next;
		}
	}
}

void linkedRadix_sort(int data[],int n){
	int i;
	int j;
	Node nodes[10];
	Node tail[10];
	for (i=0;i<3;i++)
	{
		for (j=0;j<10;j++)
		{
			nodes[j].next=NULL;
			tail[j].next=nodes+j;
		}
		distribution(data,n,tail,i);
		collect(data,n,nodes);
	}
}

//int main(){
//	int data[]={65,93,21,12,39,56};
//	linkedRadix_sort(data,6);
//	showInts(data,6);
//	return 0;
// }
