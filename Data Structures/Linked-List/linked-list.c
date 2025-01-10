#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
	int data;
	struct Node * next;
}
Node;


Node* createNode(int data)
{
	// Create new node
	struct Node *newNode = malloc(sizeof(Node));
	
	// Sets data of node
	// and initializes pointer to NULL
	newNode->data = data;
	newNode->next = NULL;

	// Return pointer to created node
	return newNode;
}


void freeList(Node* head)
{
	Node* current = head;
	Node* next;
	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;

	}
}

void printList(Node* head)
{

	printf("Linked List:\n");
	Node* current = head;
	Node* next;
	while (current != NULL)
	{
		next = current->next;
		printf("%i", current->data);
		current = next;
		if (next != NULL)
		{
			printf("->");
		}
	}
}


int main()
{

	// Create head node
	Node* head = NULL;

	// Create tail node
	Node* tail = NULL; 
	
	for (int i = 0; i < 100; i++)
	{
		Node* newNode = createNode(i);
		if (head == NULL)
		{
			head = newNode;
			tail = head;
		}
		else
		{
			tail->next = newNode;
			tail = newNode;
		}
	}
	
	
	// Print linked list in a readable format
	printList(head);


	// Free dynamicaly allocated memory to avoid memory leaks
	freeList(head);

	// Programm executed successfully
	return 0;
}
