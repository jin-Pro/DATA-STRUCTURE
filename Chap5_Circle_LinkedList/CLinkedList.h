#ifndef __C_LINKED_LIST_H__
#define __C_LINKED_LIST_H__

#define TRUE	1
#define FALSE	0

typedef int Data;

typedef struct _node
{
	Data data;
	struct _node * next;
} Node;

typedef struct _CLL
{
	Node * tail;
	Node * cur;
	Node * before;
	int numOfData;
} CList;


typedef CList List;

void ListInit(List * plist);					//노드 초기화
void LInsert(List * plist, Data data);			//노드를 꼬리에 추가
void LInsertFront(List * plist, Data data);		//노드를 머리에 추가

int LFirst(List * plist, Data * pdata);			//첫번째 노드 데이터 값 지정
int LNext(List * plist, Data * pdata);			//다음 노드 데이터 값 지정
Data LRemove(List * plist);						//노드 삭제
int LCount(List * plist);				

#endif