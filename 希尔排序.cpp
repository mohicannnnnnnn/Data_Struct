#include<stdio.h>
//ϣ������
//��Ԫ�ؽ��з���  gap ���   ����Ԫ��/2  ȡ��    �ڶ���  �µ�Ԫ��/2  ȡ��
//ÿ��������ڽ���  �� ֱ�Ӳ������� ��

void shell(int *arr,int len ,int gap)
{
	int temp = 0;
	int j  = 0;
	for(int i = gap ;i<len;++i)  //��Զ���ÿ��ĵ�һ����ʼ
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
	//����õ���ֵ�Ž�GapArr���棬����Ҫ�û��ֶ�����gapÿ�ε�ֵ
	int GapArr[4] = {0}; //��ʼ��һ�����������ÿ�ε�Gap
	int GapLen = 0;
	 int num = len;
	for(int i = 0; i <4 ;++i)
	{
		 num/=2;  //gap = len /2  �� ģ ��ֵ 
		 if(num !=1)
		 {
			 GapArr[i] = num;
			 ++GapLen;
		 }
		 else
		 {
			 GapArr[i] = 1;  //����λΪ1  ���Ե�����gap==1��  �������һ��GapΪ 1��length++ �� ����ѭ�� 
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