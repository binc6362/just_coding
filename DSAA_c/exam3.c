/*
*********************************************************************************************************
*Author       : bin.c 
*Last modified: 2023-12-16 22:03
*Email        : cb99986174@163.com
*Filename     : exam3.c
*Description  : 
* 编写一个程序，要求:从终端输入一组整数（大于10个数），以0作为结束标志，
* 将这一组整数存放在一个链表中（结束标志0不包括在内），打印出该链表中的值。
* 然后删除该链表中的第5个元素，打印出删除后的结果。最后在内存中释放掉该链表。
*********************************************************************************************************
*/
#include <stdio.h>
#include <stdlib.h>

//define linklist
typedef struct Node {
	int data;
	struct Node *next;
} Lnode, *linklist; 

void print(linklist);
void delete(linklist *, int);
void destory(linklist *);

int main(void)
{
	int n,flag = 0,count = 0;
	linklist r,list = NULL;
	Lnode *p;
	//1.get a serials of integers(numbers > 10) from stdin,0 is the end flag.	
	printf("please enter more than 10 integers:");
	while(scanf("%d", &n) && (n != flag)) {
	//2.store elem into linklist
		p = (Lnode *)malloc(sizeof(Lnode));	
		p->data = n;
		p->next = NULL;
		if (!list)
			list = p;
		else
			r->next = p;
		r = p;
	}
	//3.print linklist
	print(list);
	//4.delete no.5 element
	delete(&list, 5);
	//5.print linklist
	print(list);
	//6.destory linklist
	return 0;
}

void print(linklist l)
{
	linklist p = l;
	while(p->next != NULL) {
		printf("%d\n",p->data);
		p = p->next;
	}
	printf("%d\n",p->data);
}

void delete(linklist *l, int n)
{
	linklist tmp,p = *l;
	if (n == 1)
		*l = p->next;
	for (int i = 1; i < n - 1; i++)
		p = p->next;
	tmp = p->next->next;
	free(p->next);
	p->next = tmp;
}

void destory(linklist *l)
{
	Lnode *p, *q;
	p = *l;
	while (p) {
		q = p->next;
		free(p);
		p = q;
	}
	*l = NULL;
}
