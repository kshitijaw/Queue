// C implementation of linked list 

#include<stdio.h>
#include<stdlib.h>

struct Node
{
	int data;
	struct Node* next;


};

//insert at the end 
void insertAfter(struct Node** head_ref, int new_data)
{
	struct Node* new_node = NULL;
	new_node = (struct Node*)malloc(sizeof(struct Node));
	new_node->data=new_data;
	new_node->next = NULL;

	if(*head_ref==NULL)
	{
		*head_ref = new_node;
		return;

	}
	
	struct Node* temp = *head_ref;
	
	while(temp->next!=NULL)
	{
		temp=temp->next;

	}

	temp->next=new_node;

	return;
}

//Insert at the front
void insertFirst(struct Node** head_ref, int new_data)
{
	
	struct Node* new_node =(struct Node*)malloc(sizeof(struct Node));
	
	 new_node->data = new_data;
	new_node->next = *head_ref;
	*head_ref = new_node;


}

//Insert in the middle
void insertBetween(struct Node** head_ref, int new_data)
{
	struct Node* new_node =(struct Node*)malloc(sizeof(struct Node));

	new_node->data = new_data;
	new_node->next = NULL;
	
	struct Node* prev_node = (struct Node*)malloc(sizeof(struct Node));
		
	prev_node = ((*head_ref)->next)->next;

	new_node->next = prev_node->next;

	prev_node->next = new_node;
}


//Printing the list 
void printlist(struct Node* temp)
{

	while(temp!=NULL)
	{
		printf("%d ",temp->data);
		temp= temp->next;

	}

	

}

//Delete node by the key value
void deleteNodekey(struct Node** head_ref, int key)
{
	struct Node *temp = *head_ref, *prev;

	if(temp!=NULL && temp->data== key)
	{
		*head_ref = temp->next;
		 free(temp);
		 return;

	}


	while(temp!=NULL && temp->data !=key)		//loop will continue till we find the node, when found temp = that node
	{
		prev = temp;
		temp= temp->next;

	}

	if(temp==NULL)
		return;


	prev->next = temp->next;
	free(temp);
}


//Delete node by the position
void deleteNode(struct Node** head_ref, int position)
{
	if(*head_ref == NULL)
	return;
	struct Node* temp = *head_ref;
	if(position==0)
	{
		*head_ref = temp->next;
		free(temp);
		return;
	}
	
	

	for(int i = 0 ; temp!=NULL && i<position-1; i++)		//i < position -1 because temp should point to previous of desired node
		{	printf("\nPosition: %d\nValue: %d\n\n",i,temp->data);
			temp= temp->next;
			printf("Next value: %d\n",temp->data);


		}

	if(temp== NULL || temp->next == NULL)			// temp->next==NULL because we are pointing to 1 less value if the next value is null then the position is out of reach
		{	printf("\nOut of reach\n");
			return;

		}
	struct Node* next = temp->next->next;  //storing pointer to the next of node to be deleted;
	
	free(temp->next);

	temp->next = next;

}
int main()
{
	struct Node* head = NULL;
	
	head = (struct Node*)malloc(sizeof(struct Node));
	

	head->data = 1;
	head->next = NULL;

	insertFirst(&head,3);

	insertFirst(&head,4);
	insertAfter(&head,5);

	insertAfter(&head,6);
	insertBetween(&head,2);
	printlist(head);

	deleteNodekey(&head,4);
	deleteNodekey(&head,5);

	int pos;
	printf("Enter position\n");
	scanf("%d",&pos);
	deleteNode(&head,pos);
	printf("\n");
	printlist(head);
return 0;
}
