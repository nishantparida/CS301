#include <stdio.h>
  
int main()
{
    FILE *fptr1, *fptr2;
    char file1[100], c, c1, c2, file2[100];
  
    printf("Enter the filename whose contents you want to move \n");
    scanf("%s", file1);
  
    fptr1 = fopen(file1, "r");
    if (fptr1 == NULL)
    {
        printf("Cannot open file %s \n", file1);
    }
  
    printf("Enter the filename to which you want to move \n");
    scanf("%s", file2);
  
    fptr2 = fopen(file2, "w");
    c = fgetc(fptr1);

    while (c!= EOF)
    {
        fputc(c, fptr2);
        c = fgetc(fptr1);
    }
    printf("\nContents moved to %s", file2);
  
    fclose(fptr2);
    fclose(fptr1);

fptr1 = fopen(file1, "w");
    c1= '\0';
    c2 = fgetc(fptr1);
     while (c!= EOF)
    {
        fputc(c1, fptr2);
        c2 = fgetc(fptr1);
    }
    fclose(fptr1);
    return 0;
}
