#include <stdio.h>
#include <stdlib.h>

#define MaxSize 100

typedef int ElemType;
typedef struct {
	ElemType *elem;
	int len;
	int size;
} sqlist;

void initsqlist(sqlist *l);
void insertelem(sqlist *l, int i, elemType elem);
void delelem(sqlist *l, int i);

int main(int argc, char *argv[])
{
	return 0;
}

void initsqlist(sqlist *l)
{
	l->elem = (ElemType *)malloc(MaxSize * sizeof(ElemType));
	if (!l->elem) exit(0);
	l->len = 0;
	l->size = MaxSize;
}

void insertelem(sqlist *l, int i, elemType elem)
{
	ElemType *base, *insertPtr, *p;
	if (i < 1 || i > l->len + 1)
		exit(0);

	if (l->len >= l->size) {
		base = (ElemType *) realloc(l->elem, (l->size + 10) *sizeof(ElemType));
		l->elem = base;
		l->size += 10;
	}
	insertPtr = &(l->elem[i-1]);
	for (p = &(l->elem[l->len-1]);p >= insertPtr;p--)
		*(p+1) =*p;
	*insertPtr = item;
	l->len++;
}

void delelem(sqlist *l, int i)
{
	ElemType *delItem, *q;
	if (i < 1 || i > l->len)
		exit(0);
	delItem = &(l->elem[i-1]);
	q = l->elem + l->len - 1;
	for (++delItem; delItem <= q; ++delItem) {
		*(delItem - 1) = *delItem;
	}
	l->len--;
}
