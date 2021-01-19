/*
  NAME:MAPARI SIMRAN HASAN 
  ROLLNO: 19CO04.
  COURSE: DATA STRUCTURE LAB.

Experiment No 5: Array implementation of Queue 

THEORY:
	Queue:
		A queue is a linear data structure in which addition is done from one end and deletion of data is done from another end.
		The end from where data is inserted is referred as rear of a queue.
		The end from where data is deleted is referred as front end.
		Queue follows FIFO stucture.

	QUEUE ADT:
		DATA: It is a finite sequence of elements of a particular type. (arrays / linked list)
		OPERATIONS :
			1. Initialize a queue.
			2. check whether the queue is empty.
			3. check whether the queue is full.
			4. Insert from the rear end if a queue is not full. This operation is called Insert.
			5. Delete a element from the front of queue if it is not empty. This operation is called Delete.

*/

#include <stdio.h>
#include <stdlib.h>
#define MAX 5

struct Queue
{
	int data[MAX];
	int front, rear;
};

void initialize(struct Queue *q)
{
	q->front = q->rear = -1;
}

int isFull(struct Queue *q)
{
	return (q->rear == MAX - 1) ? 1 : 0;
}

int isEmpty(struct Queue *q)
{
	return (q->rear == -1) ? 1 : 0;
}

int insert(struct Queue *q, int d)
{
	if (isFull(q))
		return 0;
	q->data[++q->rear] = d;
	if (q->front == -1)
		q->front = 0;
	return 1;
}

void display(struct Queue *q)
{
	int i;
	if (isEmpty(q))
		printf("\n\tQueue is Empty \n");
	else
	{
		printf("\nQueue Elements\n");
		printf("Queue size:%d\nFront Pointer = %d\nRear Pointer= %d\n", MAX, q->front, q->rear);
		for (i = q->front; i <= q->rear; i++)
		{
			printf("%d\n", q->data[i]);
		}
	}
}

int delete (struct Queue *q) //dequeue
{
	int d = q->data[q->front];
	if (q->front == q->rear)
		q->front = q->rear = -1;
	else
		q->front++;
	return d;
}

int search(struct Queue *q, int k)
{
	int i;
	for (i = q->front; i <= q->rear; i++)
		if (q->data[i] == k)
			return i;
	return -1;
}

int main()
{
	int ch, d;
	struct Queue q;

	initialize(&q);
	while (1)
	{
		printf("\n\t\t\tMENU\n1. Insert.\n2. Delete.\n3. Search.\n4. Display.\n5. Exit");
		printf("\n\t\tEnter your Choice ::");
		scanf("%d", &ch);
		switch (ch)
		{
		case 1:
			printf("\nEnter data to be inserted :");
			scanf("%d", &d);
			d = insert(&q, d);
			if (d == 0)
				printf("\nQueue is full.Please delete some elements\n");
			else
				printf("\n Insertion done Successfully\n");
			break;
		case 2:
			if (isEmpty(&q))
				printf("\nQueue is empty\n");
			else
				printf("\nDeleted element is %d\n", delete (&q));
			break;
		case 3:
			printf("\n Enter data to be searched");
			scanf("%d", &d);
			d = search(&q, d);
			if (d == -1)
				printf("\nElement is not found\n");
			else
				printf("\nElement is found at location: %d \n", d);
			break;
		case 4:
			display(&q);
			break;
		case 5:
			exit(0);
		default:
			printf("\nNot a correct choice\n");
		}
	}
}
