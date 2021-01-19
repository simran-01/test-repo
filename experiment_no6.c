/*
  NAME:Mapari Simran Hasan
  ROLLNO: 19CO04
  COURSE: Data Structure Lab
  
  Experiment No 6: Array implementation of Circular Queue.

  THEORY:
	Circular Queue:-        Circular Queue is a linear data structure in which the operations are performed based on FIFO (First In First Out) principle and the last position is connected back to the first position to make a circle. 
							It is also called ‘Ring Buffer’. 
							To overcome the disadvantage of a linear queue (Memory wastage),we have circular queue.

*/
#include <stdio.h>
#include <stdlib.h>
#define MAX 5

struct queue
{
	int data[MAX];
	int front, rear;
};

void initialize(struct queue *q)
{
	q->rear = q->front = -1;
}

int isEmpty(struct queue *q)
{
	return (q->rear == -1);
}

int isFull(struct queue *q)
{
	return (q->front == ((q->rear + 1) % MAX)) ? 1 : 0;
}
int Insert(struct queue *q, int d)
{
	if (isFull(q))
	{
		printf("\t\t\nQUEUE IS FULL\n");
		return 0;
	}
	else
	{
		q->rear = (q->rear + 1) % MAX;
		q->data[q->rear] = d;
		printf("\n DATA INSERTION SUCCESFULLY!\n");
		if (q->front == -1)
			q->front = 0;
		return 1;
	}
}
int Delete(struct queue *q)
{
	if (isEmpty(q))
	{
		printf("\n\t QUEUE IS EMPTY\n");
		return 0;
	}
	else
	{
		int a;
		a = q->data[q->front];
		if (q->front == q->rear)
			q->front = q->rear = -1;
		else
			q->front = (q->front + 1) % MAX;
		printf("\n\t ELEMENT DELETED FROM QUEUE IS  %d\n", a);
		return 0;
	}
}
int Search(struct queue *q, int s)
{

	int i = 0;
	for (i = q->front; i != q->rear + 1; i = (i + 1) % MAX)
		if (q->data[i] == s)
			return i;
	return -1;
}
void Display(struct queue *q)
{
	int i;
	if (q->rear == -1)
		printf("\n\t QUEUE IS EMPTY\n");
	else
	{
		printf("\n QUEUE CONTENTS ARE :\n");
		for (i = q->front; i != q->rear; i = (i + 1) % MAX)
		{
			printf("%d\n", q->data[i]);
		}
		printf("%d\n", q->data[i]);
	}
}
int main()
{
	int ch, d;
	struct queue q;
	initialize(&q);
	while (1)
	{
		printf("\n\t\t\tMENU\n1.INSERT\n2.DLELETE\n3.SEARCH\n4.DISPLAY\n0.EXIT\n");
		printf("\nENTER YOUR CHOICE: ");
		scanf("%d", &ch);
		switch (ch)
		{
		case 1:
			printf("\nENTER DATA TO BE INSERTED: ");
			scanf("%d", &d);
			Insert(&q, d);
			break;

		case 2:
			Delete(&q);
			break;

		case 3:
			printf("\n ENTER THE ELEMENT FOR SEARCH: ");
			scanf("%d", &d);
			d = Search(&q, d);
			if (d == -1)
				printf("\nTHE ELEMENT IS NOT PRESENT INSIDE THE QUEUE\n");
			else
				printf("THE ELEMENT IS FOUND IS AT %d\n", d + 1);
			break;

		case 4:
			Display(&q);
			break;

		case 0:
			exit(0);
			break;

		default:
			printf("ENTER A VALID CHOICE\n");
		}
	}
}
