#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <string.h>

char final[200];

struct _StackNode
{
    char item;
    int rank;
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

void stackPush(Stack *s,char item, int rank)
{
    StackNode *tempNode = (StackNode *)malloc(sizeof(StackNode));
    tempNode -> item = item;
    tempNode -> rank = rank;
    tempNode -> next = s->top;
    s -> top = tempNode;
}

StackNode *stackPop(Stack *s)
{
    StackNode *temp = s->top;
    s->top = s->top -> next;
    return temp;
}

void display(Stack *s)
{
    StackNode *temp = s -> top;
    while (temp != NULL)
    {
        printf("%c, ",temp -> item);
        temp = temp -> next;
    }

}

const char *convert(char str[])
{
    Stack *s = stackInit();
    int i = 0,j = 0;
    while(str[i]!='\0')
    {
        int rank = 0;
        if(str[i]=='^')
        {
            rank = 3;
        }
        else if(str[i]=='*'||str[i]=='/')
        {
            rank = 2;
        }
        else if(str[i]=='+'||str[i]=='-')
        {
            rank = 1;
        }
        if(isdigit(str[i])||str[i] == ' ')
        {
            final[j] = str[i];
            j++; 
        }
        else if(s->top != NULL)
        {
            StackNode *temp = stackPop(s);
            if(rank == 3&&rank < temp->rank||(rank == 2||rank == 1)&&rank<=temp->rank)
            {
                final[j] = temp->item;
                stackPush(s,temp->item, rank);
                j++;
                final[j] = 0;
            }
            else if(str[i] == ')')
            {
                StackNode *temp;
                while(temp->item != '(')
                {
                    temp = stackPop(s);
                    if(temp->item != '(')
                    {
                        final[j] = temp->item;
                        j++;
                    }
                }
            }
            else if(str[i] == '(')
            {
                stackPush(s,str[i],rank);
            }
        }
        else
        {
            stackPush(s,str[i], rank);
        }
            i++;
    }
    StackNode *temp;
    if(str[i] == 0);
    {
        while(s->top != NULL)
        {
            temp = stackPop(s);
            final[j] = temp -> item;
            j++;
        }
    }
    return final;
}

int main()
{
    float item,item2;
    int choice = 0;
    Stack *s = stackInit();
    while(choice != 1)
    {
        printf("\n1. exit\nelse. convert\nenter: ");
        scanf("%i",&choice);
        if(choice != 1)
        {
            char str[500];
            printf("enter str: ");
            gets(str);
            gets(str);
            printf("%s",convert(str));
        }
    }
}
