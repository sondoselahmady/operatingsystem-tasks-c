#include <stdio.h>
#include <stdlib.h>
int main()
{
    FILE *file;
    int temps[5];
    int i, max, min;
    file = fopen("temps.txt", "w");	// Open file in write mode
    if (file == NULL)
    {
        printf("Error opening file for writing!\n");
        return 1;
    }
    // Read 5 temperatures from the user and write them to the file
    for (i = 0; i < 5; i++)   {
        scanf("%d", &temps[i]);
        fprintf(file, "%d\n", temps[i]);
    }
    fclose(file);
    file = fopen("temps.txt", "r");	// Reopen file in read mode
    if (file == NULL)   {
        printf("Error opening file for reading!\n");
        return 1;
    }
    // Read first value and initialize max and min
    if (fscanf(file, "%d", &temps[0]) != 1)  {
        fclose(file);
        return 1;
    }
    max = min = temps[0];
    // Read remaining values and update max/min
    for (i = 1; i < 5; i++)
    {
        if (fscanf(file, "%d", &temps[i]) != 1)
        {
            fclose(file);
            return 1;
        }
        if (temps[i] > max) max = temps[i];
        if (temps[i] < min) min = temps[i];
    }
    fclose(file);
    // Print results
    printf("Highest Value: %d\n", max);
    printf("Lowest Value: %d\n", min);
    return 0;
}
