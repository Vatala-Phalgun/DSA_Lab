#include <iostream>
using namespace std;
int main()
{
    int n, swap;
    cout << "Enter the no of elements in the array : ";
    cin >> n;
    int a[n];
    cout << "Enter the elements in the array --- ";
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (a[j] < a[i])
            {
                swap = a[i];
                a[i] = a[j];
                a[j] = swap;
            }
        }
    }
    cout << "Elements after swapping : ";
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << endl;
    }

    return  1;
    
}