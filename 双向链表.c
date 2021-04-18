#include "doubly_Linkedlist.h"
void doublelinkedlist1()
{
	doulink head;
	initlinkedlist(&head);//初始化双向链表
	LinkedlistFrontPush(&head, 1);//头插法
	LinkedlistFrontPush(&head, 2);//头插法
	LinkedlistFrontPush(&head, 3);//头插法
	LinkedlistFrontPush(&head, 4);//头插法
	LinkedlistFrontPush(&head, 5);//头插法
	LinkedlistBackpush(&head, 6);//尾插法
	LinkedlistBackpush(&head, 7);//尾插法
	LinkedlistBackpush(&head, 8);//尾插法
	LinkedlistBackpush(&head, 9);//尾插法
	LinkedlistBackpush(&head, 10);//尾插法
	
	LinkedlistFrontPop(&head);//头删
	LinkedlistFrontPop(&head);//头删
	LinkedlistFrontPop(&head);//头删
	LinkedlistBackPop(&head);//尾删
	LinkedlistBackPop(&head);//尾删
	LinkedlistBackPop(&head);//尾删
	LinkedlistBackPop(&head);//尾删
	LinkedlistBackPop(&head);//尾删

	

	LinkedlistPrint(&head);//打印链表

	
}
int main(void)
{
	doublelinkedlist1();
}