#include <stdio.h>

int main()
{
    int n1, n2;
    int i = 0, j = 0, k = 0;

    // Input for first array
    printf("Enter number of elements in 1st list: ");
    scanf("%d", &n1);

    int arr1[n1];

    printf("Enter %d elements (in ascending order): ", n1);
    for (int x = 0; x < n1; x++)
    {
        scanf("%d", &arr1[x]);
    }

    // Input for second array
    printf("Enter number of elements in 2nd list: ");
    scanf("%d", &n2);

    int arr2[n2];

    printf("Enter %d elements (in ascending order): ", n2);
    for (int x = 0; x < n2; x++)
    {
        scanf("%d", &arr2[x]);
    }

    // Declare merged array
    int merged[n1 + n2];

    // Merging logic
    while (i < n1 && j < n2)
    {
        if (arr1[i] < arr2[j])
        {
            merged[k++] = arr1[i++];
        }
        else
        {
            merged[k++] = arr2[j++];
        }
    }

    // Copy remaining elements
    while (i < n1)
    {
        merged[k++] = arr1[i++];
    }

    while (j < n2)
    {
        merged[k++] = arr2[j++];
    }

    // Display output
    printf("\nNumber of elements in 1st list: %d\n", n1);
    printf("Number of elements in 2nd list: %d\n", n2);

    printf("Merged elements in ascending order: ");

    for (int x = 0; x < n1 + n2; x++)
    {
        printf("%d ", merged[x]);
    }

    printf("\n");

    return 0;
}
