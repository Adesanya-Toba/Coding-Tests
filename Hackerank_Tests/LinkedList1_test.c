#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
typedef struct 
{
	int data;
	struct Node* next; //C-style
}Node;

Node* head; // head points to the Head node 

void Insert(int x)
{
	Node* temp = (Node*)malloc(sizeof(Node));
	temp->data = x;
	temp->next = head;
	head = temp;
}

void Print()
{
	Node* temp = head; // copy the address of head here, so we don't modify the reference
	printf("List is: ");
	while (temp!= NULL)
	{
		printf("%d ", temp->data);
		temp = temp->next;
	}
	printf("\n");
}

int main()
{
	head = NULL; // set to NULL for now i.e points nowhere now
	
	printf("How many numbers?\n");
	int n, x;

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		printf("Enter the number: \n");
		scanf("%d", &x);
		Insert(x);
		Print();
	}
	
	// To create a new node or memory block (C style)
	Node* temp = (Node*)malloc(sizeof(Node));

	//To fill in the elements of the node
	(*temp).data = 2;
	(*temp).next = NULL;

	//Alternatively, we could use the arrow (->) operator. Looks cleaner
	temp->data = 2;
	temp->next = NULL;
}