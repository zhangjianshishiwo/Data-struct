#include "head.h"

int main()
{
	Triplet T;
	ElemType e;
	InitTriplet(T, 14, 22, 35);
	Get(T, 2, e);
	printf("理论输出：22\n");
	printf("实际输出：%d\n", e);
	e = 29;
	Put(T, 2, e);
	printf("理论输出：29\n");
	printf("实际输出：%d\n", e);
	if(IsDescending(T))
	{
		printf("降序\n");
	}
	if(IsAscending(T))
	{
		printf("升序\n");
	}
	Get(T, 1, e);
	printf("理论输出：14\n");
	printf("实际输出：%d\n", e);
	Max(T, e);
	printf("理论输出：35\n");
	printf("实际输出：%d\n", e);
	Min(T, e);
	printf("理论输出：14\n");
	printf("实际输出：%d\n", e);
	return 0;
}