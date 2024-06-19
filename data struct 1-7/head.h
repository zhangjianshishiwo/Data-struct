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
typedef int Status;//Status�Ǻ��������ͣ���ֵ�Ǻ������״̬����

//-----���ö�̬����Ĵ洢�ṹ-----
typedef int ElemType;
typedef ElemType* Triplet;//��InitTriplet����3��Ԫ�ش洢�ռ�

//-----����������ʵ��-----
Status InitTriplet(Triplet &T, ElemType v1, ElemType v2, ElemType v3) {
	//������Ԫ��T����������T��3��Ԫ�صĳ�ֵv1,v2,v3��
	//�����Բ������ã������������е�T�����*T����T[0]�����*T[0]���������
	T = (ElemType*)malloc(3 * sizeof(ElemType));//����3��Ԫ�صĴ���ռ�
	if (!T)exit(OVERFLOW);//����洢�ռ�ʧ��
	T[0] = v1; T[1] = v2;T[2] = v3;
	return OK;
}
Status DestroyTriplet(Triplet &T) {
	//������Ԫ��
	free(T);  T = NULL;
	return OK;
}
Status Get(Triplet T,int i,ElemType &e) {
	//1<=i<=3����e����T�ĵ�iԪ��ֵ��
	if (i < 1 || i > 3)return ERROR;
	e = T[i - 1];
	return OK;
}
Status Put(Triplet& T, int i, ElemType e) {
	//1<=i<=3����T�ĵ�iԪ��ֵΪe��
	if (i < 1 || i > 3)return ERROR;
	T[i - 1] = e;
	return OK;
}
Status IsAscending(Triplet T) {
	//���T��3��Ԫ�ذ��������У��򷵻�1�����򷵻�0��
	return(T[0] <= T[1]) && (T[1] <= T[2]);
}
Status IsDescending(Triplet T) {
	//���T��3��Ԫ�ذ��������У��򷵻�1�����򷵻�0��
	return(T[0] >= T[1]) && (T[1] >= T[2]);
}
Status Max(Triplet T, ElemType& e) {
	//��e����ָ��T�����Ԫ�ص�ֵ��
	e = (T[0] >= T[1]) ? ((T[0] >= T[2]) ? T[0] : T[2]) : ((T[1] >= T[2]) ? T[1] : T[2]);
	return OK;
}
Status Min(Triplet T, ElemType& e) {
	//��e����ָ��T����СԪ�ص�ֵ��
	e = (T[0] <= T[1]) ? ((T[0] <= T[2]) ? T[0] : T[2]) : ((T[1] <= T[2]) ? T[1] : T[2]);
	return OK;
}

