//Implementation of Queue using linked list

#include<stdlib.h>
#include<stdio.h>

struct QNode
{
	int key;
	struct QNode* next;

};

struct Queue
{
	struct QNode *rear, *front;
	 

};

struct QNode* newNode(int k)
{
	struct QNode *node = (struct QNode*)malloc(sizeof(struct QNode));
	node->key = k;
	node->next = NULL;
	return node;

} 

struct Queue *createQueue()
{
	struct Queue *q=(struct Queue*)malloc(sizeof(struct Queue));
	q->front= q->rear = NULL;
	return q;
}

void enQueue(struct Queue *q,int k)
{

	struct QNode *node = newNode(k);
	if(q->rear==NULL)
	{	q->front = q->rear=node;
		return;
		
	}
	
	q->rear->next=node;
	q->rear=node;

	
}


struct QNode* deQueue(struct Queue *q)
{
	if(q->front==NULL)
		return;

	struct QNode *temp = q->front;

	q->front = q->front->next;

	if(q->front== NULL)
		q->rear = NULL;
	return temp;


}


int main()
{

	struct Queue *q = createQueue();
    enQueue(q, 10);
    enQueue(q, 20);
    deQueue(q);
    deQueue(q);
    enQueue(q, 30);
    enQueue(q, 40);
    enQueue(q, 50);
    struct QNode *n = deQueue(q);
    if (n != NULL)
      printf("Dequeued item is %d", n->key);
    return 0;
}
