/*
*********************************************************************************************************
*Author       : binc6263 
*Last modified: 2023-12-24 05:18
*Email        : cb99986174@163.com
*blog         : https://blog.csdn.net/qq_37167532
*Filename     : exam4.c
*Description  : 
* 利用栈的数据结构，将二进制数转换为十进制数
* 11001 -> 1*2^0 + 0*2^1 + 0*2^2 + 1*2^3 + 1*2^4 = 25 
*********************************************************************************************************
*/
#include <stdio.h>
#include <stdlib.h>

#define STACK_INIT_SIZE 32
typedef struct {
	int *bot;
	int *top;
	int size;
} sqstack;

void push(sqstack *, int);
void pop(sqstack *, int *);

int main(void)
{
	//initialize stack
	int n = 0, sum = 0, shift = 0, tmp, current;
	sqstack s;
	s.bot = (int *)malloc(sizeof(int) * STACK_INIT_SIZE);
	if (!s.bot)
		exit(EXIT_FAILURE);
	s.top = s.bot;
	s.size = STACK_INIT_SIZE;
	//push elem to sqstack
	printf("enter binary numbers:");
	while (scanf("%d", &n) && (n == 0 || n == 1)) {
		push(&s, n);
	}
	current = s.top - s.bot;
	while (shift <= current) {
		pop(&s, &tmp);
		sum += tmp * (1 << shift);
		shift++;
	}
	printf("dec is %d\n", sum);
	return 0;
}

void push(sqstack *s, int elem)
{
	if (s->top - s->bot >= STACK_INIT_SIZE)
		exit(EXIT_FAILURE);
	*(s->top) = elem;
	s->top++;
}

void pop(sqstack *s, int *elem)
{
	if (s->top == s->bot)
		exit(EXIT_FAILURE);
	s->top--;
	*elem = *(s->top);
}
