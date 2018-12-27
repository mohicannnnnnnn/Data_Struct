#include<stdio.h>
//每次和待排序 序列的 后面的元素 找到比当前数字 小的数值    进行交换
void Select(int *arr ,int len)
{
	int minindex = 0;
	int temp = 0;
	for(int i = 0;i<len ;i++)
	{
		 minindex = i;//设当前为最小
		for(int j =i+1 ;j<len; j++ )  //从i后面的数据找  ，因为前面已经有序
		{

			if(arr[j]<arr[minindex]) ////arr[j]（i 后面的数据）与mindex 进行比较  如果arr[j] 更小，交换数据
			{
				temp =arr[j];
				arr[j] = arr[minindex];
				arr[minindex] = temp;
			}
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
	int arr[]={7,3,4,6,4,2.876,3,53,346};
	int len = sizeof(arr)/sizeof(arr[0]);
	Select(arr,len);
	show(arr,len);
	getchar();
	return 0;
}