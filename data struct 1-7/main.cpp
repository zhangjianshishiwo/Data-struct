#include "head.h"

int main()
{
	Triplet T;
	ElemType e;
	InitTriplet(T, 14, 22, 35);
	Get(T, 2, e);
	printf("���������22\n");
	printf("ʵ�������%d\n", e);
	e = 29;
	Put(T, 2, e);
	printf("���������29\n");
	printf("ʵ�������%d\n", e);
	if(IsDescending(T))
	{
		printf("����\n");
	}
	if(IsAscending(T))
	{
		printf("����\n");
	}
	Get(T, 1, e);
	printf("���������14\n");
	printf("ʵ�������%d\n", e);
	Max(T, e);
	printf("���������35\n");
	printf("ʵ�������%d\n", e);
	Min(T, e);
	printf("���������14\n");
	printf("ʵ�������%d\n", e);
	return 0;
}