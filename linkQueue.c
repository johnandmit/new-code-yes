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
    newNode->element = element;
    if (!isEmpty(q))
    {
        q->rear->next = newNode;
        q->rear = newNode;
    }
    else
    {
        q->rear = newNode;
        q->front = newNode;
    }
}

int dequeue(queue *q)
{
    node *ptr = q->front;
    if (!isEmpty(q))
    { /* có nút dữ liệu trong hàng đợi */
        if (q->front == q->rear) /* là nút dữ liệu cuối cùng */
        {
            q->rear = NULL;
            q->front = q->front->next;
        }
        q->front = NULL;    
        ptr->next = NULL;
    }
    return ptr->element;
}

void display(queue *q)
{
    node *ptr = q->front;
    if (!isEmpty(q))
    {
        while (ptr != q->rear)
        {
            printf("%i ", ptr->element);
            ptr = ptr->next;
        }
        printf("%i ", q->rear->element);
    }
    else
    {
        printf("no element in queue");
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
            printf("%i", dequeue(q));
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
