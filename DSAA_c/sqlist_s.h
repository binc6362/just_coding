#ifndef __SQLISTS_H__
#define __SQLISTS_H__

#define MaxSize 10
#define For(a,b) for (int i = (a); i < (b); i++)

//interfaces
void PrintList(int sqlist[], int *size);
void MakeEmpty(int sqlist[], int maxsize, int *size);

int Find(int sqlist[], int *size, int value);
int Findkth(int sqlist[], int *size, int loc);

void Insert(int sqlist[], int *size, int value, int loc);
void Delete(int sqlist[], int *size, int loc);
#endif
