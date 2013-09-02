#include <iostream>

using namespace std;

/*//////////////////////////////////////////////////////////////////////////
1.²åÈëÅÅĞò
2.ÕÛ°ë²åÈëÅÅĞò
3.2-Â·²åÈëÅÅĞò
4.±í²åÈëÅÅĞò
5.Ï£¶ûÅÅĞò
6.¿ìËÙÅÅĞò
7.¹é²¢ÅÅĞò
8.Ñ¡ÔñÅÅĞò
9.Ê÷ĞÎÑ¡ÔñÅÅĞò
10.¶ÑÅÅĞò
11.Á´Ê½»ùÊıÅÅĞò

²åÈë¡¢Ñ¡Ôñ¡¢½»»»¡¢¹é²¢¡¢¼ÆÊı
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

void chose_sort(){

}

int main(){
	int data[]={5,3,1,2,9,6};
	tableInsert_sort(data,6);
	showInts(data,6);
	return 0;
}
