/*
NAME:MAPARI SIMRAN HASAN
ROLLNO: 19CO04.
COURSE: DATA STRUCTURE LAB.

Experiment No 2: Implementation of stack using arrays.

THEORY:
  Stack:-  A stack is a linear data structure in which addition and deletion of data are done from a same end. This end is often referred as top of a stack.
        Last-In-First-Out (LIFO) structure.
      

  STACK Abstract Data Type(ADT):
                    Operations performed in stacks for implementation  are as follows:
                            1. Initialize a stack.
                            2. check whether the stack is empty.
                            3. check whether the stack is full.
                            4. Insert at the top of stack if a stack is not full. This operation is called Push.
                            5. Delete a element from the top of stack if it is not empty. This operation is called Pop.
                            6. Retrieve an element from the top of stack. This operation is called Peek.
     
*/

#include <stdio.h>
#include <stdlib.h>
#define MAX 5

struct stack
{
  int data[MAX];
  int top;
};

void initialize(struct stack *s)
{
  s->top = -1;
}

int isEmpty(struct stack *s)
{
  if (s->top == -1)
    return 1;
  else
    return 0;
}
int isFull(struct stack *s)
{
  if (s->top == MAX - 1)
    return 1;
  else
    return 0;
}

void push(struct stack *s, int d)
{
  if (isFull(s))
    printf("stack is overflow");

  else
  {
    s->top++;
    s->data[s->top] = d;
    printf("pushed successfully");
  }
}

void pop(struct stack *s, int d)
{
  if (isEmpty(s))
    printf("Stack is underflow");

  else
  {
    d = s->data[s->top];
    s->top--;
    printf("Poped element is %d", d);
  }
}

void peek(struct stack *s)
{
  if (isEmpty(s))
    printf("Stack is underflow");

  else
  {
    int d = s->data[s->top];
    printf("peak element is\t%d", d);
  }
}

void display(struct stack *s)
{
  int i;
  if (isEmpty(s))
    printf("Stack is underflow");

  else
  {
    printf("--------Content of Stack---------");
    for (i = s->top; i >= 0; i--)
    {
      printf("%d\n", s->data[i]);
    }
  }
}

int main()
{
  struct stack s;
  int a, d;
  initialize(&s);

  printf("\t\t\t\tMENU PROGRAM");
  while (1)
  {

    printf("\n\nOperations:");
    printf("\n1. push\n2. pop\n3. peek\n4. display\n5. exit\n\nEnter your choice: ");
    scanf("%d", &a);
    switch (a)
    {
    case 1:
      printf("Enter the data for push: ");
      scanf("%d", &d);
      push(&s, d);
      break;

    case 2:
      pop(&s, d);
      break;

    case 3:
      peek(&s);
      break;

    case 4:
      display(&s);
      break;

    case 5:
      exit(0);

    default:
      printf("Invalid choice!!");
    }
  }
  return 0;
}
