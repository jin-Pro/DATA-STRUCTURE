#include <stdio.h>
#include <stdlib.h>
#include "BinaryTree2.h"

BTreeNode* MakeBTreeNode(void)
{
	BTreeNode* newTreeNode = (BTreeNode*)malloc(sizeof(BTreeNode));	//���ο� ��� ����
	newTreeNode->left = NULL;											//���� ��� NULL�ʱ�ȭ
	newTreeNode->right = NULL;											//������ ��� NULL�ʱ�ȭ

	return newTreeNode;
}

BTData GetData(BTreeNode* bt)
{
	return bt->data;													//bt����� data ��ȯ
}

void SetData(BTreeNode* bt, BTData data)
{
	bt->data = data;													//bt����� data �� �־��ֱ�
}

BTreeNode* GetLeftSubTree(BTreeNode* bt)
{
	return bt->left;													//bt����� Left SubTree ��ȯ
}

BTreeNode* GetRightSubTree(BTreeNode* bt)
{
	return bt->right;													//bt����� Right SubTree ��ȯ
}

void MakeLeftSubTree(BTreeNode* main, BTreeNode* sub)
{
	if (main->left != NULL)												//main�� LeftSubTree�� �ִٸ�
		free(main->left);												//�����ְ�

	main->left = sub;													//���� �־��ش�.
}

void MakeRightSubTree(BTreeNode* main, BTreeNode* sub)
{
	if (main->right != NULL)											//main�� RightSubTree�� �ִٸ�
		free(main->right);												//�����ְ�

	main->right = sub;													//���� �־��ش�.
}


void PreorderTraverse(BTreeNode* bt, VisitFuncPtr action)
{
	if (bt == NULL)
		return;

	action(bt->data);
	PreorderTraverse(bt->left, action);
	PreorderTraverse(bt->right, action);
}

void InorderTraverse(BTreeNode* bt, VisitFuncPtr action)
{
	if (bt == NULL)
		return;

	InorderTraverse(bt->left, action);
	action(bt->data);
	InorderTraverse(bt->right, action);
}

void PostorderTraverse(BTreeNode* bt, VisitFuncPtr action)
{
	if (bt == NULL)
		return;

	PostorderTraverse(bt->left, action);
	PostorderTraverse(bt->right, action);
	action(bt->data);
}