#pragma once
#include<cstdlib>
#include<cstdio>
#include<cstring>
using namespace std;

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
typedef int Status;//Status是函数的类型，其值是函数结果状态代码

//-----采用动态分配的存储结构-----
typedef int ElemType;
typedef ElemType* Triplet;//由InitTriplet分配3个元素存储空间

//-----基本操作的实现-----
Status InitTriplet(Triplet &T, ElemType v1, ElemType v2, ElemType v3) {
	//构造三元组T，依次置入T的3个元素的初值v1,v2,v3。
	//曾尝试不用引用，但函数内所有的T变成了*T，如T[0]变成了*T[0]，不好理解
	T = (ElemType*)malloc(3 * sizeof(ElemType));//分配3个元素的储存空间
	if (!T)exit(OVERFLOW);//分配存储空间失败
	T[0] = v1; T[1] = v2;T[2] = v3;
	return OK;
}
Status DestroyTriplet(Triplet &T) {
	//销毁三元组
	free(T);  T = NULL;
	return OK;
}
Status Get(Triplet T,int i,ElemType &e) {
	//1<=i<=3，用e返回T的第i元的值。
	if (i < 1 || i > 3)return ERROR;
	e = T[i - 1];
	return OK;
}
Status Put(Triplet& T, int i, ElemType e) {
	//1<=i<=3，置T的第i元的值为e。
	if (i < 1 || i > 3)return ERROR;
	T[i - 1] = e;
	return OK;
}
Status IsAscending(Triplet T) {
	//如果T的3个元素按升序排列，则返回1，否则返回0。
	return(T[0] <= T[1]) && (T[1] <= T[2]);
}
Status IsDescending(Triplet T) {
	//如果T的3个元素按降序排列，则返回1，否则返回0。
	return(T[0] >= T[1]) && (T[1] >= T[2]);
}
Status Max(Triplet T, ElemType& e) {
	//用e返回指向T的最大元素的值。
	e = (T[0] >= T[1]) ? ((T[0] >= T[2]) ? T[0] : T[2]) : ((T[1] >= T[2]) ? T[1] : T[2]);
	return OK;
}
Status Min(Triplet T, ElemType& e) {
	//用e返回指向T的最小元素的值。
	e = (T[0] <= T[1]) ? ((T[0] <= T[2]) ? T[0] : T[2]) : ((T[1] <= T[2]) ? T[1] : T[2]);
	return OK;
}

