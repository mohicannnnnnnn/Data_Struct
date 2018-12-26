#pragma once
#include"SXList.h"
#include<stdio.h>
#include<assert.h>
#include<malloc.h>
#define SIZE 20
void Initisite(PList  plist )
{
	assert(plist!=NULL);
	plist->elem = (int *) malloc (SIZE * sizeof(int ));
	assert(plist->elem!=NULL);
	plist->length = SIZE;
	plist->usedsize = 0;
}

bool IsFull(PList plist)
{
	if(plist->usedsize==plist->length)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Resize(PList plist)
{
	plist->elem = (int *)realloc(plist->elem,SIZE*sizeof(int)*2);
	assert(plist->elem!=NULL);
	plist->length*=2;

}

bool AddList(PList plist,int pos ,int value) //在pos位插入一个 value
{
	assert(plist!=NULL);
	if(IsFull(plist))
	{
		Resize(plist);
	}
	if(pos<0 || pos>plist->usedsize)  //顺序表是连续存储的
	{
		return false;
	}
	//从后往前挪
	for(int i =plist->usedsize;i>pos ;--i)
	{
		plist->elem[i] = plist->elem[i-1];
	}
	plist->elem[pos] = value;
	plist->usedsize++;
	return true;
}
bool DelList(PList plist,int pos, int value )//删除pos位置的一个value，把删除掉的value保存
{
	assert(plist!=NULL);
	if(pos<0 || pos>plist->usedsize)
	{
		return false;
	}
	value = plist->elem[pos]; 
	//printf("第%d位置的元素 %d已经删除\n",pos+1,value);
	for(int i =pos;i<plist->usedsize;++i)
	{
		plist->elem[i-1] = plist->elem[i];
	}
	plist->usedsize--;
	return true;
}
bool Search(PList plist,int pos,int value)//从Pos位开始查找一个value值，并将结果返回pos
{
	assert(plist!=NULL);
	if(pos <0 || pos>plist->usedsize)
	{
		return false;
	}
	for(int i =pos-1;i<plist->usedsize;++i)
	{
		if(plist->elem[i] == value)
		{
			printf("在%d号位置找到\n",i+1);
			return true;
		}
	}
	return false;

}
bool DelVal(PList plist ,int pos,int value)// 删除指定Value值,从pos位开始的第一个
{
	if(Search(plist,pos,value))
	{
		for(int i = pos-1 ;i<plist->usedsize;++i)
		{
			if(plist->elem[i]== value)
			{
				DelList(plist,i+1,NULL);
				return true;
			}
		}
	}
	else
	{
		return false;
	}
}

int GetElem(PList plist,int pos)//得到pos位置的元素的值
{
	assert(plist!=NULL);
	return plist->elem[pos-1];
}

int GetLength(PList plist)//得到顺序表的长度
{
		assert(plist!=NULL);
	return plist->usedsize;
}
void Clear(PList plist)//清楚顺序表
{
	assert(plist!=NULL);
	plist->usedsize = 0;
}
void Destory(PList plist)//销毁 //二倍扩容 堆上分配 手动摧毁
{
	Clear(plist);
	free(plist->elem);
	plist->elem=NULL;
	plist->length=0;
}
void Show(PList plist)
{
	assert(plist!=NULL);
	for(int i = 0;i<plist->usedsize;++i)
	{
		printf("%d\t",plist->elem[i]);
	}
	printf("\n");
}


int main()
{
	SXList plist;
    Initisite(&plist);
	for(int i =0;i<40;++i )
	{
		AddList(&plist,i,i);
	}
	DelVal(&plist,10,7);
	Show(&plist);
	getchar();
	return 0;
}


