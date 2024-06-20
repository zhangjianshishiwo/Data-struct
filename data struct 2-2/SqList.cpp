#include "head.h"
Status InitList_Sq(SqList& L) {
	//构造一个空的线性表L。
	L.elem = (ElemType*)malloc(LIST_INIT_SIZE * sizeof(ElemType));
	if (!L.elem)exit(OVERFLOW);//存储分配失败
	L.length = 0;//空表长度为0
	L.listsize = LIST_INIT_SIZE;//初始存储容量
	return OK;
}//构造

Status ListInsert_Sq(SqList& L, int i, ElemType e) {
	//在顺序表中L中第i个位置之前插入新的元素e。
	//i的合法值为1<=i<=ListLength_Sq(L)
	ElemType* newbase = NULL, * q, * p;//辅助指针
	if ((i < 1) || (i > L.length + 1))return ERROR;//i值不合法
	if (L.length >= L.listsize) {//当前存储空间已满，增加分配
		newbase = (ElemType*)realloc(L.elem, (L.listsize + LISTINCREMENT) * sizeof(ElemType));
		if (!newbase)exit(OVERFLOW);//存储分配失败
		L.elem = newbase;//新基址
		L.listsize += LISTINCREMENT;//增加存储容量
	}
	q = &(L.elem[i - 1]);//q为插入位置
	for (p = &(L.elem[L.length - 1]);p >= q;--p)
		*(p + 1) = *p;//插入位置及之后的位置右移
	*q = e;//插入e
	++L.length;//表长增1
	return OK;
}//插入

Status ListDelete_Sq(SqList& L, int i, ElemType& e) {
	//在顺序线性表L中删除第i个元素，并用e返回其值
	//i的合法值为1<=i<=ListLength_Sq(L)
	ElemType* p, * q;//辅助指针
	if ((i < 1) || (i > L.length))return ERROR;//i值不合法
	p = &(L.elem[i - 1]);//p为删除位置
	e = *p;//被删除元素的值赋给e
	q = L.elem + L.length - 1;//表尾元素的位置
	for (++p;p <= q;++p)//被删除元素之后的元素左移
		*(p - 1) = *p;
	--L.length;//表长减1
	return OK;
}//删除

int LocateElem_Sq(SqList L, ElemType e, Status(*compare)(ElemType, ElemType)) {
	//在顺序线性表L中查找第1个值与e满足compare()的元素的位序
	//若找到，则返回其在L中的位序，否则返回0
	int i;ElemType* p;
	i = 1;//i的初值为第1个元素的位序
	p = L.elem;//p的初值为第1个元素的存储位置
	while (i <= L.length && !(*compare)(*p++, e))++i;
	if (i <= L.length)return i;
	else return 0;
}//按值查找

void MergeList_Sq(SqList La, SqList Lb, SqList& Lc) {
	//已知顺序线性表La和Lb的元素按值非递减排列
	//归并La和Lb得到的新的顺序线性表Lc,Lc的元素也按值非递减排列
	ElemType* pa, * pb, * pc, * pa_last, * pb_last;
	pa = La.elem;pb = Lb.elem;
	Lc.listsize = Lc.length = La.length + Lb.length;
	pc = Lc.elem = (ElemType*)malloc(Lc.listsize * sizeof(ElemType));
	if (!Lc.elem)exit(OVERFLOW);//存储分配失败
	pa_last = La.elem + La.length - 1;
	pb_last = Lb.elem + Lb.length - 1;
	while (pa <= pa_last && pb <= pb_last) {//归并
		if (*pa <= *pb)*pc++ = *pa++;
		else *pc++ = *pb++;
	}
	while (pa <= pa_last)*pc++ = *pa++;//插入La的剩余元素
	while (pb <= pb_last)*pc++ = *pb++;//插入Lb的剩余元素
}//归并

void union_Sq(SqList& La, SqList Lb) {
	//将所有在线性表Lb中但不在La中的数据元素插入到La中
	int La_len = ListLength_Sq(La);
	int Lb_len = ListLength_Sq(Lb);//求线性表的长度
	ElemType e;
	for (int i = 1;i <= Lb_len;i++) {
		GetElem_Sq(Lb, i, e);//取Lb中第i个数据元素赋给e
		if (!LocateElem_Sq(La, e, equal))ListInsert_Sq(La, ++La_len, e);
	}
}//无序归并
Status equal(ElemType c1, ElemType c2) /* 数据元素判定函数(相等关系) */
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
	//对非动态开辟内存不能使用free释放，所以free(&L)不可以
}//销毁

Status ClearList_Sq(SqList& L) {
	if (!L.elem)exit(OVERFLOW);
	else {//傻了，思考两个小时在想销毁和清空有什么区别，原来清空是保留空间啊
		L.length = 0;
		L.listsize = LIST_INIT_SIZE;//空间位置数
		return OK;
	}
}//清空

Status ListEmpty_Sq(SqList L) {
	if (L.length == 0 && L.listsize == LIST_INIT_SIZE)
		return TRUE;
	else
		return FALSE;
}//确定表是否为空

int ListLength_Sq(SqList L) {
	return L.length;
}//返回表中元素个数

Status GetElem_Sq(SqList L, int i, ElemType& e) {
	if ((i < 1) || (i > L.length))return ERROR;//i值不合法
	e = L.elem[i - 1];
	return OK;
}//按位查找

Status PriorElem_Sq(SqList L, ElemType cur_e, ElemType& pre_e) {
	int i = 2;//从第2个元素开始，因为第一个元素一定没有前驱
	for (;i <= L.length;i++) {
		if (L.elem[i - 1] == cur_e)break;//elem[0]是第1个元素
	}
	if (i > L.length)return ERROR;//无前驱
	pre_e = L.elem[i - 2];//i-1的前驱是i-2
	return OK;//一定要有return OK。若没有上一次为ERROR，下一次无论合不合理返回值仍为ERROR；若第一次正常，返回值系统随意赋值。
}//寻找前驱

Status NextElem_Sq(SqList L, ElemType cur_e, ElemType& next_e) {
	int i = 1;//从第1个元素开始
	for (;i <= L.length;i++) {
		if (L.elem[i - 1] == cur_e)break;//elem[0]是第1个元素
	}
	if (i >= L.length)return ERROR;//无后继
	next_e = L.elem[i];//i-1的前驱是i
	return OK;
}//寻找后继

Status ListTraverse_Sq(SqList L, void(*visit)(ElemType*))
{ /* 初始条件：顺序线性表L已存在 */
  /* 操作结果：依次对L的每个数据元素调用函数visit()。一旦visit()失败，则操作失败 */
  /*           visit()的形参加'&'，表明可通过调用visit()改变元素的值 */
	ElemType* p;
	int i;
	p = L.elem;
	for (i = 1;i <= L.length;i++)
		visit(p++);
	printf("\n");
	return OK;
}
