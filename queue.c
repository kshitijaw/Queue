//C implementation of queue

#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

//Structure for the queue
struct Queue
{
	int rear,front, size;	
	unsigned capacity;

	int *array;
};


struct Queue* createQueue(unsigned capacity)
{	

	struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));

	queue->front= queue->size= 0;

	queue->capacity = capacity;
	queue->array = (int*)malloc(queue->capacity*sizeof(int));
	return;


}


int isFull(struct Queue* queue)
{
	if(queue->capacity == queue->size)
		return 1;

	else
		return 0;

}

int isEmpty(struct Queue* queue)
{

	if(queue->size == 0)
		return 1;


	else
		return 0;

}

//Insert element 
void enqueue(struct Queue* queue, int key)
{	if(isFull(queue))
		return;
	queue->rear = (queue->rear+1)%queue->capacity;
	queue->array[queue->rear] = key;
	queue->size = queue->size + 1;
}

//Delete element 
int dequeue(struct Queue* queue)
{
	if(isEmpty(queue))
		return;
	
	int item = queue->array[queue->front];
	queue->front= (queue->front+1)%queue->capacity;
	queue->size = queue->size-1;
	return item;
}

//Display the queue
void display(struct Queue* queue)
{	if(isEmpty(queue))
		return;

	printf("\nSize %d\n",queue->size);
	for(int i=queue->front; i<queue->front+queue->size; i++)
	{
		printf("%d ",queue->array[i]);
	
	}

}

int main()
{
	struct Queue *queue = createQueue(1000);
	
	enqueue(queue,1);
	enqueue(queue,3);
	enqueue(queue,6);
	enqueue(queue,7);
	enqueue(queue,9);
	display(queue);
	printf("\n");
	printf("Dequeued item %d",dequeue(queue));
	printf("\nDequeued item %d\n",dequeue(queue));
	display(queue);
	
	return 0;

}
