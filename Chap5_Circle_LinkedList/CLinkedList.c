#include <stdio.h>
#include <stdlib.h>
#include "CLinkedList.h"

void ListInit(List * plist)
{
	plist->tail = NULL;
	plist->cur = NULL;
	plist->before = NULL;
	plist->numOfData = 0;
}

void LInsertFront(List * plist, Data data)
{														//�Ӹ��� ��� �߰��ϱ�
	Node * newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;

	if(plist->tail == NULL) 
	{													//������ ����ٸ� = ��尡 �ϳ��� ���ٸ�
		plist->tail = newNode;
		newNode->next = newNode;						//���� ���Ḯ��Ʈ�̱� ������ �ڱ��ڽ��� �����Ѿ���.
	}													//������ ��� �߰��ϱ�
	else
	{
		newNode->next = plist->tail->next;				//���ο� ���� head ��带 ����Ų��.
		plist->tail->next = newNode;					//������ ���ο� ��带 ����Ų��. == (���ο� ��� = ���) == ���ο��带 ���� ����� �ֱ�
	}													

	(plist->numOfData)++;
}

void LInsert(List * plist, Data data)
{														//������ ��� �߰��ϱ�
	Node * newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;

	if(plist->tail == NULL) 
	{													//������ ��尡 ���ٸ� == ��尡 �ϳ��� ���ٸ�
		plist->tail = newNode;
		newNode->next = newNode;						//���� ���Ḯ��Ʈ�̱� ������ �ڱ��ڽ��� �����Ѿ���.
	}													//������ ��� �߰��ϱ�
	else 
	{													//������ ��尡 �ִٸ� == ��尡 �ϳ� �̻� ����
		newNode->next = plist->tail->next;				//���ο� ���� tail�� next(==head)�� ����Ų��.
		plist->tail->next = newNode;					//������ ���ο� ��带 ����Ų��.
		plist->tail = newNode;							//������ ���ο� ��尡 �ȴ�.
	}

	(plist->numOfData)++;
}

int LFirst(List * plist, Data * pdata)
{
	if(plist->tail == NULL)    // ����� ��尡 ���ٸ�
		return FALSE;

	plist->before = plist->tail;						//before �� tail �� ��ü
	plist->cur = plist->tail->next;						//cur�� head�� �����Ѿ���.

	*pdata = plist->cur->data;
	return TRUE;
}

int LNext(List * plist, Data * pdata)
{														//���� ��� ��� �ݺ���.
	if(plist->tail == NULL)    // ����� ��尡 ���ٸ�
		return FALSE;

	plist->before = plist->cur;							//before��ĭ �̵�
	plist->cur = plist->cur->next;						//cur ��ĭ �̵�

	*pdata = plist->cur->data;
	return TRUE;
}

Data LRemove(List * plist)
{
	Node * rpos = plist->cur;
	Data rdata = rpos->data;

	if(rpos == plist->tail)    // ���� ����� tail�� ����Ų�ٸ�
	{
		if(plist->tail == plist->tail->next)    // �׸��� ������ ���� �����
			plist->tail = NULL;					//before�� ��� tail�� ����ų�� ����. ����, NULL�� ����Ų��.
		else
			plist->tail = plist->before;		//tail�� ����Ű�°� �־����.
	}

	plist->before->next = plist->cur->next;
	plist->cur = plist->before;

	free(rpos);
	(plist->numOfData)--;
	return rdata;
}

int LCount(List * plist)
{
	return plist->numOfData;
}