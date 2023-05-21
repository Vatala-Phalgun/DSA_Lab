#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <stdbool.h>
#include "HeapADT.h"
const int maxQueue = 20;
typedef struct
{
    int id;
    int priority;
    int serial;
} CUST;
int compareCust(void *cust1, void *cust2);
void processPQ(HEAP *heap);
char menu(void);
CUST *getCust(void);
int main(void)
{
    HEAP *prQueue;
    printf("Begin Priority Queue Demonstration\n");
    prQueue = heapCreate(maxQueue, compareCust);
    processPQ(prQueue);
    printf("End Priority Queue Demonstration\n");
    return 0;
}
int compareCust(void *cust1, void *cust2)
{
    CUST c1;
    CUST c2;
    c1 = *(CUST *)cust1;
    c2 = *(CUST *)cust2;
    if (c1.serial < c2.serial)
        return -1;
    else if (c1.serial == c2.serial)
        return 0;
    return +1;
}
void processPQ(HEAP *prQueue)
{
    CUST *cust;
    bool result;
    char option;
    int numCusts = 0;
    do
    {
        option = menu();
        switch (option)
        {
        case 'e':
            cust = getCust();
            numCusts++;
            cust->serial = cust->priority * 1000 + (1000 - numCusts);
            result = heapInsert(prQueue, cust);
            if (!result)
                printf("Error inserting into heap\n"),
                    exit(101);
            break;
        case 'd':
            result = heapDelete(prQueue, (void **)&cust);
            if (!result)
                printf("Error: customer not found\n");
            else
            {
                printf("Customer %4d deleted\n", cust->id);
                numCusts--;
            }
        }
    } while (option != 'q');
    return;
}
char menu(void)
{
    char option;
    bool valid;
    printf("\n============ Menu =============\n");
    printf(" e : Enter Customer Flight \n");
    printf(" d : Delete Customer Flight \n");
    printf(" q : Quit. \n");
    printf("===============================\n");
    printf("Please enter your choice: ");
    do
    {
        scanf(" %c", &option);
        option = tolower(option);
        switch (option)
        {
        case 'e':
        case 'd':
        case 'q':
            valid = true;
            break;
        default:
            printf("Invalid choice. Re-Enter: ");
            valid = false;
            break;
        }
    } while (!valid);
    return option;
}
CUST *getCust(void)
{
    CUST *cust;
    cust = (CUST *)malloc(sizeof(CUST));
    if (!cust)
        printf("Memory overflow in getCust\n"),
            exit(200);
    printf("Enter customer id: ");
    scanf("%d", &cust->id);
    printf("Enter customer priority: ");
    scanf("%d", &cust->priority);
    return cust;
}