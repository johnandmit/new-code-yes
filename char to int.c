#include <stdio.h>
#include <stdlib.h>

struct qnode
{
    char element;
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

void enqueue(queue *q, char element)
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

char dequeue(queue *q)
{
    node *ptr = q->front;
    if (!isEmpty(q))
    {
        if (q->front == q->rear)
        {
            q->rear = NULL;
            q->front = NULL;
        }
        else
            q->front = q->front->next;
    }
    else
    {
        printf("no queue");
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
            printf("%c ", ptr->element);
            ptr = ptr->next;
        }
        printf("%c ", q->rear->element);
    }
    else
    {
        printf("no element in queue");
    }
}

int CToI(char str[])
{
    queue *q = create();
    int i = 0, final = 0;
    while (str[i] != '\0')
    {
        enqueue(q, str[i]);
        i++;
    }
    while (!isEmpty(q))
    {
        final = final * 10 + (int)(dequeue(q)) - 48;
    }

    return final;
}

int main()
{
    int choice = 1, val;
    queue *q = create();
    while (choice != 0)
    {
        printf("\n1. enqueue\n2. dequeue\n3. print\n4. convert string into int\nother. exit\nenter: ");
        scanf("%i", &choice);
        fseek(stdin, 0, SEEK_END);
        if (choice == 1)
        {
            printf("enter item: ");
            scanf("%c", &val);
            enqueue(q, val);
        }
        else if (choice == 2)
        {
            printf("%c", dequeue(q));
        }
        else if (choice == 3)
        {
            display(q);
        }
        else if (choice == 4)
        {
            char str[500];
            printf("enter str: ");
            gets(str);
            printf("%i",CToI(str));
        }
        else
        {
            choice = 0;
        }
    }
}
