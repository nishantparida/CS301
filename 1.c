#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// Compare function
int Comp(const void* one, const void* two)
{
        return strcmp(*(const char**)one, *(const char**)two);
}

int main()
{
    // Storing names in array
        const char* names_array[]= {"Nishant", "Amrit", "Chandan", "Sunandan", "Subhasmita", "Ritika" };
        
        int n = sizeof(names_array) / sizeof(names_array[0]);
    
        // Sort the names array by sending Comp as argument using qsort function where the size of the array was taken as criteria
        qsort(names_array, n, sizeof(const char*), Comp);


        // Print the sorted names
        printf("Sorted names: \n");
        for (int i = 0; i < n; i++)
    {
                printf("%s \n", names_array[i]);
    }
        return 0;
}
