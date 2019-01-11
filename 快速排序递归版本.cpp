#include<iostream>
#define SIZE 10 
using namespace std;
//快速排序 根据基准元素 来排序
//一趟快速排序过程 ---》与基准进行比较
//递归寻找基准的过程


//寻找基准 一趟快速排序的过程
int Partion(int *arr, int left ,int right)
{
	int L = left ;
	int R = right;
	int par  = 0;
	int base = 0;
	while(L< R)
	{
		base = arr[L];
		//第一步 从右向左扫描  比base小，与left交换
		while ((L< R) && (arr[R]>=base))
		{
			--R;
		}
		if(arr[R] <base)
		{
			arr[L] = arr[R];
		}
		//第二步，从左向右扫面,比base大，与right 交换
		//left == right   返回par;
		while ( (L< R) && (arr[L]<=base))
		{
			++L;
		}
		if(arr[L]>base)
		{
			arr[R]=arr[L];
		}
			arr[L] = base;
	}
	par = L;
	return par;
}

//递归每次找基准   保证左右两边两个数据以上
void Quick(int *arr,int start,int end)
{
	int par = Partion(arr,start,end);
	//如果左边有两个数据以上
	if(par>start+1)
	{
		Quick(arr,start,par-1);
	}
	//如果右边还有两个数据以上
	if(par<end-1)
	{
		Quick(arr,par+1,end);
	}
	return ;
}

void QuickSort(int *arr,int len)
{
	Quick(arr,0,len-1);
}

void Show(int *arr,int len)
{
	for(int i =0;i<len;++i)
	{
		cout<<arr[i]<<"   ";
	}
}

int main()
{
	cout<<"Please input number ! SIZE ="<<SIZE<<endl;
	int *arr= new int[SIZE] ;
    for(int i = 0;i<SIZE;++i)
	{
		cin>>arr[i];
	}
	int len = SIZE;
	QuickSort(arr,len);
	Show(arr,len);
	system("pause");
	return 0;
}