/*
* 编写一个程序，动态地创建一个顺序表。
* 要求：顺序表初始长度为10，向顺序表中输入15个整数，并打印出来；
* 再删除顺序表中的第5个元素，打印出删除后的结果。
*/
#include <stdio.h>
#include <stdlib.h>
#define Maxsize 10

//define data struct
typedef struct {
	int *elem;
	int len;
	int size;
} sqlist;

//interfaces
void delete(sqlist *, int, int *);
void initlist(sqlist *);
void print(sqlist *);

int main(int argc, char *argv[])
{
	sqlist L;
	int *ptr = NULL, tmp = 0;
	//1.initilize sqlist
	initlist(&L);
	//2.input 15 numbers,and print
	printf("please enter 15 integers:"); //also can input any n numbers,dynamic resize sqlist memory.
	for (int i = 1; i <= 15; i++) {
		if (i > L.size) {
			ptr = (int *)realloc(L.elem, (sizeof(int) *(L.size + 1)));
			L.elem = ptr;
			scanf("%d", &L.elem[i-1]);
			L.size += 1;
			L.len += 1;
		} else {
			scanf("%d", &L.elem[i-1]);
			L.len += 1;
		}
	}
	print(&L);
	//3.delete no.5 elem
	delete(&L, 5, &tmp);
	print(&L);
	return 0;
}

void delete(sqlist *l, int loc, int *elem)
{
	//illegal delete
	if (loc < 1 || loc > l->len)
		exit(-1);
	//before del save elem
	elem = &(l->elem[loc - 1]);
	// 1 2 3 4 5	
	for (int i = loc; i <= l->len - 1; i++)
		l->elem[i-1] = l->elem[i];
	l->len -= 1;
}

void initlist(sqlist *l)
{
	l->elem = (int *)malloc(sizeof(int) * Maxsize);
	if (!l->elem)
		exit(EXIT_FAILURE);
	l->size = Maxsize;
	l->len = 0;
}

void print(sqlist *l)
{
	for (int i = 0; i < l->len; i++) {
		if (i == l->len - 1)
			printf("%d\n",l->elem[i]);
		else
			printf("%d,",l->elem[i]);
	}
}
