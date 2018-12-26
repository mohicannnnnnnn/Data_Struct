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

bool AddList(PList plist,int pos ,int value) //��posλ����һ�� value
{
	assert(plist!=NULL);
	if(IsFull(plist))
	{
		Resize(plist);
	}
	if(pos<0 || pos>plist->usedsize)  //˳����������洢��
	{
		return false;
	}
	//�Ӻ���ǰŲ
	for(int i =plist->usedsize;i>pos ;--i)
	{
		plist->elem[i] = plist->elem[i-1];
	}
	plist->elem[pos] = value;
	plist->usedsize++;
	return true;
}
bool DelList(PList plist,int pos, int value )//ɾ��posλ�õ�һ��value����ɾ������value����
{
	assert(plist!=NULL);
	if(pos<0 || pos>plist->usedsize)
	{
		return false;
	}
	value = plist->elem[pos]; 
	//printf("��%dλ�õ�Ԫ�� %d�Ѿ�ɾ��\n",pos+1,value);
	for(int i =pos;i<plist->usedsize;++i)
	{
		plist->elem[i-1] = plist->elem[i];
	}
	plist->usedsize--;
	return true;
}
bool Search(PList plist,int pos,int value)//��Posλ��ʼ����һ��valueֵ�������������pos
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
			printf("��%d��λ���ҵ�\n",i+1);
			return true;
		}
	}
	return false;

}
bool DelVal(PList plist ,int pos,int value)// ɾ��ָ��Valueֵ,��posλ��ʼ�ĵ�һ��
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

int GetElem(PList plist,int pos)//�õ�posλ�õ�Ԫ�ص�ֵ
{
	assert(plist!=NULL);
	return plist->elem[pos-1];
}

int GetLength(PList plist)//�õ�˳���ĳ���
{
		assert(plist!=NULL);
	return plist->usedsize;
}
void Clear(PList plist)//���˳���
{
	assert(plist!=NULL);
	plist->usedsize = 0;
}
void Destory(PList plist)//���� //�������� ���Ϸ��� �ֶ��ݻ�
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


