#include<stdio.h>
//ÿ�κʹ����� ���е� �����Ԫ�� �ҵ��ȵ�ǰ���� С����ֵ    ���н���
void Select(int *arr ,int len)
{
	int minindex = 0;
	int temp = 0;
	for(int i = 0;i<len ;i++)
	{
		 minindex = i;//�赱ǰΪ��С
		for(int j =i+1 ;j<len; j++ )  //��i�����������  ����Ϊǰ���Ѿ�����
		{

			if(arr[j]<arr[minindex]) ////arr[j]��i ��������ݣ���mindex ���бȽ�  ���arr[j] ��С����������
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