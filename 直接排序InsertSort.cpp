#include<stdio.h>

//直接插入排序    
//类似于扑克牌   接牌的过程  与选择排序有点类似 
//设置一个tmp 把 当前i 的值 放在tmp里面，每个数据和tmp进行比较，如果是降序
//  pcur >  tmp ==>   pcur -->赋给 tmp  ,再把 i+1的值赋给 pcur ； j-- ,继续和tmp进行比较   

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