#include<stdio.h>

//ֱ�Ӳ�������    
//�������˿���   ���ƵĹ���  ��ѡ�������е����� 
//����һ��tmp �� ��ǰi ��ֵ ����tmp���棬ÿ�����ݺ�tmp���бȽϣ�����ǽ���
//  pcur >  tmp ==>   pcur -->���� tmp  ,�ٰ� i+1��ֵ���� pcur �� j-- ,������tmp���бȽ�   

void InsertSort(int *arr,int len)
{
	int temp = 0;
	int j =0;
	for(int i =0;i<len;++i)
	{
		int temp = arr[i];
	    for( j = i-1;j>=0;--j)
		{
			if(arr[j] >temp)
			{
				arr[j+1] = arr[j];
			}
			else
			{
				break;
			}
		}
		arr[j+1] = temp;
	}
}

void show(int *arr,int len)
{
	for(int i =0;i<len;++i)
	{
		printf("%d\t",arr[i]);
	}
}

int main()
{
	int arr[]={7,3,4,6,4,2.876,3,53,346};
	int len = sizeof(arr)/sizeof(arr[0]);
	InsertSort(arr,len);
	show(arr,len);
	getchar();
	return 0;
}