/*
* 创建一个静态的顺序表存放整数，大小为10，完成以下的操作
* （1）输入6个整数，打印出顺序表中的内容，并显示表中剩余的空间个数
* （2）在顺序表中的第3个位置插入元素0，打印出顺序表中的内容，并显示表中剩余的空间个数
* （3）再试图向表中第11个位置插入整数0，程序提示超出范围
* （4）删除表中第6个元素，打印出顺序表中的内容，并显示表中剩余的空间个数
*/
#include <stdio.h>
#include <stdlib.h>
#define maxSize 10

//interfaces
void print(int [], int *);
void insert(int [], int, int, int *);
void delete(int [], int *, int);

int main()
{
	//initialize static sqlist
	int len = 0, sqlist[maxSize], in = 0;
	printf("please enter 6 integers first:");
	//1.input 6 ints
	for (int i = 0; i < 6; i++) {
		scanf("%d", &sqlist[i]);
		len++;
	}
	//2.print list elem, and show the rest mem
	print(sqlist, &len);
	//3.insert elem 0 at loc = 3,then print list
	insert(sqlist, 3, 0, &len);
	print(sqlist, &len);
	//4.insert elem 0 at loc = 11
	insert(sqlist, 11, 0, &len);
	//5.delete elem at loc = 6,then print list
	delete(sqlist, &len, 6);
	print(sqlist, &len);
	return 0;
}

void print(int sqlist[], int *len)
{
	int remain = maxSize - *len;
	//first print elem
	for (int i = 0; i <= *len - 1; i++) {
		if (i == *len - 1)
			printf("%d.remain %d elems mem\n",sqlist[i], remain);
		else
			printf("%d,", sqlist[i]);
	}
}

void insert(int sqlist[], int loc, int value, int *len)
{
	if (loc > maxSize) {
		printf("out of range,range is [1,%d],please try it again\n", maxSize);
		return;
	}
	//judge illegal insert, loc must in range [1,len+1]
	//and the sqlist is not full
	if (*len == maxSize || loc < 1 || loc > *len + 1)
		exit(EXIT_FAILURE);
	//insert value at loc(loc <= len), then range [loc-1,len-1] need move backward, from back to front move one by one 
	//except insert value at loc(loc == len + 1), no need to move,
	//both of above situations insert values at location loc - 1, and sqlist length inc 1.
	for (int i = *len - 1;i >= loc -1;i--)
		sqlist[i + 1] = sqlist[i];

	sqlist[loc - 1] = value;
	*len += 1;
}

void delete(int sqlist[], int *len, int loc)
{
	//judge illegal delete,loc must in range [1,len]
	if (loc < 1 || loc > *len)
		exit(EXIT_FAILURE);
	// delete value at loc(loc < len), then range[loc,len-1] need move forward, from front to back move one by one
	// except delete value at loc(loc=len-1),no need to move,
	// then sqlist length dec 1.
	for (int i = loc; i <= *len - 1; i++)
		sqlist[i - 1] = sqlist[i];
	*len -= 1;
}
