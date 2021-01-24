#ifndef __ARRAY_LIST_H__
#define __ARRAY_LIST_H__

#define TRUE	1
#define FALSE	0

/*** ArrayList의 정의 ****/
#define LIST_LEN	100						// list의 길이
typedef int LData;							// list의 data값을 LData로 표현

typedef struct __ArrayList
{//ArrayList 내부 사항
	LData arr[LIST_LEN];					// int arr[100]
	int numOfData;							// list안에 있는 data의 수
	int curPosition;						// list에서 지금 가리키고 있는 인덱스
} ArrayList;


/*** ArrayList와 관련된 연산들 ****/
typedef ArrayList List;						//ArrayList를 List라고 할게

void ListInit(List * plist);				//List 초기화하기  numOfData = 0, curPosition = -1 
void LInsert(List * plist, LData data);		//List에 data값 넣기, numOfData ++, List.arr[numOfData] = data,

int LFirst(List * plist, LData * pdata);	//pdata에 List.arr[0]값 넣어주기
int LNext(List * plist, LData * pdata);		//pdata에 List.arr+i 값 넣어주기

LData LRemove(List * plist);				//List에서 현재 가리키고 있는 data지워주기
int LCount(List * plist);					//List의 numOfData값 나타내기

#endif