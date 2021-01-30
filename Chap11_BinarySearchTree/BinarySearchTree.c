#include <stdio.h>
#include "BinaryTree2.h"
#include "BinarySearchTree.h"

void BSTMakeAndInit(BTreeNode ** pRoot)
{
	*pRoot = NULL;
}

BSTData BSTGetNodeData(BTreeNode * bst)
{
	return GetData(bst);
}

void BSTInsert(BTreeNode ** pRoot, BSTData data)
{	
	BTreeNode* pNode = NULL;
	BTreeNode* cNode = *pRoot;
	BTreeNode* nNode = NULL;

	while (cNode != NULL)
	{//비어있는 자식노드 찾기, 그때의 부모노드 = pNode
		if (data == GetData(cNode))
			return;

		pNode = cNode;	//부모노드 정의

		if (GetData(cNode) > data)
			cNode = GetLeftSubTree(cNode);		//자식노드 정의
		else
			cNode = GetRightSubTree(cNode);
	}

	nNode = MakeBTreeNode();	//새로운 노드 만들기
	SetData(nNode, data);		//새로운 노드에 데이터 값 넣기

	if (pNode != NULL)
	{
		if (data < GetData(pNode))	//부모 노드의 데이터값보다 작다면
			MakeLeftSubTree(pNode, nNode);	//부모 노드의 왼쪽자식노드로 추가하기
		else
			MakeRightSubTree(pNode, nNode);
	}
	else
		*pRoot = nNode;
}


BTreeNode * BSTSearch(BTreeNode * bst, BSTData target)
{
	BTreeNode* cNode = bst;
	BSTData cd;

	while (cNode != NULL)
	{
		cd = GetData(cNode);

		if (target == cd)
			return cNode;
		else if (target < cd)
			cNode = GetLeftSubTree(cNode);
		else
			cNode = GetRightSubTree(cNode);
	}
	return NULL;
}