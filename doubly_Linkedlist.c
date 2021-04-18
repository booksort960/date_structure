#include "doubly_Linkedlist.h"
void initlinkedlist(doulink* head)//��ʼ��˫������
{
	(*head).next = head;
	(*head).prev = head;
}
void LinkedlistFrontPush(doulink* head, lint n)//ͷ�巨
{
	doulink* newnode = (doulink*)malloc(sizeof(doulink));
	newnode->num = n;
	doulink*phead=(*head).next;//ԭͷ�ڵ� 
	newnode->next = phead;//�µĺ���ָ�������һ��
	(*head).next = newnode;//���ڱ������½��
	newnode->prev = head;//�½���ǰ��ָ��ָ���ڱ�
	phead->prev = newnode;//ԭͷ����ǰ��ָ��ָ���µ�ͷ�ڵ�
}
void LinkedlistBackpush(doulink* head, lint n)//β�巨
{
	doulink* newnode = (doulink*)malloc(sizeof(doulink));
	newnode->num = n;
	doulink* plast = (*head).prev;//�ҵ�β���
	newnode->prev = plast;//�µ�β����ԭβ���
	newnode->next = plast->next;//�½����ڱ�
	plast->next = newnode;//ԭβ���nextָ���µ�β
	(*head).prev = newnode;//ͷ�ڵ��prevָ���µ�β��㣬�γɱջ�
}
void LinkedlistFrontPop(doulink* head)//ͷɾ
{
	doulink* phead = (*head).next;
	doulink* second = phead->next;
	if (phead == head)
	{
		printf("Empty List\n");
		return;
	}
	second->prev = phead->prev;
	(*head).next = second;
}
void LinkedlistBackPop(doulink* head)//βɾ
{
	
	doulink* last = (*head).prev;//�ҵ�Ҫɾ����β���
	doulink* llast = last->prev;//�ҵ�ɾ������µ�β���
	if (last == head)
	{
		printf("Empty List\n");
		return;
	}
	(*head).prev = llast;//�ı��ڱ����prevָ��
	llast->next = last->next;//���µ�β����next�����ڱ�
	free(last);
}
void LinkedlistPrint(doulink* head)//��ӡ����
{
	doulink* cur = (*head).next;
	while (cur != head)
	{
		printf("%d ", cur->num);
		cur = cur->next;
	}
}
