// linkedlist.cpp
// PS C:\Users\KAMALASUBHA\OneDrive\Documents\C++ advanced concepts\c++20_2> g++ -std=c++2a -fmodules-ts -xc++-system-header iostream
// PS C:\Users\KAMALASUBHA\OneDrive\Documents\C++ advanced concepts\c++20_2> g++ -std=c++2a -fmodules-ts -c .\node.cpp
// PS C:\Users\KAMALASUBHA\OneDrive\Documents\C++ advanced concepts\c++20_2> g++ -std=c++2a -fmodules-ts -c .\insert.cpp
// PS C:\Users\KAMALASUBHA\OneDrive\Documents\C++ advanced concepts\c++20_2> g++ -std=c++2a -fmodules-ts -c .\linkedlist.cpp
// PS C:\Users\KAMALASUBHA\OneDrive\Documents\C++ advanced concepts\c++20_2> g++ -std=c++2a .\node.o .\insert.o .\linkedlist.o -o a.exe
import insert;
import node;

#include <iostream>

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
