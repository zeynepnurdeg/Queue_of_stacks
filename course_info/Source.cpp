#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "stack_int (2).h"
#include "queue_int.h"

void displayStack(stack_t s) {
	courses_t temp;
	while (!isEmptyS(&s)) {
		temp = pop(&s);
		printf("%d %d-->", temp.code, temp.credit);
	}
	printf("END");
	printf("\n");
}

void displayQueue(queue_t q) {
	printf("Queue Content: \n");
	printf("******************\n");
	while (!isEmptyQ(&q))
	{
		displayStack(remove(&q));
	}
}

int main(void)
{
	FILE* inp;
	inp = fopen("courses.txt", "r");
	if (inp == NULL)
		printf("Error");
	else
	{
		queue_t q;
		initializeQ(&q);
		
		courses_t temp;
		stack_t s;
		initializeS(&s);
		while (fscanf(inp, "%d %d", &temp.code, &temp.credit) != EOF)
		{
			push(&s, temp);
			char nextChar;
			while ((nextChar = fgetc(inp)) != '\n' && nextChar != EOF)
			{
				fscanf(inp, "%d %d", &temp.code, &temp.credit);
				push(&s, temp);
			}
			insert(&q, s);
			initializeS(&s);
		}
		fclose(inp);

		displayQueue(q);
	}
	return 0;
}