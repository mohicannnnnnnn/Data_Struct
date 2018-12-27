#include<stdio.h>
//希尔排序
//对元素进行分组  gap 间隔   数据元素/2  取整    第二次  新的元素/2  取整
//每个间隔组内进行  【 直接插入排序 】

void shell(int *arr,int len ,int gap)
{
	int temp = 0;
	int j  = 0;
	for(int i = gap ;i<len;++i)  //相对而言每组的第一个开始
	{
		temp = arr[i];
		for( j =i-gap;j>=0;j=j-gap)
		{
			if(arr[j]>temp)
			{
				arr[j+gap] = arr[j];
			}
			else
			{
				break;
			}
		}
		arr[j+gap] = temp;
	}

}

void shellsort(int*arr,int len)
{
	//计算好的数值放进GapArr里面，而不要用户手动输入gap每次的值
	int GapArr[4] = {0}; //初始化一个数组里面放每次的Gap
	int GapLen = 0;
	 int num = len;
	for(int i = 0; i <4 ;++i)
	{
		 num/=2;  //gap = len /2  的 模 的值 
		 if(num !=1)
		 {
			 GapArr[i] = num;
			 ++GapLen;
		 }
		 else
		 {
			 GapArr[i] = 1;  //结束位为1  所以当遇到gap==1后，  设置最后一个Gap为 1，length++ ； 跳出循环 
			 ++GapLen;
			 break;
		 }
	}

	for(int i = 0;i<GapLen;++i)
	{
		shell(arr,len,GapArr[i]);
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
	int brr[] = {1,2,3,4,5,6,100,200,42};
	int len = sizeof(brr)/sizeof(brr[0]);
	shellsort(brr,len);
	show(brr,len);
	getchar();
	return 0;
}