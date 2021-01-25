#include <stdio.h>
#include <stdlib.h>

typedef struct _node
{
	int data;									//�����Ͱ�
	struct _node * next;						//������ ���� ���
} Node;

int main(void)
{
	Node * head = NULL;    // NULL ������ �ʱ�ȭ
	Node * tail = NULL;
	Node * cur = NULL;

	Node * newNode = NULL;
	int readData;

	/**** �����͸� �Է� �޴� ���� ****/
	while(1)
	{
		printf("�ڿ��� �Է�: ");
		scanf("%d", &readData);
		if(readData < 1)
			break;								//������ �Է��ϸ� �����ڴ�.

		/*** ����� �߰����� ***/
		newNode = (Node*)malloc(sizeof(Node));	//Node����ü ũ�⸸ŭ �޸𸮸� �Ҵ����ٰ�
		newNode->data = readData;				//newNode�� data�� readData �ʰ� �Է��� ���ھ�
		newNode->next = NULL;					//newNode�� ���� ������ ���� ����,,

		if(head == NULL)						//head Node�� NULL�̶��
			head = newNode;						//head�� newNode�� �ɰž�
		else
			tail->next = newNode;				//head Node�� �ִٸ� ����(���������)�� ������ newNode�� �ɰž�.
												//����? ���� ����� ������ ���(ó�����)����� ���������??
		tail = newNode;							//���� ���� newNode��  
												//�׷��� ������ ������� ���� ������ ���� Node�� next node�� �ǰڰ�, ���� ������� Node�� ����Node�� �ǰڳ�!
	}
	printf("\n");

	/**** �Է� ���� �������� ��°��� ****/
	printf("�Է� ���� �������� ��ü���! \n");
	if(head == NULL) 
	{
		printf("����� �ڿ����� �������� �ʽ��ϴ�. \n");
	}
	else 
	{
		cur = head;								//���� ���� ����Ű���ִ� ��ġ�� head�� ����ų��!
		printf("%d  ", cur->data);   // ù ��° ������ ���
		
		while(cur->next != NULL)    // �� ��° ������ ������ ��� && Next Node�� ���������� ����Ұ�
		{
			cur = cur->next;					//��������� ���� Node�� ����ų��!
			printf("%d  ", cur->data);
		}
	}
	printf("\n\n");

	/**** �޸��� �������� ****/
	if(head == NULL) 
	{
		return 0;    // ������ ��尡 �������� �ʴ´�.
	}
	else 
	{
		Node * delNode = head;								//���� ��� ����
		Node * delNextNode = head->next;					//���� ��� ���� ��� ����

		printf("%d��(��) �����մϴ�. \n", head->data);
		free(delNode);    // ù ��° ����� ����
		
		while(delNextNode != NULL)    // �� ��° ������ ��� ���� ���� �ݺ��� && Next Node�� ������ ���� �����!
		{
			delNode = delNextNode;							//���� ���� ��������~ ��, ������嵵 ����ž�!		
			delNextNode = delNextNode->next;				//���� ���� �� ��������~!

			printf("%d��(��) �����մϴ�. \n", delNode->data);	
			free(delNode);    // �� ��° ������ ��� ����
		}
	}

	return 0;
}