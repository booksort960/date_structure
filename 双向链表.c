#include "doubly_Linkedlist.h"
void doublelinkedlist1()
{
	doulink head;
	initlinkedlist(&head);//��ʼ��˫������
	LinkedlistFrontPush(&head, 1);//ͷ�巨
	LinkedlistFrontPush(&head, 2);//ͷ�巨
	LinkedlistFrontPush(&head, 3);//ͷ�巨
	LinkedlistFrontPush(&head, 4);//ͷ�巨
	LinkedlistFrontPush(&head, 5);//ͷ�巨
	LinkedlistBackpush(&head, 6);//β�巨
	LinkedlistBackpush(&head, 7);//β�巨
	LinkedlistBackpush(&head, 8);//β�巨
	LinkedlistBackpush(&head, 9);//β�巨
	LinkedlistBackpush(&head, 10);//β�巨
	
	LinkedlistFrontPop(&head);//ͷɾ
	LinkedlistFrontPop(&head);//ͷɾ
	LinkedlistFrontPop(&head);//ͷɾ
	LinkedlistBackPop(&head);//βɾ
	LinkedlistBackPop(&head);//βɾ
	LinkedlistBackPop(&head);//βɾ
	LinkedlistBackPop(&head);//βɾ
	LinkedlistBackPop(&head);//βɾ

	

	LinkedlistPrint(&head);//��ӡ����

	
}
int main(void)
{
	doublelinkedlist1();
}