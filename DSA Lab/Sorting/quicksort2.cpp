#include <iostream>
using namespace std;

int particion(int[], int, int);
void quicksort(int[], int, int);
void printarray(int[], int);

void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int main()
{
    int n;
    cout << "Enter the elements of the array : ";
    cin >> n;
    int a[n];
    cout << "##### Enter the elements in the array #####" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int lb = 0;//intialized lower bound of array =0
    int ub = n - 1;//intialize upper bound to n-1
    quicksort(a, lb, ub);
    printarray(a, n);
}

void printarray(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << endl;
    }
}

int particion(int a[], int lb, int ub)
{
    int pivot = a[lb];//a[0]
    int start = lb;//0
    int end = ub;
    while (start < end)
    {
        while (a[start] <= pivot)
        {
            start++;
        }
        while (a[end] > pivot)
        {
            end--;
        }
        if (start < end)
        {
            swap(&a[start], &a[end]);
        }
    }
    swap(&a[lb], &a[end]);
    return end;//4
}

void quicksort(int a[], int lb, int ub)
{
    if (lb < ub)//checks
    {
        int location = particion(a, lb, ub);//4
        quicksort(a, lb, location - 1);
        quicksort(a, location + 1, ub);
    }
}
