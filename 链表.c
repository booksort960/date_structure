#include "linkedlist.h"
void test()
{
	list* head;
	list* last;
	initLinkedlist(&head,&last);
	pushlast(&last, 1);//尾插法
	pushlast(&last, 2);
	pushlast(&last, 3);
	pushlast(&last, 4);
	pushfront(&head, 5);//头插法
	pushfront(&head, 8);//头插法
	pushfront(&head, 7);//头插法
	pushfront(&head, 6);//头插法
	popchoice(&head, 0);//任意位置删除
	//poshposition(&head, 3);//任意位置插入
	printlist(&head);//打印
}
int main(void)
{
	test();
	return 0;
}