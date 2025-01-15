#include <stdio.h>
#include <stdlib.h>

int main() {
    int *ptr1, *ptr2, size;

    // Allocate memory for four integers
    size = 4 * sizeof(*ptr1);
    ptr1 = malloc(size);

    if (ptr1 == NULL) {
        printf("Memory allocation failed\n");
        return 1; // Return an error code if malloc fails
    }

    printf("%d bytes allocated at address %p \n", size, ptr1);

    // Resize the memory to hold six integers
    size = 6 * sizeof(*ptr1);
    ptr2 = realloc(ptr1, size);

    if (ptr2 == NULL) {
        printf("Memory reallocation failed\n");
        free(ptr1); // Free the original memory if realloc fails
        return 1; // Return an error code if realloc fails
    }

    ptr1 = ptr2; // Update ptr1 to point to the reallocated memory
    printf("%d bytes reallocated at address %p \n", size, ptr2);

    // Free the allocated memory
    free(ptr1);

    return 0; // Return 0 for successful execution
}

