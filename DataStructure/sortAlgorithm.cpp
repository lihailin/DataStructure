#include <iostream>

using namespace std;

/*//////////////////////////////////////////////////////////////////////////
1.��������
2.�۰��������
3.2-·��������
4.���������
5.ϣ������
6.��������
7.�鲢����
8.ѡ������
9.����ѡ������
10.������
11.��ʽ��������

���롢ѡ�񡢽������鲢������
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
