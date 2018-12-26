#include<stdio.h>

//普通冒泡排序 两两交换 
//降序排列
void Bubble(int *arr,int len)
{
	int temp = 0;
	int num =0;
	for(int i = 0 ;i<len-1;++i)  //最后一个元素  位置 i  i+1越界
	{
		for(int j =0 ;j<len-1;++j)
		{
			if(arr[j]>arr[j+1])
			{
			    temp = arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
		}
	}
}


//冒泡排序优化
//设置一个flag 如果不再发生交换，说明已经有序，不再需要排序，直接退出

void BubbleBetter(int *arr,int len)
{
	int temp = 0;
	int num =0;
	bool flag = false;
	for(int i = 0 ;i<len-1;++i)  //最后一个元素  位置 i  i+1越界
	{
		flag =false;
		for(int j =0 ;j<len-1;++j)
		{
			if(arr[j]>arr[j+1])
			{
			    temp = arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
			flag = true;
		}
		if(!flag)
		{
			return ;
		}
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
	int arr[]={7,3,4,6,4,2.876,3,5346,345};
	int len = sizeof(arr)/sizeof(arr[0]);
	Bubble(arr,len);
	BubbleBetter(arr,len);
	show(arr,len);
	getchar();
	return 0;
}