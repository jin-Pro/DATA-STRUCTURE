#include <stdio.h>
#include "ArrayList.h"

void ListInit(List* plist)							//List 초기화
{
	(plist->numOfData) = 0;							//Data의 수는 0
	(plist->curPosition) = -1;						//현재 가르키는 위치 없으므로 -1
}

void LInsert(List* plist, LData data)
{
	if (plist->numOfData > LIST_LEN)					//List안의 Data의 수가 LIST_LEN(100)보다 크다면 오버플로 발생
	{
		puts("저장이 불가능합니다.");
		return;
	}

	plist->arr[plist->numOfData] = data;			//그게 아니라면, data를 넣는다.
	(plist->numOfData)++;							//numOfData = 현재 Data의 수 = 다음 Data를 넣을 인덱스번호
}

int LFirst(List* plist, LData* pdata)
{
	if (plist->numOfData == 0)						//List에 Data가 하나도 없다면
		return FALSE;								//FALSE

	(plist->curPosition) = 0;						//그게아니라면 (= List에 Data가 하나라도 있다.)
	*pdata = plist->arr[0];							//pdata에 arr[0] (첫번째임을 강조) 에 있는 data를 넣어준다.
	return TRUE;
}

int LNext(List* plist, LData* pdata)
{
	if (plist->curPosition >= (plist->numOfData) - 1)	//List의 총 data의 수 = numOfData, 마지막 Data를 가르키는 index = numOfData-1
		return FALSE;								//마지막 index를 가리키고있어도 FALSE인 이유 = 다음이 없다.

	(plist->curPosition)++;							//다음으로 이동하자.
	*pdata = plist->arr[plist->curPosition];		//pdata에 내가 가리키는(curPosition) arr[index] 가 나타내는 data를 넣어줄게
	return TRUE;
}

LData LRemove(List* plist)
{
	int rpos = plist->curPosition;					//rpos = 내가 지금 가리키는곳
	int num = plist->numOfData;						//num = List에 존재하는 총 데이터의 수
	int i;
	LData rdata = plist->arr[rpos];					//rdata = 지울 데이터 = 내가 가리키고있는 인덱스의 데이터

	for (i = rpos; i < num - 1; i++)						//내가 가리키고 있는 곳부터 마지막-1번까지 인덱스에
		plist->arr[i] = plist->arr[i + 1];			//한칸 앞에있는 data들 땡길꺼야
													//왜냐면 빈 공간이 있거든
	(plist->numOfData)--;							//data를 하나 지웠음으로 numOfData 1감소
	(plist->curPosition)--;							//내가 가리키고있는 index는 새로 들어온 값이 들어있는 index이다. 따라서 -1 해주어야한다.
	return rdata;
}

int LCount(List* plist)
{
	return plist->numOfData;
}