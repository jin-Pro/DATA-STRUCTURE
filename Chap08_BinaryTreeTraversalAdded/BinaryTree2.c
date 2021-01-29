#include <stdio.h>
#include <stdlib.h>
#include "BinaryTree2.h"

BTreeNode* MakeBTreeNode(void)
{
	BTreeNode* newTreeNode = (BTreeNode*)malloc(sizeof(BTreeNode));	//새로운 노드 생성
	newTreeNode->left = NULL;											//왼쪽 노드 NULL초기화
	newTreeNode->right = NULL;											//오른쪽 노드 NULL초기화

	return newTreeNode;
}

BTData GetData(BTreeNode* bt)
{
	return bt->data;													//bt노드의 data 반환
}

void SetData(BTreeNode* bt, BTData data)
{
	bt->data = data;													//bt노드의 data 값 넣어주기
}

BTreeNode* GetLeftSubTree(BTreeNode* bt)
{
	return bt->left;													//bt노드의 Left SubTree 반환
}

BTreeNode* GetRightSubTree(BTreeNode* bt)
{
	return bt->right;													//bt노드의 Right SubTree 반환
}

void MakeLeftSubTree(BTreeNode* main, BTreeNode* sub)
{
	if (main->left != NULL)												//main의 LeftSubTree가 있다면
		free(main->left);												//지워주고

	main->left = sub;													//새로 넣어준다.
}

void MakeRightSubTree(BTreeNode* main, BTreeNode* sub)
{
	if (main->right != NULL)											//main의 RightSubTree가 있다면
		free(main->right);												//지워주고

	main->right = sub;													//새로 넣어준다.
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