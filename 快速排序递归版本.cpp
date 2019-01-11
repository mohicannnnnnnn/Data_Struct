#include<iostream>
#define SIZE 10 
using namespace std;
//�������� ���ݻ�׼Ԫ�� ������
//һ�˿���������� ---�����׼���бȽ�
//�ݹ�Ѱ�һ�׼�Ĺ���


//Ѱ�һ�׼ һ�˿�������Ĺ���
int Partion(int *arr, int left ,int right)
{
	int L = left ;
	int R = right;
	int par  = 0;
	int base = 0;
	while(L< R)
	{
		base = arr[L];
		//��һ�� ��������ɨ��  ��baseС����left����
		while ((L< R) && (arr[R]>=base))
		{
			--R;
		}
		if(arr[R] <base)
		{
			arr[L] = arr[R];
		}
		//�ڶ�������������ɨ��,��base����right ����
		//left == right   ����par;
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

//�ݹ�ÿ���һ�׼   ��֤��������������������
void Quick(int *arr,int start,int end)
{
	int par = Partion(arr,start,end);
	//��������������������
	if(par>start+1)
	{
		Quick(arr,start,par-1);
	}
	//����ұ߻���������������
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