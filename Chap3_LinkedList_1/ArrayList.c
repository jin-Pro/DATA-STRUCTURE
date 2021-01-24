#include <stdio.h>
#include "ArrayList.h"

void ListInit(List* plist)							//List �ʱ�ȭ
{
	(plist->numOfData) = 0;							//Data�� ���� 0
	(plist->curPosition) = -1;						//���� ����Ű�� ��ġ �����Ƿ� -1
}

void LInsert(List* plist, LData data)
{
	if (plist->numOfData > LIST_LEN)					//List���� Data�� ���� LIST_LEN(100)���� ũ�ٸ� �����÷� �߻�
	{
		puts("������ �Ұ����մϴ�.");
		return;
	}

	plist->arr[plist->numOfData] = data;			//�װ� �ƴ϶��, data�� �ִ´�.
	(plist->numOfData)++;							//numOfData = ���� Data�� �� = ���� Data�� ���� �ε�����ȣ
}

int LFirst(List* plist, LData* pdata)
{
	if (plist->numOfData == 0)						//List�� Data�� �ϳ��� ���ٸ�
		return FALSE;								//FALSE

	(plist->curPosition) = 0;						//�װԾƴ϶�� (= List�� Data�� �ϳ��� �ִ�.)
	*pdata = plist->arr[0];							//pdata�� arr[0] (ù��°���� ����) �� �ִ� data�� �־��ش�.
	return TRUE;
}

int LNext(List* plist, LData* pdata)
{
	if (plist->curPosition >= (plist->numOfData) - 1)	//List�� �� data�� �� = numOfData, ������ Data�� ����Ű�� index = numOfData-1
		return FALSE;								//������ index�� ����Ű���־ FALSE�� ���� = ������ ����.

	(plist->curPosition)++;							//�������� �̵�����.
	*pdata = plist->arr[plist->curPosition];		//pdata�� ���� ����Ű��(curPosition) arr[index] �� ��Ÿ���� data�� �־��ٰ�
	return TRUE;
}

LData LRemove(List* plist)
{
	int rpos = plist->curPosition;					//rpos = ���� ���� ����Ű�°�
	int num = plist->numOfData;						//num = List�� �����ϴ� �� �������� ��
	int i;
	LData rdata = plist->arr[rpos];					//rdata = ���� ������ = ���� ����Ű���ִ� �ε����� ������

	for (i = rpos; i < num - 1; i++)						//���� ����Ű�� �ִ� ������ ������-1������ �ε�����
		plist->arr[i] = plist->arr[i + 1];			//��ĭ �տ��ִ� data�� ���沨��
													//�ֳĸ� �� ������ �ְŵ�
	(plist->numOfData)--;							//data�� �ϳ� ���������� numOfData 1����
	(plist->curPosition)--;							//���� ����Ű���ִ� index�� ���� ���� ���� ����ִ� index�̴�. ���� -1 ���־���Ѵ�.
	return rdata;
}

int LCount(List* plist)
{
	return plist->numOfData;
}