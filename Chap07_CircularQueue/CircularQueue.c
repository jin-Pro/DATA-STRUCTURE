#include <stdio.h>
#include <stdlib.h>
#include "CircularQueue.h"

void QueueInit(Queue * pq)
{
	pq->front = 0;		//�ʱ�ȭ ����ɶ�, front�� rear�� 0���� �����Ͽ���
	pq->rear = 0;		//�����Ͱ� ��á����, ������� ���� ����
}						//ó�� ������ �߰��Ҷ� 1�� index�� ������ �߰�, ���� 0�� index�� ���X

int QIsEmpty(Queue * pq)
{
	if(pq->front == pq->rear)	//front�� rear�� ������ �����.
		return TRUE;
	else
		return FALSE;
}

int NextPosIdx(int pos)
{
	if(pos == QUE_LEN-1)		//pos���� 99(QUE_LEN-1)�̶�� ������ 0��index�� ������.
		return 0;
	else
		return pos+1;
}

void Enqueue(Queue * pq, Data data)
{
	if(NextPosIdx(pq->rear) == pq->front)	//front�� 0�̰�, rear�� 99���	NextPosIdx�� ��ȯ���� 0������
	{										//front �� ���� ��������. ����, �����Ͱ� ������ �� �� �ִ�.
		printf("Queue Memory Error!");
		exit(-1);
	}

	pq->rear = NextPosIdx(pq->rear);
	pq->queArr[pq->rear] = data;
}

Data Dequeue(Queue * pq)
{
	if(QIsEmpty(pq))
	{
		printf("Queue Memory Error!");
		exit(-1);
	}

	pq->front = NextPosIdx(pq->front);
	return pq->queArr[pq->front];
}

Data QPeek(Queue * pq)
{
	if(QIsEmpty(pq))
	{
		printf("Queue Memory Error!");
		exit(-1);
	}

	return pq->queArr[NextPosIdx(pq->front)];
}