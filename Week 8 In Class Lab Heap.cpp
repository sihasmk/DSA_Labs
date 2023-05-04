#include <iostream>
using namespace std;
  
// function to heapify the tree
void heapify(int arr[], int n, int root)
{
   // build heapify
   int max = root; //set max to root initially
   int left = 2*root +1; //left child of root
   int right = 2*root +2; //right child of root

   //update max to swap at the end

   if (left<n && arr[left]>arr[max]) {
      max = left;
   }

   if (right<n && arr[right]>arr[max]) {
      max = right;
   }

   //swap maximum with the original root

   if (max != root) {
      swap(arr[max], arr[root]);
      heapify(arr, n, max); //heapify is recursively called until swap was no longer required
   }
}
  
// implementing heap sort
void heapSort(int arr[], int n)
{
   // build heap
   for (int k=n/2-1; k>=0; k--) {
      heapify(arr, n, k);
   }

   // extracting elements from heap one by one

   for (int i=n-1; i>=0; i--) {
      swap(arr[i], arr[0]);
      heapify(arr, i, 0);
   }
   
}
  
/* print contents of array */
void displayArray(int arr[], int n)
{
   for (int i=0; i<n; ++i)
   cout << arr[i] << " ";
   cout << "\n";
}
  
// main program
int main()
{
   // int heap_arr[] = {4,17,3,12,9,6};
   // int n = sizeof(heap_arr)/sizeof(heap_arr[0]);

   int n;
   cout << "Enter size of heap: ";
   cin>>n;

   int i=0;
   int heaparr[n];

   while (i<n) {
      cout << "Enter element: ";
      int element;
      cin >> element;
      heaparr[i] = element;

      i++;
   }

   cout<<"Input array"<<endl;
   displayArray(heaparr,n);
  
   heapSort(heaparr, n);
  
   cout << "Sorted array"<<endl;
   displayArray(heaparr, n);
}
