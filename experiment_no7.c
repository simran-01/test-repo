/*
  NAME:MAPARI SIMRAN HASAN
  ROLLNO: 19CO04
  COURSE: Data Structure Lab.

  Experiment No 7:Implementation of singly linked list.

  THEORY:
		Singly Linked List:- In Singly Linked List, every node is made up of two parts:
				1. Data and 2. Next
			Data parts contains the actual element while next part contains address of next node
			It is a one way traversing list, which means we can traverse only in forward direction
			We cannot traverse in backward direction
			The first node is called head node	 
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
//#pragma pack(1)
struct SLL //self referencial structure
{
	int data;		  //if int takes 4 bytes then this data would take 4 bytes
	struct SLL *next; //4 bytes
};

struct SLL *insertAtEnd(struct SLL *h, int d)
{
	struct SLL *p, *tmp;
	p = (struct SLL *)malloc(sizeof(struct SLL));
	if (p == NULL)
	{
		printf("\nNot Enough memory.");
		return h;
	}
	p->data = d;
	p->next = NULL;
	if (h == NULL)
		h = p;
	else
	{
		tmp = h;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = p;
	}
	return h;
}

struct SLL *insertAtBeg(struct SLL *h, int d)
{
	struct SLL *p, *tmp;
	p = (struct SLL *)malloc(sizeof(struct SLL));
	if (p == NULL)
	{
		printf("\nNot Enough memory.");
		return h;
	}
	p->data = d;
	p->next = NULL;
	if (h == NULL)
		h = p;
	else
	{
		p->next = h;
		h = p;
	}
	return h;
}

struct SLL *insertAfter(struct SLL *h, int d, int k)
{
	struct SLL *p, *tmp;
	if (h == NULL)
		return h;
	p = (struct SLL *)malloc(sizeof(struct SLL));
	if (p == NULL)
	{
		printf("\nNot enough memory..");
		return h;
	}
	p->data = d;
	p->next = NULL;
	tmp = h;
	while (tmp != NULL && tmp->data != k)
		tmp = tmp->next;

	if (tmp != NULL)
	{
		p->next = tmp->next;
		tmp->next = p;
	}
	else
		printf("\nGiven Key data does not exist..");
	return h;
}

void display(struct SLL *h)
{
	if (h == NULL)
		printf("\nLinked List is Empty.");
	else
	{
		struct SLL *tmp;
		int n = 0;
		tmp = h;
		printf("\n\n\tLinked List Content:");
		while (tmp != NULL)
		{
			printf("\n\t\t%d", tmp->data);
			tmp = tmp->next;
			n++;
		}
		printf("\n\tSize of Linked List: %d bytes.", n * sizeof(struct SLL));
		printf("\nSize of Int: %d and Size of Pointer: %d", sizeof(int), sizeof(struct SLL *));
		printf("\n\tSize of Structure: %d bytes.", sizeof(struct SLL));
	}
}

struct SLL *removelast(struct SLL *h)
{
	struct SLL *tmp, *prev;
	if (h == NULL)
		printf("\nList is Empty.");
	else
	{
		tmp = h; //i=0;
		prev = tmp;
		while (tmp->next != NULL) //while(i!=5)
		{
			prev = tmp;		 //j=i;
			tmp = tmp->next; //i=i+1;
		}
		if (h->next == NULL)
			h = NULL;
		else
			prev->next = NULL;
		free(tmp);
		printf("\nLast Node Removed.");
	}
	return h;
}

struct SLL *removeGiven(struct SLL *h, int k)
{
	struct SLL *tmp, *prev;
	if (h == NULL)
		printf("\nList is Empty.");
	else
	{
		tmp = h; //i=0;
		prev = tmp;
		while (tmp != NULL && tmp->data != k) //while(i!=5)
		{
			prev = tmp;		 //j=i;
			tmp = tmp->next; //i=i+1;
		}
		if (tmp == NULL)
		{
			printf("\nGiven Node does not exist.");
			return h;
		}
		if (h == tmp)
			h = h->next;
		else
			prev->next = tmp->next;
		free(tmp);
		printf("\nGiven Node Removed.");
	}
	return h;
}

struct SLL *removeBefore(struct SLL *h, int k)
{
	struct SLL *tmp, *prev;
	if (h == NULL)
	{
		printf("\nList is Empty.");
		return h;
	}
	tmp = h;
	prev = tmp;
	while (tmp != NULL && tmp->data != k)
	{
		prev = tmp;
		tmp = tmp->next;
	}
	if (tmp == h)
	{
		printf("\nNo node before the first node.");
		return h;
	}
	if (tmp == NULL)
	{
		printf("\nGiven Node does not exist.");
		return h;
	}
	tmp = h;
	while (tmp != prev && tmp->next != prev)
		tmp = tmp->next;
	if (tmp == prev)
		h = h->next;
	else
		tmp->next = prev->next;
	prev->next = NULL;
	free(prev);
	return h;
}
int main()
{
	struct SLL *head;
	int ch, d, k;
	head = NULL;
	while (1)
	{
		printf("\n\n\n\t\t\tMENU");
		printf("\n1. Insert.\n2. Insert Begin.\n3. Insert After.\n4. Remove.\n5. Remove Given.\n6. Display.\n7. Exit.");
		printf("\n\tEnter Your Choice :: ");
		scanf("%d", &ch);
		switch (ch)
		{
		case 1:
			printf("\n\tEnter Data : ");
			scanf("%d", &d);
			head = insertAtEnd(head, d);
			break;
		case 2:
			printf("\n\tEnter Data : ");
			scanf("%d", &d);
			//printf("\n\tEnter Key Data : ");
			//scanf("%d",&k);

			head = insertAtBeg(head, d);

			break;

		case 3:
			printf("\n\tEnter Data : ");
			scanf("%d", &d);
			printf("\n\tEnter Key Data : ");
			scanf("%d", &k);

			head = insertAfter(head, d, k);
			//head=removelast(head);
			//head=removefirst(head);
			break;
		case 4:
			head = removelast(head);
			break;
		case 5:
			printf("\n\tEnter Key : ");
			scanf("%d", &d);
			head = removeGiven(head, d);
			break;
		case 6:
			display(head);
			break;
		case 7:
			//exit(0);
			return 0;
			break;
		default:
			printf("\n\t\tPlease enter correct choice....");
		}
	}
	return 0;
}