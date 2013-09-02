#include <iostream>

using namespace std;

/*//////////////////////////////////////////////////////////////////////////
1.插入排序
2.折半插入排序
3.2-路插入排序
4.表插入排序
5.希尔排序
6.快速排序
7.归并排序
8.选择排序
9.树形选择排序
10.堆排序
11.链式基数排序

插入、选择、交换、归并、计数
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

void quick_sort(int data[],int l,int h){
	
}

int main(){
	int data[]={5,3,1,2,9,6};
	tableInsert_sort(data,6);
	showInts(data,6);
	return 0;
}
