#include <stdio.h>
#include <stdlib.h>

struct _StackNode
{
    float item;
    struct _StackNode *next;
};
typedef struct _StackNode StackNode;

struct _Stack
{
    StackNode *top;
};
typedef struct _Stack Stack;

Stack *stackInit()
{
    Stack *s = (Stack *)malloc(sizeof(Stack));
    if(s==NULL)
    {
        return NULL;
    }
    s->top = NULL;
    return s;

}

void stackPush(Stack *s,float item)
{
    StackNode *tempNode = (StackNode *)malloc(sizeof(StackNode));
    tempNode -> item = item;
    tempNode -> next = s->top;
    s -> top = tempNode;
}

float stackPop(Stack *s)
{
    StackNode *temp = s->top;
    s->top = temp -> next;
    float item = temp -> item;
    free(temp);
    return item;
}

void display(Stack *s)
{
    StackNode *temp = s -> top;
    while (temp != NULL)
    {
        printf("%2.1f, ",temp -> item);
        temp = temp -> next;
    }
    
}

int main()
{
    float item,item2;
    int choice = 0;
    Stack *s = stackInit();
    while(choice != 0)
    {
        printf("1. insert\n2.dellete\n3.print\nother. exit");
        scanf("%i",&choice);
        if(choice == 1)
        {
            printf("enter item: ");
            scanf("%f",item);
            stackPush(s,item);
        }
        else if(choice == 2)
        {
            stackPop(s);
        }
        else if(choice == 3)
        {
            display(s);
        }
        else
        {
            choice = 0;
        }
    }
}
