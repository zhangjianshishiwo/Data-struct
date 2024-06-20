#include"head.h"
typedef int ElemType;

Status comp(ElemType c1, ElemType c2) /* ����Ԫ���ж�����(ƽ����ϵ) */
{
    if (c1 == c2 * c2)
        return TRUE;
    else
        return FALSE;
}

void visit(ElemType* c) /* ListTraverse()���õĺ���(����Ҫһ��) */
{
    printf("%d ", *c);
}

void dbl(ElemType* c) /* ListTraverse()���õ���һ����(Ԫ��ֵ�ӱ�) */
{
    *c *= 2;
}

void main()
{
    SqList L, L1, L2;
    ElemType e, e0;
    Status i;
    int j, k;
    i = InitList_Sq(L);
    printf("��ʼ��L��L.elem=%u L.length=%d L.listsize=%d\n", L.elem, L.length, L.listsize);
    for (j = 1;j <= 5;j++)
        i = ListInsert_Sq(L, 1, j);
    printf("��L�ı�ͷ���β���1��5��*L.elem=");
    for (j = 1;j <= 5;j++)
        printf("%d ", *(L.elem + j - 1));
    printf("\n");
    printf("L.elem=%u L.length=%d L.listsize=%d\n", L.elem, L.length, L.listsize);
    i = ListEmpty_Sq(L);
    printf("L�Ƿ�գ�i=%d(1:�� 0:��)\n", i);
    i = ClearList_Sq(L);
    printf("���L��L.elem=%u L.length=%d L.listsize=%d\n", L.elem, L.length, L.listsize);
    i = ListEmpty_Sq(L);
    printf("L�Ƿ�գ�i=%d(1:�� 0:��)\n", i);
    for (j = 1;j <= 10;j++)
        ListInsert_Sq(L, j, j);
    printf("��L�ı�β���β���1��10��L.elem=");
    for (j = 1;j <= 10;j++)
        printf("%d ", *(L.elem + j - 1));
    printf("\n");
    printf("L.elem=%u L.length=%d L.listsize=%d\n", L.elem, L.length, L.listsize);
    ListInsert_Sq(L, 1, 0);
    printf("��L�ı�ͷ����0��L.elem=");
    for (j = 1;j <= ListLength_Sq(L);j++) /* ListLength(L)ΪԪ�ظ��� */
        printf("%d ", *(L.elem + j - 1));
    printf("\n");
    printf("L.elem=%u(�п��ܸı�) L.length=%d(�ı�) L.listsize=%d(�ı�)\n", L.elem, L.length, L.listsize);
    GetElem_Sq(L, 5, e);
    printf("��5��Ԫ�ص�ֵΪ��%d\n", e);
    for (j = 3;j <= 4;j++)
    {
        k = LocateElem_Sq(L, j, comp);
        if (k)
            printf("��%d��Ԫ�ص�ֵΪ%d��ƽ��\n", k, j);
        else
            printf("û��ֵΪ%d��ƽ����Ԫ��\n", j);
    }
    for (j = 1;j <= 2;j++) /* ����ͷ�������� */
    {
        GetElem_Sq(L, j, e0); /* �ѵ�j�����ݸ���e0 */
        i = PriorElem_Sq(L, e0, e); /* ��e0��ǰ�� */
        if (i == ERROR)
            printf("Ԫ��%d��ǰ��\n", e0);
        else
            printf("Ԫ��%d��ǰ��Ϊ��%d\n", e0, e);
    }
    for (j = ListLength_Sq(L) - 1;j <= ListLength_Sq(L);j++) /* ����������� */
    {
        GetElem_Sq(L, j, e0); /* �ѵ�j�����ݸ���e0 */
        i = NextElem_Sq(L, e0, e); /* ��e0�ĺ�� */
        if (i == ERROR)
            printf("Ԫ��%d�޺��\n", e0);
        else
            printf("Ԫ��%d�ĺ��Ϊ��%d\n", e0, e);
    }
    k = ListLength_Sq(L); /* kΪ�� */
    for (j = k + 1;j >= k;j--)
    {
        i = ListDelete_Sq(L, j, e); /* ɾ����j������ */
        if (i == ERROR)
            printf("ɾ����%d������ʧ��\n", j);
        else
            printf("ɾ����Ԫ��ֵΪ��%d\n", e);
    }
    printf("�������L��Ԫ�أ�");
    ListTraverse_Sq(L, visit); /* ���ζ�Ԫ�ص���visit()�����Ԫ�ص�ֵ */
    printf("L��Ԫ��ֵ�ӱ���");
    ListTraverse_Sq(L, dbl); /* ���ζ�Ԫ�ص���dbl()��Ԫ��ֵ��2 */
    ListTraverse_Sq(L, visit);
    i = InitList_Sq(L1);//L1�����ʼ����L2���Բ���ʼ��
    printf("��ʼ��L1��L1.elem=%u L1.length=%d L1.listsize=%d\n", L1.elem, L1.length, L1.listsize);
    for (j = 1;j <= 6;j++)
        ListInsert_Sq(L1, j, j);
    printf("��L1�ı�β���β���1��6��L1.elem=");
    for (j = 1;j <= 6;j++)
        printf("%d ", *(L1.elem + j - 1));
    printf("\n");
    MergeList_Sq(L, L1, L2);
    printf("�������L2��Ԫ�أ�");
    ListTraverse_Sq(L2, visit);
    union_Sq(L, L1);
    printf("�������L��Ԫ�أ�");
    ListTraverse_Sq(L, visit);
    DestroyList_Sq(L);
    DestroyList_Sq(L1);
    DestroyList_Sq(L2);
    printf("����L��L.elem=%u L.length=%d L.listsize=%d\n", L.elem, L.length, L.listsize);
}