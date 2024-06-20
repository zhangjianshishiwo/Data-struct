#include "head.h"
Status InitList_Sq(SqList& L) {
	//����һ���յ����Ա�L��
	L.elem = (ElemType*)malloc(LIST_INIT_SIZE * sizeof(ElemType));
	if (!L.elem)exit(OVERFLOW);//�洢����ʧ��
	L.length = 0;//�ձ���Ϊ0
	L.listsize = LIST_INIT_SIZE;//��ʼ�洢����
	return OK;
}//����

Status ListInsert_Sq(SqList& L, int i, ElemType e) {
	//��˳�����L�е�i��λ��֮ǰ�����µ�Ԫ��e��
	//i�ĺϷ�ֵΪ1<=i<=ListLength_Sq(L)
	ElemType* newbase = NULL, * q, * p;//����ָ��
	if ((i < 1) || (i > L.length + 1))return ERROR;//iֵ���Ϸ�
	if (L.length >= L.listsize) {//��ǰ�洢�ռ����������ӷ���
		newbase = (ElemType*)realloc(L.elem, (L.listsize + LISTINCREMENT) * sizeof(ElemType));
		if (!newbase)exit(OVERFLOW);//�洢����ʧ��
		L.elem = newbase;//�»�ַ
		L.listsize += LISTINCREMENT;//���Ӵ洢����
	}
	q = &(L.elem[i - 1]);//qΪ����λ��
	for (p = &(L.elem[L.length - 1]);p >= q;--p)
		*(p + 1) = *p;//����λ�ü�֮���λ������
	*q = e;//����e
	++L.length;//����1
	return OK;
}//����

Status ListDelete_Sq(SqList& L, int i, ElemType& e) {
	//��˳�����Ա�L��ɾ����i��Ԫ�أ�����e������ֵ
	//i�ĺϷ�ֵΪ1<=i<=ListLength_Sq(L)
	ElemType* p, * q;//����ָ��
	if ((i < 1) || (i > L.length))return ERROR;//iֵ���Ϸ�
	p = &(L.elem[i - 1]);//pΪɾ��λ��
	e = *p;//��ɾ��Ԫ�ص�ֵ����e
	q = L.elem + L.length - 1;//��βԪ�ص�λ��
	for (++p;p <= q;++p)//��ɾ��Ԫ��֮���Ԫ������
		*(p - 1) = *p;
	--L.length;//����1
	return OK;
}//ɾ��

int LocateElem_Sq(SqList L, ElemType e, Status(*compare)(ElemType, ElemType)) {
	//��˳�����Ա�L�в��ҵ�1��ֵ��e����compare()��Ԫ�ص�λ��
	//���ҵ����򷵻�����L�е�λ�򣬷��򷵻�0
	int i;ElemType* p;
	i = 1;//i�ĳ�ֵΪ��1��Ԫ�ص�λ��
	p = L.elem;//p�ĳ�ֵΪ��1��Ԫ�صĴ洢λ��
	while (i <= L.length && !(*compare)(*p++, e))++i;
	if (i <= L.length)return i;
	else return 0;
}//��ֵ����

void MergeList_Sq(SqList La, SqList Lb, SqList& Lc) {
	//��֪˳�����Ա�La��Lb��Ԫ�ذ�ֵ�ǵݼ�����
	//�鲢La��Lb�õ����µ�˳�����Ա�Lc,Lc��Ԫ��Ҳ��ֵ�ǵݼ�����
	ElemType* pa, * pb, * pc, * pa_last, * pb_last;
	pa = La.elem;pb = Lb.elem;
	Lc.listsize = Lc.length = La.length + Lb.length;
	pc = Lc.elem = (ElemType*)malloc(Lc.listsize * sizeof(ElemType));
	if (!Lc.elem)exit(OVERFLOW);//�洢����ʧ��
	pa_last = La.elem + La.length - 1;
	pb_last = Lb.elem + Lb.length - 1;
	while (pa <= pa_last && pb <= pb_last) {//�鲢
		if (*pa <= *pb)*pc++ = *pa++;
		else *pc++ = *pb++;
	}
	while (pa <= pa_last)*pc++ = *pa++;//����La��ʣ��Ԫ��
	while (pb <= pb_last)*pc++ = *pb++;//����Lb��ʣ��Ԫ��
}//�鲢

void union_Sq(SqList& La, SqList Lb) {
	//�����������Ա�Lb�е�����La�е�����Ԫ�ز��뵽La��
	int La_len = ListLength_Sq(La);
	int Lb_len = ListLength_Sq(Lb);//�����Ա�ĳ���
	ElemType e;
	for (int i = 1;i <= Lb_len;i++) {
		GetElem_Sq(Lb, i, e);//ȡLb�е�i������Ԫ�ظ���e
		if (!LocateElem_Sq(La, e, equal))ListInsert_Sq(La, ++La_len, e);
	}
}//����鲢
Status equal(ElemType c1, ElemType c2) /* ����Ԫ���ж�����(��ȹ�ϵ) */
{
	if (c1 == c2)
		return TRUE;
	else
		return FALSE;
}

void DestroyList_Sq(SqList& L) {
	free(L.elem);
	L.elem = NULL;
	L.length = 0;
	L.listsize = 0;
	//�ԷǶ�̬�����ڴ治��ʹ��free�ͷţ�����free(&L)������
}//����

Status ClearList_Sq(SqList& L) {
	if (!L.elem)exit(OVERFLOW);
	else {//ɵ�ˣ�˼������Сʱ�������ٺ������ʲô����ԭ������Ǳ����ռ䰡
		L.length = 0;
		L.listsize = LIST_INIT_SIZE;//�ռ�λ����
		return OK;
	}
}//���

Status ListEmpty_Sq(SqList L) {
	if (L.length == 0 && L.listsize == LIST_INIT_SIZE)
		return TRUE;
	else
		return FALSE;
}//ȷ�����Ƿ�Ϊ��

int ListLength_Sq(SqList L) {
	return L.length;
}//���ر���Ԫ�ظ���

Status GetElem_Sq(SqList L, int i, ElemType& e) {
	if ((i < 1) || (i > L.length))return ERROR;//iֵ���Ϸ�
	e = L.elem[i - 1];
	return OK;
}//��λ����

Status PriorElem_Sq(SqList L, ElemType cur_e, ElemType& pre_e) {
	int i = 2;//�ӵ�2��Ԫ�ؿ�ʼ����Ϊ��һ��Ԫ��һ��û��ǰ��
	for (;i <= L.length;i++) {
		if (L.elem[i - 1] == cur_e)break;//elem[0]�ǵ�1��Ԫ��
	}
	if (i > L.length)return ERROR;//��ǰ��
	pre_e = L.elem[i - 2];//i-1��ǰ����i-2
	return OK;//һ��Ҫ��return OK����û����һ��ΪERROR����һ�����ۺϲ�������ֵ��ΪERROR������һ������������ֵϵͳ���⸳ֵ��
}//Ѱ��ǰ��

Status NextElem_Sq(SqList L, ElemType cur_e, ElemType& next_e) {
	int i = 1;//�ӵ�1��Ԫ�ؿ�ʼ
	for (;i <= L.length;i++) {
		if (L.elem[i - 1] == cur_e)break;//elem[0]�ǵ�1��Ԫ��
	}
	if (i >= L.length)return ERROR;//�޺��
	next_e = L.elem[i];//i-1��ǰ����i
	return OK;
}//Ѱ�Һ��

Status ListTraverse_Sq(SqList L, void(*visit)(ElemType*))
{ /* ��ʼ������˳�����Ա�L�Ѵ��� */
  /* ������������ζ�L��ÿ������Ԫ�ص��ú���visit()��һ��visit()ʧ�ܣ������ʧ�� */
  /*           visit()���βμ�'&'��������ͨ������visit()�ı�Ԫ�ص�ֵ */
	ElemType* p;
	int i;
	p = L.elem;
	for (i = 1;i <= L.length;i++)
		visit(p++);
	printf("\n");
	return OK;
}
