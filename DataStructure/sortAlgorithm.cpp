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

void 

int main(){
	
	return 0;
}
