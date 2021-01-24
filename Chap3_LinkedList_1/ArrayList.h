#ifndef __ARRAY_LIST_H__
#define __ARRAY_LIST_H__

#define TRUE	1
#define FALSE	0

/*** ArrayList�� ���� ****/
#define LIST_LEN	100						// list�� ����
typedef int LData;							// list�� data���� LData�� ǥ��

typedef struct __ArrayList
{//ArrayList ���� ����
	LData arr[LIST_LEN];					// int arr[100]
	int numOfData;							// list�ȿ� �ִ� data�� ��
	int curPosition;						// list���� ���� ����Ű�� �ִ� �ε���
} ArrayList;


/*** ArrayList�� ���õ� ����� ****/
typedef ArrayList List;						//ArrayList�� List��� �Ұ�

void ListInit(List * plist);				//List �ʱ�ȭ�ϱ�  numOfData = 0, curPosition = -1 
void LInsert(List * plist, LData data);		//List�� data�� �ֱ�, numOfData ++, List.arr[numOfData] = data,

int LFirst(List * plist, LData * pdata);	//pdata�� List.arr[0]�� �־��ֱ�
int LNext(List * plist, LData * pdata);		//pdata�� List.arr+i �� �־��ֱ�

LData LRemove(List * plist);				//List���� ���� ����Ű�� �ִ� data�����ֱ�
int LCount(List * plist);					//List�� numOfData�� ��Ÿ����

#endif