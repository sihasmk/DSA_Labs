#include <iostream>
#include <stack>

using namespace std;
 
// int partition(int low, int high, int A[]) 
// {
//     int pivot = A[low];

//     int i = low-1;
    
//     for (int j=low; j<high; j++)
//     {
//         if (A[j] <= pivot)
//         {
//             i++;
//             swap(A[i],A[j]);
//         }
//     }
//     swap(A[i+1],A[low]);
//     return i+1;
// }

int partition(int start, int end, int A[]){
    int pivot= A[end];
    int i = start-1;
    for(int j=start; j<=end-1;j++ ){
        if(A[j]<pivot){
            i++;
            swap(A[i],A[j]);
        }
    }
    i++;
    swap(A[i],A[end]);
    return i;
}

void QuickSorti(int low, int high, int A[])
{
    int stack[high-low+1];

    int top = -1;

    stack[++top] = low;
    stack[++top] = high;

    while (top>=0)
    {
        high = stack[top--];
        low = stack[top--];

        int part = partition(low,high,A);

        if (part-1>low)
        {
            stack[++top] = low;
            stack[++top] = part-1;
        }

        if (part+1<high)
        {
            stack[++top] = part+1;
            stack[++top] = high;
        }
    }
}

int main()
{
    // int size;

    // cin >> size;

    // int test[size]; 

    // for (int m=0; m<size; m++)
    // {
    //     int ele;
    //     cin >> ele;

    //     test[m] = ele;
    // }

    int test[] = {5,4,3,2,1};

    int size = sizeof(test)/sizeof(int);

    cout << "Array before sorting: ";

    for (int k: test)
    {
        cout << k << " ";
    }

    cout << "\nArray after sorting: ";

    QuickSorti(0, size, test);

    for (int l: test)
    {
        cout << l << " ";
    }
}