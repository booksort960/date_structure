#include "linkedlist.h"
void test()
{
	list* head;
	list* last;
	initLinkedlist(&head,&last);
	pushlast(&last, 1);//β�巨
	pushlast(&last, 2);
	pushlast(&last, 3);
	pushlast(&last, 4);
	pushfront(&head, 5);//ͷ�巨
	pushfront(&head, 8);//ͷ�巨
	pushfront(&head, 7);//ͷ�巨
	pushfront(&head, 6);//ͷ�巨
	popchoice(&head, 0);//����λ��ɾ��
	//poshposition(&head, 3);//����λ�ò���
	printlist(&head);//��ӡ
}
int main(void)
{
	test();
	return 0;
}