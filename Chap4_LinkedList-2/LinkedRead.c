#include <stdio.h>
#include <stdlib.h>

typedef struct _node
{
	int data;									//데이터값
	struct _node * next;						//연결할 다음 노드
} Node;

int main(void)
{
	Node * head = NULL;    // NULL 포인터 초기화
	Node * tail = NULL;
	Node * cur = NULL;

	Node * newNode = NULL;
	int readData;

	/**** 데이터를 입력 받는 과정 ****/
	while(1)
	{
		printf("자연수 입력: ");
		scanf("%d", &readData);
		if(readData < 1)
			break;								//음수를 입력하면 끝내겠다.

		/*** 노드의 추가과정 ***/
		newNode = (Node*)malloc(sizeof(Node));	//Node구조체 크기만큼 메모리를 할당해줄게
		newNode->data = readData;				//newNode의 data는 readData 너가 입력한 숫자야
		newNode->next = NULL;					//newNode에 다음 연결할 노드는 없어,,

		if(head == NULL)						//head Node가 NULL이라면
			head = newNode;						//head는 newNode가 될거야
		else
			tail->next = newNode;				//head Node가 있다면 꼬리(마지막노드)의 다음은 newNode가 될거야.
												//오잉? 꼬리 노드의 다음이 헤드(처음노드)노드라면 꼬리물기네??
		tail = newNode;							//꼬리 노드는 newNode야  
												//그러면 다음에 만들어질 노드는 이전에 만든 Node의 next node가 되겠고, 지금 만들어진 Node는 꼬리Node가 되겠네!
	}
	printf("\n");

	/**** 입력 받은 데이터의 출력과정 ****/
	printf("입력 받은 데이터의 전체출력! \n");
	if(head == NULL) 
	{
		printf("저장된 자연수가 존재하지 않습니다. \n");
	}
	else 
	{
		cur = head;								//내가 현재 가리키고있는 위치를 head로 가리킬게!
		printf("%d  ", cur->data);   // 첫 번째 데이터 출력
		
		while(cur->next != NULL)    // 두 번째 이후의 데이터 출력 && Next Node가 없을때까지 출력할게
		{
			cur = cur->next;					//출력했으면 다음 Node를 가리킬게!
			printf("%d  ", cur->data);
		}
	}
	printf("\n\n");

	/**** 메모리의 해제과정 ****/
	if(head == NULL) 
	{
		return 0;    // 해제할 노드가 존재하지 않는다.
	}
	else 
	{
		Node * delNode = head;								//지울 노드 생성
		Node * delNextNode = head->next;					//지울 노드 다음 노드 생성

		printf("%d을(를) 삭제합니다. \n", head->data);
		free(delNode);    // 첫 번째 노드의 삭제
		
		while(delNextNode != NULL)    // 두 번째 이후의 노드 삭제 위한 반복문 && Next Node가 없을때 까지 지울게!
		{
			delNode = delNextNode;							//지울 노드는 다음노드야~ 즉, 다음노드도 지울거야!		
			delNextNode = delNextNode->next;				//다음 노드는 그 다음노드야~!

			printf("%d을(를) 삭제합니다. \n", delNode->data);	
			free(delNode);    // 두 번째 이후의 노드 삭제
		}
	}

	return 0;
}