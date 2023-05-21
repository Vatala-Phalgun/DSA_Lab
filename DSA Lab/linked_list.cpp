#include <iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;
} *head = NULL;

void create(int a[], int n)
{
    struct node *temp, *last;
    head = new struct node;
    head->data = a[0];
    head->next = NULL;
    last = head;

    for (int i = 1; i < n; i++)
    {
        temp = new struct node;
        temp->data = a[i];
        temp->next = NULL;
        last->next = temp;
        last = temp;
    }
}

void display(struct node *p)
{
    while (p != NULL)
    {
        cout << p->data << endl;
        p = p->next;
    }
}

int main()
{
    int a[] = {1, 2, 3, 4, 5};
    create(a, 5);
    display(head);

    return 1;
}

