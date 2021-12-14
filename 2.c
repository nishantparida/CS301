#include <stdio.h>
#include<stdlib.h>
#include <string.h>

// heap subtree root node i
// index in arr[]. N = size
void heapify(int arr[], int n, int i)
{
   int largest = i; // Initialize largest as root
   int l = 2 * i + 1; // left = 2*i + 1
   int r = 2 * i + 2; // right = 2*i + 2

   // left child is larger than root
   if (l < n && arr[l] > arr[largest])
       largest = l;

   // right child is larger than largest yet
   if (r < n && arr[r] > arr[largest])
       largest = r;

   // largest is not root
   if (largest != i) {
       
    //   swap the values
       int temp = arr[i];
       arr[i]= arr[largest];
       arr[largest] = temp;

       // Recursively heapify the affected sub-tree
       heapify(arr, n, largest);
   }
}

// Function to build a Max-Heap from the given array
void buildHeap(int arr[], int n)
{
   // Index of last non-leaf node
   int startIdx = (n / 2) - 1;

   // Perform reverse level order traversal
	for (int i = startIdx; i >= 0; i--) {
       heapify(arr, n, i);
   }
}

//print the array representation of Heap
void printHeap(int arr[], int n)
{
   printf("Array representation of Heap is:\n");  //no cout in c

   for (int i = 0; i < n; ++i)
       printf("%d\n",arr[i]);
   
}
//Compare function
int Comp(const void* one, const void* two)
{
        return strcmp(*(const char**)one, *(const char**)two);
}
// main 
int main()
{
    // Storing names in array
   
    const char* names_array[]= {"Amrit", "Chandan", "Sunandan", "Subhasmita", "Ritika" };
        int s = sizeof(names_array) / sizeof(names_array[0]);
    
        // Sort the names
        qsort(names_array, s, sizeof(const char*), Comp);
        int arr[6];
        //Print and index sorted names
        printf("Sorted names: \n");
        for (int key = 0; key < s; key++)
    {
                printf("%s \n", names_array[key]);
                 arr[key]=key;

    }
    names_array[s]="Nishant";
    printf("%s \n", names_array[s]);
    arr[s]=s;


   int n = sizeof(arr) / sizeof(arr[0]);
   buildHeap(arr, n);
   printHeap(arr, n);
   return 0;
}
