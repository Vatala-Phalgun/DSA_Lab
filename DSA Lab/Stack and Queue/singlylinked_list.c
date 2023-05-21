#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *createLinkedList(int n)
{
    int i;
    struct node *head = NULL;
    struct node *newNode, *ptr;
    for (i = 0; i < n; i++)
    {
        newNode = (struct node *)malloc(sizeof(struct node));
        printf("Enter node data = ");
        scanf("%d", &newNode->data);
        newNode->next = NULL;
        if (head == NULL)
        {
            head = newNode;
        }
        else
        {
            ptr = head;
            while (ptr->next != NULL)
            {
                ptr = ptr->next;
            }
            ptr->next = newNode;
        }
    }
    return head;
}

void display(struct node *head)
{
    struct node *ptr;
    if (head == NULL)
    {
        printf("The Linked List is empty");
    }
    else
    {
        ptr = head;
        while (ptr != NULL)
        {
            printf("%d ", ptr->data);
            ptr = ptr->next;
        }
    }
}

void sort(struct node *head)
{
    struct node *current, *index;
    int temp;
    current = head;
    index = NULL;
    if (head == NULL)
    {
        return;
    }
    else
    {
        while (current != NULL)
        {
            index = current->next;
            while (index != NULL)
            {
                if (current->data > index->data)
                {
                    temp = current->data;
                    current->data = index->data;
                    index->data = temp;
                }
                index = index->next;
            }
            current = current->next;
        }
    }
}

void insert(struct node *head, int newdata)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    struct node *last = head;
    newnode->data = newdata;
    newnode->next = NULL;
    if (head == NULL)
    {
        head = newnode;
        return;
    }
    while (last->next != NULL)
        last = last->next;
    last->next = newnode;
    return;
}

int search(struct node *head)
{
    struct node *ptr = head;
    int flag, item;

    printf("\nEnter item which you want to search = ");
    scanf("%d", &item);
    while (ptr != NULL)
    {
        if (ptr->data == item)
        {
            printf("Item found");
            flag = 0;
        }
        else
        {
            flag = 1;
        }
        ptr = ptr->next;
    }
    if (flag == 1)
    {
        printf("Item not found\n");
    }
}

void delete (struct node *head, int element)
{
    struct node *np = head, *prev;
    if (np != NULL && np->data == element)
    {
        head = np->next;
        free(np);
        return;
    }
    while (np != NULL && np->data != element)
    {
        prev = np;
        np = np->next;
    }
    if (np == NULL)
        return;
    prev->next = np->next;
    free(np);
}

int main()
{
    int n, x;
    struct node *head;
    int opt;
    printf("\nMENU");
    printf("\n1.Create Linked List");
    printf("\n2.Display List");
    printf("\n3.Insert");
    printf("\n4.Search");
    printf("\n5.Delete");
    while (1)
    {
        printf("\nEnter option = ");
        scanf("%d", &opt);
        switch (opt)
        {
        case 1:
            printf("Enter the size of linked list = ");
            scanf("%d", &n);
            head = createLinkedList(n);
            sort(head);
            break;
        case 2:
            printf("Given Linked list is = ");
            display(head);
            break;
        case 3:
            printf("Enter new data = ");
            scanf("%d", &x);
            insert(head, x);
            sort(head);
            break;
        case 4:
            search(head);
            break;
        case 5:
            printf("Enter node to delete = ");
            scanf("%d", &x);
            delete (head, x);
            printf("List after deletion = ");
            display(head);
            break;
        default:
            exit(0);
        }
    }
    return 0;
}