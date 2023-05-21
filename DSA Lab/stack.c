#include<stdio.h>
#include<stdlib.h>
int stack[10], choice = 0, top = -1;

void top_element()
{
    if (top == -1)
    {
        printf("\nThe stack is empty");
        return;
    }
    printf("\nThe top element is %d", stack[top]);
}
void push()
{
    int val;
    if (top == 9)
    {
        printf("\nStack is over flow..");
    }
    else
    {
        printf("\nEnter a value to be pushed: ");
        scanf("%d", &val);
        top++;
        stack[top] = val;
        printf("\nThe value succesfully added..");
    }
}
void pop()
{
    if (top == -1)
    {
        printf("\nThe stack is underflow..");
    }
    else
    {
        printf("\nThe popped elements is %d", stack[top]);
        top--;
    }
}
void display_reverse()
{
    static int temp = 0;
    static int j;
    if (temp == 0)
    {
        j = top;
        temp++;
    }
    if (top >= 0)
    {
        if (j >= 0)
        {
            printf("%3d", stack[j--]);
            display_reverse();
        }
        else
        {
            return;
        }
    }
    else
    {
        printf("\nThe STACK is empty");
    }
}
void display()
{
    static int i = 0;
    if (top >= 0)
    {
        if (i <= top)
        {
            printf("%3d", stack[i++]);
            display();
        }
        else
        {
            return;
        }
    }
    else
    {
        printf("\nThe STACK is empty");
    }
}
int main()
{
    while (choice != 6)
    {
        printf("\nChoose one from the below options.....");
        printf("\n1.Push\n2.Pop\n3.StackTop\n4.Display\n5.Displayreverse\n6.Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
        {
            push();
            break;
        }
        case 2:
        {
            pop();
            break;
        }
        case 3:
        {
            top_element();
            break;
        }
        case 4:
        {
            display();
            break;
        }
        case 5:
        {
            display_reverse();
            break;
        }
        default:
        {
            printf("\nPlease Enter a valid choice...");
        }
        };
    }
    return 1;
}
