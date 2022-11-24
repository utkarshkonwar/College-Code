// Linked List Implementation
// User Defined Program
#include <stdio.h>
#include <stdlib.h>

//node 
typedef struct Node  
{
	int data;
	struct Node* next;
} Node;

//display linked list
void displayLinkedList(Node* head)
{

	Node* temp = head;
	printf("\n");
	while (temp) 
	{
		printf("%d -> ", temp->data);
		temp = temp->next;
	}
	printf("NULL\n\n");
}

void insertionFromTail(Node** head, int value)
{
	// 1 -> 2 -> 3 -> NULL
	Node* n = (Node*) malloc(sizeof(Node));
	n->data = value;
	n->next = NULL;
	
	Node* temp = *head;
	
	if (temp == NULL)
	{
		*head = n;
		return;
	}
	
	while (temp)//(temp->next != NULL) 
	{
		if (temp->next == NULL)
		{
			temp->next = n;
			return;	
		}
		temp = temp->next;
	}

}

void insertionFromHead(Node** head, int value)
{
	Node* n = (Node*) malloc(sizeof(Node));
	n->data = value;
	n->next = NULL;
	
	Node* temp = *head;
	
	if (temp == NULL)
	{
		//n->next = (*head)->next;
		*head = n;
		return;
	}
	
	//n->next = (*head);
	//*head = (*head)->next;
	n->next = (*head);
	*head = n;

}

void deletion(Node** head, int value)
{
		Node* temp = (*head);

		if (temp == NULL)
		{
				printf("Nothing to delete\n");
				return;
		}

		if (temp->data == value)
		{
				(*head) = (*head)->next;
				free(temp);
				return;
		}

		/*if ((temp != NULL) && (temp->next == NULL) && (temp->data != value))
		{
			return;
		}*/


		while ((temp->next != NULL) 
				&& 
				(temp->next->data != value))
		{
				/*if (temp->next == NULL)
				{
					return;//break;
				}*/
				temp = temp->next;
		}

		if (temp->next->data != value)
		{
				return;
		}

		Node* toDelete = temp->next;
		temp->next = temp->next->next;

		free(toDelete);
}

void deletion2(Node** head, int value) 
{
		/*Node* temp = *head;
		if (temp = NULL)
		{
				printf("Nothing to delete\n");
				return;
		}

		if ((temp->data == value))
		{
				free(
		}*/
}


void main() 
{

	Node* head = NULL;
	
	while (1)
	{
	
		int choice = 0;
		printf("Perform Operations: \n");
		printf("(1) Display Linked List \n");
		printf("(2) Insert Node from tail\n");
		printf("(3) Insert Node from head\n");
		printf("(4) Delete Node\n");
		printf("(5) Exit\n");
		scanf("%d", &choice);
		switch(choice)
		{
			case 1:
			{
				displayLinkedList(head);
			} break;
			case 2:
			{
				int value = 0;
				printf("Enter value you want to insert at the tail: ");
				scanf("%d", &value);
				insertionFromTail(&head, value);
			} break;
			case 3:
			{
				int value = 0;
				printf("Enter value you want to insert at the head: ");
				scanf("%d", &value);
				insertionFromHead(&head, value);
			
			} break;
			case 4:
			{
				int value = 0;
				printf("Enter the node data which you want to delete: ");
				scanf("%d", &value);
				deletion(&head, value);
			} break;
			
			case 5:
			{
				return;
			}
			
			default:
			{
				printf("Invalid key pressed\n");
				break;
			}
		
		}
		
	}

}