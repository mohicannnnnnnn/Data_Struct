
#include<stdio.h>
typedef struct SXList
{
	int *elem; //ָ��
	int usedsize; //��ЧԪ�ظ���
	int length; //�ܳ���
}SXList,*PList;

//��ʼ��˳���
void Initisite(PList  plist );
bool AddList(PList plist,int pos ,int value); //��posλ����һ�� value
bool DelList(PList plist,int pos, int *value ); //ɾ��posλ�õ�һ��value����ɾ������value����
bool Search(PList plist,int pos,int value);//��Posλ��ʼ����һ��valueֵ�������������pos
bool DelVal(PList plist ,int pos,int value);// ɾ��ָ��Valueֵ,��posλ��ʼ�ĵ�һ��
int GetElem(PList plist,int pos);//�õ�posλ�õ�Ԫ�ص�ֵ
int GetLength(PList PList);//�õ�˳���ĳ���
void Clear(PList plist);//���˳���
void Destory(PList plist);//���� //�������� ���Ϸ��� �ֶ��ݻ�
void Show(PList plist);