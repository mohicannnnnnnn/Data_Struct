
#include<stdio.h>
typedef struct SXList
{
	int *elem; //指针
	int usedsize; //有效元素个数
	int length; //总长度
}SXList,*PList;

//初始化顺序表
void Initisite(PList  plist );
bool AddList(PList plist,int pos ,int value); //在pos位插入一个 value
bool DelList(PList plist,int pos, int *value ); //删除pos位置的一个value，把删除掉的value保存
bool Search(PList plist,int pos,int value);//从Pos位开始查找一个value值，并将结果返回pos
bool DelVal(PList plist ,int pos,int value);// 删除指定Value值,从pos位开始的第一个
int GetElem(PList plist,int pos);//得到pos位置的元素的值
int GetLength(PList PList);//得到顺序表的长度
void Clear(PList plist);//清楚顺序表
void Destory(PList plist);//销毁 //二倍扩容 堆上分配 手动摧毁
void Show(PList plist);