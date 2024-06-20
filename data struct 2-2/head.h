#pragma once
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
typedef int Status;//Status�Ǻ��������ͣ���ֵ�Ǻ������״̬����
typedef int ElemType;

//-----���Ա�Ķ�̬����˳��洢�ṹ-----
#define LIST_INIT_SIZE 100 //���Ա�洢�ռ�ĳ�ʼ������
#define LISTINCREMENT 10 //���Ա�洢�ռ�ķ�������
typedef struct SqList {
	ElemType* elem;//�洢�ռ��ַ
	int length;//��ǰ����
	int listsize;//��ǰ����Ĵ洢����(��sizeof(ElemType)Ϊ��λ)
}SqList;

Status InitList_Sq(SqList& L);
//�������������һ���յ����Ա�L��
void DestroyList_Sq(SqList& L);
//��ʼ���������Ա�L�Ѵ��ڡ�
//����������������Ա�L��
Status ClearList_Sq(SqList& L);
//��ʼ���������Ա�L�Ѵ��ڡ�
//�����������L����Ϊ�ձ�
Status ListEmpty_Sq(SqList L);
//��ʼ���������Ա�L�Ѵ��ڡ�
//�����������LΪ�ձ��򷵻�TRUE,���򷵻�FALSE��
int ListLength_Sq(SqList L);
//��ʼ���������Ա�L�Ѵ��ڡ�
//�������������L������Ԫ�ظ�����
Status GetElem_Sq(SqList L, int i, ElemType& e);
//��ʼ���������Ա�L�Ѵ��ڣ�1<=i<=ListLength(L)��
//�����������e����L�е�i������Ԫ�ص�ֵ��
int LocateElem_Sq(SqList L, ElemType e, Status(*compare)(ElemType, ElemType));
//��ʼ���������Ա�L�Ѵ��ڣ�compare()������Ԫ���ж�������
//�������������L�е�1�������ϵcompare()������Ԫ�ص�λ��������������Ԫ�ز����ڣ��򷵻�ֵΪ0��
Status PriorElem_Sq(SqList L, ElemType cur_e, ElemType& pre_e);
//��ʼ���������Ա�L�Ѵ��ڡ�
//�����������cur_e��L������Ԫ�أ��Ҳ��ǵ�һ��������pre_e��������ǰ�����������ʧ�ܣ�pre_e�޶��塣
Status NextElem_Sq(SqList L, ElemType cur_e, ElemType& next_e);
//��ʼ���������Ա�L�Ѵ��ڡ�
//�����������cur_e��L������Ԫ�أ��Ҳ��ǵ�һ��������next_e�������ĺ�̣��������ʧ�ܣ�pre_e�޶��塣
Status ListInsert_Sq(SqList& L, int i, ElemType e);
//��ʼ���������Ա�L�Ѵ��ڣ�1<=i<=ListLength(L)+1��
//�����������L�е�i��λ��֮ǰ�����µ�����Ԫ��e��L�ĳ��ȼ�1��
Status ListDelete_Sq(SqList& L, int i, ElemType& e);
//��ʼ���������Ա�L�Ѵ����ҷǿգ�1<=i<=ListLength(L)��
//���������ɾ��L�ĵ�i������Ԫ�أ�����e������ֵ��L�ĳ��ȼ�1��
Status ListTraverse_Sq(SqList L, void (*visit)(ElemType*));
//��ʼ���������Ա�L�Ѵ��ڡ�
//������������ζ�L��ÿ������Ԫ�ص��ú���visit()��һ��visit()ʧ�ܣ������ʧ�ܡ�
void MergeList_Sq(SqList La, SqList Lb, SqList& Lc);
//�ϲ�����ǵݼ�˳���//����������ǿα���12������������һ����
//�鲢La,Lb�õ��µ����Ա�Lc��Lc������Ԫ��Ҳ��ֵ�ǵݼ����С�
void union_Sq(SqList& La, SqList Lb);
//�����������Ա�Lb�е�����La�е�����Ԫ�ز��뵽La��
Status equal(ElemType c1, ElemType c2); /* ����Ԫ���ж�����(��ȹ�ϵ) */