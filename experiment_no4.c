/*
NAME:MAPARI SIMRAN HASAN
ROLLNO: 19CO04.
COURSE: DATA STRUCTURE LAB.
          Experiment no:4 Evaluation of Postfix Expression
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX 50

struct stack
{
	int data[MAX];
	int top;
};

int empty(struct stack *s)
{
	return (s->top == -1) ? 1 : 0;
}

void push(struct stack *s, int ele)
{
	if (s->top < MAX - 1)
		s->data[++s->top] = ele;
	else
		printf("\nStack Overflow.");
}

int pop(struct stack *s)
{
	if (!empty(s))
		return s->data[s->top--];
	else
		return -1;
}

int eval(char *expr)
{
	char c;
	int i, res, op2;
	struct stack st;
	st.top = -1;
	for (i = 0; expr[i] != '\0'; i++)
	{
		c = expr[i];
		switch (c)
		{
		case '+':
			op2 = pop(&st);
			res = pop(&st) + op2;
			push(&st, res);
			break;
		case '-':
			op2 = pop(&st);
			res = pop(&st) - op2;
			push(&st, res);
			break;
		case '*':
			op2 = pop(&st);
			res = pop(&st) * op2;
			push(&st, res);
			break;
		case '/':
			op2 = pop(&st);
			res = pop(&st) / op2;
			push(&st, res);
			break;
		case '^':
		case '$':
			op2 = pop(&st);
			res = pow(pop(&st), op2);
			push(&st, res);
			break;
		default:
			push(&st, c - '0');
		}
	}
	return pop(&st);
}

int main()
{
	char *postfix;
	int res;
	postfix = (char *)malloc(1);
	printf("\nEnter Postfix expression : ");
	scanf("%s", postfix);
	res = eval(postfix);
	printf("\nEvaluation of Postfix is : %d\n", res);
}
