#include <stdio.h>
int stack_coin[10],i,top=-1;
void stack_push();
int stack_pop();
int stack_top();
int stack_display();
int stack_display_reverse();
void main()
{
int choice;
 while(1)
    {
        printf(" choose one operation");
        printf("\n 1.push \n 2.pop \n 3.top \n 4.display \n 5.display_reverse");
        printf("\n Enter choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
        {
            stack_push();
            break;
        }
        case 2:
        {
            stack_pop();
            break;
        }
        case 3:
        {
            stack_top();
            break;
        }
        case 4:
        {
            stack_display(stack_coin,0,top);
            break;
        }
        case 5:
        {
            stack_display_reverse(stack_coin,0,top+1);
            break;
        }
        default:
        {
            printf("Choice Invalid");
        }
        }

    }

}

void stack_push(int n)
{

    int coin_num;
    if(top==n-1)
        printf("\n overflow");
    else
    {
        printf("Enter coin number");
        scanf("%d",&coin_num);
        top = top + 1;
        stack_coin[top]=coin_num;
    }
}

int stack_pop()
{
    if(top==-1)
        printf("\n underflow");
    else
        printf("\nDeleted element is %d",stack_coin[top]);
        top=top-1;
    return 0;
}

int stack_top()
{
    printf("%d\n",stack_coin[i]);
    return 0;
}
int stack_display(int stack[],int last,int n)
{
    if(n<last)
        return;

    printf("%d\n", stack_coin[last]);

    stack_display(stack_coin, last-1, n);
}
int stack_display_reverse(int stack_coin[],int first,int n)
{
    if(first >= n)
        return;

    printf("%d\n", stack_coin[first]);

    stack_display_reverse(stack_coin, first + 1, n);

}
