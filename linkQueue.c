#include <stdio.h>
#include <stdlib.h>

struct qnode
{
    int element;
    struct qnode *next;
};
typedef struct qnode node;

struct _queue
{
    node *front;
    node *rear;
};
typedef struct _queue queue;

queue *create()
{
    queue *q;
    q = (queue *)malloc(sizeof(queue));
    if (q == NULL)
    {
        return NULL;
    }
    q->front = NULL;
    q->rear = NULL;
    return q;
}

int isEmpty(queue *q)
{
    return ((q->front == NULL) && (q->rear == NULL));
}

void enqueue(queue *q, int element)
{
    node *newNode = (node *)malloc(sizeof(newNode));
    newNode ->element = element;
    if (!isEmpty(q))
    {
        q->rear->next = newNode;
        q->rear = newNode;
    }
    else
    {
        printf("e");
        q->rear = newNode;
        q->front = newNode;
    }
}

void display(queue *q)
{
    node *ptr = q->front;
    while (ptr != NULL)
    {
        printf("%i ",ptr->element);
        ptr = ptr->next;
    }
}

int main()
{
    int choice = 1, val;
    queue *q = create();
    while (choice != 0)
    {
        printf("\n1. enqueue\n2. dequeue\n3. print\nother. exit\nenter: ");
        scanf("%i", &choice);
        if (choice == 1)
        {
            printf("enter value: ");
            scanf("%i", &val);
            enqueue(q, val);
        }
        else if (choice == 2)
        {
            // printf("%i",dequeue());
        }
        else if (choice == 3)
        {
            display(q);
        }
        else
        {
            choice = 0;
        }
    }
}
