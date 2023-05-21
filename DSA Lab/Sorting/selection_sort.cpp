#include <iostream>
using namespace std;

int smallest(int[], int, int);
int main()
{
    int n, temp, position;
    cout << "Enter the no of elements : ";
    cin >> n;
    int a[n];
    cout << "Enter the elements ----- " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        position = smallest(a, i, n);
        temp = a[i];
        a[i] = a[position];
        a[position] = temp;
    }
    cout << "Elements after sorting : " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << endl;
    }
}

int smallest(int a[], int i, int n)
{
    int pos, elsmall;
    elsmall = a[i];
    pos = i;
    for (int j = i + 1; j < n; j++)
    {
        if (a[j] < elsmall)
        {
            elsmall = a[j];
            pos = j;
        }
    }
    return pos;
}