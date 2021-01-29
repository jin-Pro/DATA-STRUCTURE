#include <stdio.h>
#include <stdlib.h>
#include "CircularQueue.h"

void QueueInit(Queue * pq)
{
	pq->front = 0;		//초기화 진행될때, front와 rear이 0으로 시작하여야
	pq->rear = 0;		//데이터가 꽉찼는지, 비었는지 구분 가능
}						//처음 데이터 추가할때 1번 index에 데이터 추가, 따라서 0번 index는 사용X

int QIsEmpty(Queue * pq)
{
	if(pq->front == pq->rear)	//front와 rear이 같으면 비었다.
		return TRUE;
	else
		return FALSE;
}

int NextPosIdx(int pos)
{
	if(pos == QUE_LEN-1)		//pos값이 99(QUE_LEN-1)이라면 꽉차서 0번index로 보낸다.
		return 0;
	else
		return pos+1;
}

void Enqueue(Queue * pq, Data data)
{
	if(NextPosIdx(pq->rear) == pq->front)	//front가 0이고, rear이 99라면	NextPosIdx의 반환값은 0임으로
	{										//front 와 값이 같아진다. 따라서, 데이터가 꽉참을 알 수 있다.
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