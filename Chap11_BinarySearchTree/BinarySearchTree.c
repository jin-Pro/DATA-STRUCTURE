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
	{//����ִ� �ڽĳ�� ã��, �׶��� �θ��� = pNode
		if (data == GetData(cNode))
			return;

		pNode = cNode;	//�θ��� ����

		if (GetData(cNode) > data)
			cNode = GetLeftSubTree(cNode);		//�ڽĳ�� ����
		else
			cNode = GetRightSubTree(cNode);
	}

	nNode = MakeBTreeNode();	//���ο� ��� �����
	SetData(nNode, data);		//���ο� ��忡 ������ �� �ֱ�

	if (pNode != NULL)
	{
		if (data < GetData(pNode))	//�θ� ����� �����Ͱ����� �۴ٸ�
			MakeLeftSubTree(pNode, nNode);	//�θ� ����� �����ڽĳ��� �߰��ϱ�
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