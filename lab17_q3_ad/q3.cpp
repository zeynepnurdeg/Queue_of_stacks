#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "queue_int.h"
#include "stack_int.h"

#define SIZE 10

int main(void)
{
	FILE* inp;
	inp = fopen("printingA.txt", "r");
	if (inp == NULL)
		printf("Error");
	else
	{
		stack_t pc1, pc2, pc3;

		initializeS(&pc1);
		push(&pc1, 60);
		push(&pc1, 50);
		push(&pc1, 40);

		initializeS(&pc2);
		push(&pc2, 80);
		push(&pc2, 70);

		initializeS(&pc3);
		push(&pc3, 90);

		queue_t q;
		initializeQ(&q);

		char line[SIZE];
		int num[SIZE], i = 0;
		while (fscanf(inp, " %[^\n]", line) != EOF)
		{
			switch (line[0])
			{
			case 'S':
				switch (line[2])
				{
				case '1':
					insert(&q, pop(&pc1));
					break;
				case '2':
					insert(&q, pop(&pc2));
					break;
				case '3':
					insert(&q, pop(&pc3));
					break;
				}
				break;
			case 'P':
				num[i] = remove(&q);
				i++;
				break;
			}
		}
		printf("Pending jobs: ");
		while (!isEmptyQ(&q))
			printf("%d ", remove(&q));

		printf("\nPrinted jobs: ");
		for (int k = 0; k < i; k++)
			printf("%d ", num[k]);
	}
	return 0;
}