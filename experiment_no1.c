/*
 Experiment No 1: Implement Menu driven program for factorial, fibonacci and palindrome using functions.


*/
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int factorial(int num)
{
	int fact = 1, i;
	for (i = 1; i <= num; i++)
		fact = fact * i;
	return fact;
}

void fibonacci(int num)
{
	int a = 0, b = 1, c, i;
	if (num >= 1)
		printf("\nFibonacci Series upto %d :\n\t0\t1", num);
	for (i = 1; i <= num - 2; i++)
	{
		c = a + b;
		printf("\t%d", c);
		a = b;
		b = c;
	}
}

int palindrome(char *p)
{
	char *r, tmp;
	int i, j;
	r = (char *)malloc(strlen(p)); //malloc is used to allocate the memory
	r = strcpy(r, p);
	j = strlen(p);
	for (i = 0; i < j / 2; i++)
	{
		tmp = r[i];
		r[i] = r[j - i - 1];
		r[j - i - 1] = tmp;
	}
	return strcmp(p, r);
}

int main()
{
	int ch, n, res;
	char s[50];
	while (1)
	{
		printf("\n\n\t\t\tMENU\n1.Factorial.\n2.Fibonacci.\n3.Palindrome.\n4.Exit.\n\tEnter your Choice::");
		scanf("%d", &ch);
		switch (ch)
		{
		case 1:
			printf("\nEnter the number::");
			scanf("%d", &n);
			res = factorial(n);
			printf("\n\tFactorial of %d is %d", n, res);
			break;
		case 2:
			printf("\nEnter the number::");
			scanf("%d", &n);
			fibonacci(n);

			break;
		case 3:
			printf("Enter the String::");
			scanf("%s", s);
			res = palindrome(s);
			if (res == 0)
				printf("\n\tString %s is Palindrome", s);
			else
				printf("\n\tString %s is not Palindrome", s);
			break;
		case 4:
			exit(0);
		default:
			printf("\n\tPlease enter correct choice...");
		}
	}
	return 0;
}