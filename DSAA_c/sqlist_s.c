#include <stdio.h>

#define MaxSize 10
#define For(a,b) for (int i = (a); i < (b); i++)

//interfaces
void PrintList(int sqlist[], int *size);
void MakeEmpty(int sqlist[], int maxsize, int *size);

int Find(int sqlist[], int *size, int value);
int Findkth(int sqlist[], int *size, int loc);

void Insert(int sqlist[], int *size, int value, int loc);
void Delete(int sqlist[], int *size, int loc);

int main()
{
	/* static create sqlist,size can't too big avoid stack overflow
	 * add test code here
	 */
	int size, sqlist[MaxSize];
	return 0;
}

void PrintList(int sqlist[], int *size)
{
	printf("sqlist(%d):{", *size);
	For(0,*size) {
		if (i == *size - 1)
			printf("%d}\n",sqlist[i]);
		else
			printf("%d ", sqlist[i]);
	}
}

void MakeEmpty(int sqlist[], int maxsize, int *size)
{
	For(0,maxsize)
		sqlist[i] = 0;
	*size = 0;
}

int Find(int sqlist[], int *size, int value)
{
	For(0,*size) {
		if (sqlist[i] == value)
			return i + 1;
	}
	printf("%d not in sqlist\n", value);
	return -1;
}

int Findkth(int sqlist[], int *size, int loc)
{
	if ((loc >= 1) && (loc <=*size))
		return sqlist[loc-1];
	printf("loc is not in the range of sqlist,please try again\n");
	return -1;
}

void Insert(int sqlist[], int *size, int value, int loc)
{
	if (*size == MaxSize) {
		printf("sqlist now is full\n");
		return;
	}
	//illegal insert
	if (loc < 1 || loc > *size + 1)
		return;
	if (loc <= *size) {
		for (int i = *size - 1; i >= loc - 1; i--)
			sqlist[i+1] = sqlist[i];
	}
	sqlist[loc-1] = value;
	*size += 1;
}

void Delete(int sqlist[], int *size, int loc)
{
	if (*size == 0) {
		printf("sqlist is empty\n");
		return;
	}
	//illegal delete
	if (loc < 1 || loc > *size)
		return;

	if (loc < *size) {
		for (int i = loc; i <= *size - 1;i++)
			sqlist[i-1] = sqlist[i];
	}
	*size -= 1;
}
