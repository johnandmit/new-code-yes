#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <string.h>

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
        printf("%f, ",temp -> item);
        temp = temp -> next;
    }
    
}

float cacu(char str[])
{
    Stack *s = stackInit();
    int i = 0;
    while(str[i] != '\0')
    {
        if(isspace(str[i]) != 0)
        {
            printf("ok");
        }
        else if(isdigit(str[i]))
        {
            stackPush(s,str[i]-48);
            //printf("%i", str[i]-48);
            printf("onk");
        }
        else
        {
            float num2 = stackPop(s);
            float num1 = stackPop(s);
            float ans;
            switch(str[i]){
                case '^':
                    ans = pow(num1,num2);
                    break;
                case '*':
                    ans = num1 * num2;
                    break;
                case '/':
                    ans = num1 / num2;
                    break;
                case '+':
                    ans = num1 + num2;
                    break;
                case '-':
                    ans = num1 - num2;
                    break;
            }
           
            stackPush(s, ans);
        }
        i++;
    }
    return s -> top -> item;
}

int main()
{
    float item,item2;
    int choice = 1;
    Stack *s = stackInit();
    while(choice != 0)
    {
        printf("\n1. insert\n2. dellete\n3. print\n4. caculate\nother. exit\nenter: ");
        scanf("%i",&choice);
        if(choice == 1)
        {
            printf("enter item: ");
            scanf("%i",item);
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
        else if(choice == 4)
        {
            char str[500];
            printf("enter str: ");
            scanf("%s",str);
            printf("%f",cacu(str));
        }
        else
        {
            choice = 0;
        }
    }
}
