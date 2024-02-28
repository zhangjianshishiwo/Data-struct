#include "LinkStack.h"

Status InitStack(LinkStack& S) {
	S = (LinkStack)malloc(sizeof(SNode));
	if (!S)
		exit(OVERFLOW);
	S->next = NULL;
	return OK;
}

Status DestroyStack(LinkStack& S) {
	LinkStack p = S->next, pp;
	while (p) {
		pp = p->next;
		free(p);
		p = pp;
	}
	free(S);
	return OK;
}

Status ClearStack(LinkStack& S) {
	LinkStack p = S->next, pp;
	while (p) {
		pp = p->next;
		free(p);
		p = pp;
	}
	S->next = NULL;
	return OK;
}

Status StackEmpty(LinkStack S) {
	if (S->next == NULL)
		return OK;
	else
		return FALSE;
}

int StackLength(LinkStack S) {
	int n = 0;
	LinkStack p = S->next;
	while (p) {
		n++;
		p = p->next;
	}
	return n;
}

Status GetTop(LinkStack S, SElemType& e) {
	if (S->next == NULL)
		return ERROR;
	e = S->next->data;
	return OK;
}

Status Push(LinkStack& S, SElemType e) {
	LinkStack p = (LinkStack)malloc(sizeof(SNode));
	p->data = e;
	p->next = S->next;
	S->next = p;
	return OK;
}

Status Pop(LinkStack& S, SElemType& e) {
	if (S->next == NULL)
		return ERROR;
	e = S->next->data;
	LinkStack pp = S->next->next;
	free(S->next);
	S->next = pp;
	return OK;
}

Status StackTraverse(LinkStack S, void(*visit)(SElemType)) {
	if (S->next == NULL) {
		printf("Õ»Îª¿Õ£¡\n");
		return ERROR;
	}
	for (int i = StackLength(S);i > 0;i--) {
		LinkStack p = S->next;
		int j = 1;
		while (p && j < i) {
			p = p->next;
			++j;
		}
		visit(p->data);
	}
	printf("\n");
	return OK;
}

Status StackTraverse_Top(LinkStack S, Status(*pfn_visit)(SElemType)) {
	if (S->next == NULL) {
		printf("Õ»Îª¿Õ£¡\n");
		return ERROR;
	}
	LinkStack p = S->next;
	while (p) {
		pfn_visit(p->data);
		p = p->next;
	}
	printf("\n");
	return OK;
}