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
{														//머리에 노드 추가하기
	Node * newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;

	if(plist->tail == NULL) 
	{													//꼬리가 비었다면 = 노드가 하나도 없다면
		plist->tail = newNode;
		newNode->next = newNode;						//원형 연결리스트이기 때문에 자기자신을 가리켜야함.
	}													//꼬리에 노드 추가하기
	else
	{
		newNode->next = plist->tail->next;				//새로운 노드는 head 노드를 가리킨다.
		plist->tail->next = newNode;					//꼬리는 새로운 노드를 가리킨다. == (새로운 노드 = 헤드) == 새로운노드를 원형 연결로 넣기
	}													

	(plist->numOfData)++;
}

void LInsert(List * plist, Data data)
{														//꼬리에 노드 추가하기
	Node * newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;

	if(plist->tail == NULL) 
	{													//꼬리에 노드가 없다면 == 노드가 하나도 없다면
		plist->tail = newNode;
		newNode->next = newNode;						//원형 연결리스트이기 때문에 자기자신을 가리켜야함.
	}													//꼬리에 노드 추가하기
	else 
	{													//꼬리에 노드가 있다면 == 노드가 하나 이상 존재
		newNode->next = plist->tail->next;				//새로운 노드는 tail의 next(==head)를 가리킨다.
		plist->tail->next = newNode;					//꼬리는 새로운 노드를 가리킨다.
		plist->tail = newNode;							//꼬리는 새로운 노드가 된다.
	}

	(plist->numOfData)++;
}

int LFirst(List * plist, Data * pdata)
{
	if(plist->tail == NULL)    // 저장된 노드가 없다면
		return FALSE;

	plist->before = plist->tail;						//before 는 tail 그 자체
	plist->cur = plist->tail->next;						//cur은 head를 가리켜야함.

	*pdata = plist->cur->data;
	return TRUE;
}

int LNext(List * plist, Data * pdata)
{														//끝이 없어서 계속 반복됨.
	if(plist->tail == NULL)    // 저장된 노드가 없다면
		return FALSE;

	plist->before = plist->cur;							//before한칸 이동
	plist->cur = plist->cur->next;						//cur 한칸 이동

	*pdata = plist->cur->data;
	return TRUE;
}

Data LRemove(List * plist)
{
	Node * rpos = plist->cur;
	Data rdata = rpos->data;

	if(rpos == plist->tail)    // 삭제 대상을 tail이 가리킨다면
	{
		if(plist->tail == plist->tail->next)    // 그리고 마지막 남은 노드라면
			plist->tail = NULL;					//before가 없어서 tail이 가리킬게 없다. 따라서, NULL을 가리킨다.
		else
			plist->tail = plist->before;		//tail이 가리키는게 있어야함.
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