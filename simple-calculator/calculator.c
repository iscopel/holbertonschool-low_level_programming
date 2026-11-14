#include <stdio.h>

void print_menu(void)
{
	printf("1) Add\n");
	printf("2) Subtract\n");
	printf("3) Multiply\n");
	printf("4) Divide\n");
	printf("0) Quit\n");
}


int main(void)
{
	int choice;

	printf("Simple Calculator\n");
	while (1)
	{
		print_menu();
		printf("Choice: ");
		if (scanf("%d", &choice) != 1)
		{
			printf("Bye!\n");
			return (0);
		}
		if (choice == 0)
		{
			printf("Bye!\n");
			return (0);
		}
		printf("Not implemented yet\n");
	}
	return (0);
}