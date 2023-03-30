#include <iostream>

using namespace std;

int partition(int low,int high, int A[]) 
{
    int pivot = A[low];

    int i=low; int j=high;


    while (i<j)
    {
        do
        {
            i++;
        } while (A[i]<=pivot);

        do
        {
            j--;
        } while (A[j]>pivot);
        
        if (i<j)
        {
            swap(A[i],A[j]);
        }
    }
    swap(A[low], A[j]);
    return j;
}

void QuickSort(int low, int high, int A[]) 
{
    if (low<high)
    {
        int j = partition(low,high, A);
        QuickSort(low, j, A);
        QuickSort(j+1, high, A);
    }
}

int main()
{
    int size;

    cin >> size;

    int test[size]; 

    for (int m=0; m<size; m++)
    {
        int ele;
        cin >> ele;

        test[m] = ele;
    }

    cout << "Array before sorting: ";

    for (int k: test)
    {
        cout << k << " ";
    }

    cout << "\nArray after sorting: ";

    QuickSort(0,size, test);

    for (int l: test)
    {
        cout << l << " ";
    }
}