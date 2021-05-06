#include <stdio.h>
typedef char BTData;
typedef struct BinaryTree
{
	struct BinaryTree* left;
	struct BinaryTree* right;
	BTData n;
}BTType;
BTType* BinaryTreeCreat(BTData x)
{
	BTType* node = (BTType*)malloc(sizeof(BTType));
	node->n = x;
	return node;
}
void PosOrder(BTType* root)
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}
	PosOrder(root->left);
	PosOrder(root->right);
	printf("%c ", root->n);
}
void MidOrder(BTType* root)
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}
	MidOrder(root->left);
	printf("%c ", root->n);
	MidOrder(root->right);

}
void PreOrder(BTType* root)
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}
	printf("%c ", root->n);
	PreOrder(root->left);
	PreOrder(root->right);
}

int main(void)
{
	BTType* nodea = BinaryTreeCreat('a');
	BTType* nodeb = BinaryTreeCreat('b');
	BTType* nodec = BinaryTreeCreat('c');
	BTType* noded = BinaryTreeCreat('d');
	BTType* nodee = BinaryTreeCreat('e');
	BTType* nodef = BinaryTreeCreat('f');
	BTType* nodeg = BinaryTreeCreat('g');
	BTType* nodeh = BinaryTreeCreat('h');
	nodea->left = nodeb;
	nodea->right = nodec;

	nodeb->left = noded;
	nodeb->right = NULL;
	nodec->left = nodee;
	nodec->right = nodef;

	noded->left = noded->right = NULL;
	nodee->left = nodee->right = NULL;
	nodef->left = nodef->right = NULL;

	PosOrder(nodea);

}