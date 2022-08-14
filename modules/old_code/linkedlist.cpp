// linkedlist.c
// Driver Program

#include "insert.h"
#include "linkedlist.h"
#include <stdio.h>

void display(struct Node* temp)
{
	printf("The elements are:\n");
	while (temp != NULL) {
		printf("%d ", temp->data);
		temp = temp->next;
	}
	printf("\n");
}

int main()
{
	struct Node* head = NULL;

	int ch, data, pos;

	printf("Linked List: \n");
	while (1) {
		printf("1.Insert at Beginning");
		printf("\n2.Insert at Nth Position");
		printf("\n3.Insert At Ending");
		printf("\n4.Display");
		printf("\n0.Exit");
		printf("\nEnter your choice: ");
		scanf("%d", &ch);

		switch (ch) {
		case 1:
			printf("Enter the data: ");
			scanf("%d", &data);
			b_insert(&head, data);
			break;

		case 2:
			printf("Enter the data: ");
			scanf("%d", &data);

			printf("Enter the Position: ");
			scanf("%d", &pos);
			n_insert(&head, data, pos);
			break;

		case 3:
			printf("Enter the data: ");
			scanf("%d", &data);
			e_insert(&head, data);
			break;

		case 4:
			display(head);
			break;

		case 0:
			return 0;

		default:
			printf("Wrong Choice");
		}
	}
}
