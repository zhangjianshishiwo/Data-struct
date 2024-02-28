#include "LinkStack.h"
#define OperandType char

Status visit(SElemType e) {
	printf(" %c", e);
	return OK;
}

//-----算法部分-----
//判定运算符栈的（栈顶运算符Θ1）与（读入的运算符Θ2）之间的优先关系

SElemType Precede(SElemType t1, SElemType t2) {
	SElemType t;
	switch (t1) {
	case '+':
	case '-':
		if (t2 == '*' || t2 == '/' || t2 == '(')
			t = '<';
		else t = '>';
		break;
	case '*':
	case '/':
		if (t2 == '(')
			t = '<';
		else t = '>';
		break;
	case '(':
		if (t2 == ')')
			t = '=';
		else if (t2 == '#')
			return ERROR;
		else t = '<';
		break;
	case ')':
		if (t2 == '(')
			return ERROR;
		else t = '>';
		break;
	case '#':
		if (t2 == ')')
			return ERROR;
		else if (t2 == '#')
			t = '=';
		else t = '<';
		break;
	}
	return t;
}

//进行二元运算aΘb
SElemType Operator(SElemType a, SElemType theta, SElemType b) {
	SElemType ret;
	switch (theta)
	{
	case '+':
		ret = (a - 48) + (b - 48) + 48;
		break;
	case '-':
		ret = (a - 48) - (b - 48) + 48;
		break;
	case '*':
		ret = (a - 48) * (b - 48) + 48;
		break;
	case '/':
		ret = (a - 48) / (b - 48) + 48;
		break;
	default:
		return NULL;
	}
	return ret;
}

Status In(SElemType c) {
	switch (c) {
	case'+':
	case'-':
	case'*':
	case'/':
	case'(':
	case')':
	case'#':
	case'=':
		return OK;
		break;
	default:
		return ERROR;
	}
}

//算法3.4
OperandType EvaluateExpression() {
	//算术表达式求值的算符优先算法。
	//设OPTR和OPND分别为运算符栈和运算数栈，OP为运算符集合。
	LinkStack OPTR;//运算符栈：寄存运算符
	LinkStack OPND;//运算数栈：寄存操作数或运算结果
	//VS中变量上加注释，当鼠标移到下一次同变量的地方会显示注释
	char c, x, theta, a, b, e;
	InitStack(OPTR);
	InitStack(OPND);
	Push(OPTR, '#');
	c = getchar();
	GetTop(OPTR, e);
	while (c != '#' || e != '#') {
		if (!In(c)) {//运算数
			Push(OPND, c);
			c = getchar();
		}
		else {//运算符
			GetTop(OPTR, e);
			switch (Precede(e, c)) {
			case '<'://栈顶元素优先权低
				Push(OPTR, c);
				c = getchar();
				break;
			case '='://脱括号并接受下一个字符
				Pop(OPTR, x);
				c = getchar();
				break;
			case '>'://退栈并将运算结果入栈
				Pop(OPTR, theta);
				Pop(OPND, b);
				Pop(OPND, a);
				Push(OPND, Operator(a, theta, b));
				break;
			}
		}
		GetTop(OPTR, e);
	}
	GetTop(OPND, e);
	return e;
}

//运算数只能是一位自然数
int main(int argc, char** argv) {
	char c;
	c = EvaluateExpression();//3*5#=15
	printf("%d", c - 48);
	return 0;
}