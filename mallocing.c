#include <stdlib.h>
#include <stdio.h>

/*
int main()
{
    int *array;
    int num_elements, i;
    int sum = 0;

    printf("Enter number of elements: ");
    scanf("%d", &num_elements);
    array = (int *)malloc(num_elements * sizeof(int));
    if (array == NULL) {
        printf("Memory Allocation Failed");
        return 1;
    }
    printf("Enter %d integers:\n", num_elements);
    for (i=0; i < num_elements; i++) {
        printf("Element %d: ", i+1);
        scanf("%d", &array[i]);
    }
    for (i=0; i < num_elements; i++) {
        sum += array[i];
    }
    printf("Sum of elements: %d\n", sum);
    free(array);
    return 0;
}
*/

/*
#define SIZE 3

void printBoard(int **board) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int **board;
    board= (int **)calloc(SIZE, sizeof(int*));
    if (board == NULL) {
        printf("Memory Allocation Failed\n");
        return 1;
    }

    for (int i = 0; i < SIZE; i++) {
        board[i] = (int *)calloc(SIZE, sizeof(int));
        if (board[i] == NULL) {
            printf("Memory Allocation Failed\n");
            for (int j = 0; j < SIZE; j++) {
                free(board[j]);
            }
            free(board);
            return 1;
        }
    }
    printBoard(board);
}
*/

int main() {
    int *array;
    int size = 2, count = 0, input;
    array = (int *)malloc(size * sizeof(int));
    if (array == NULL) {
        printf("Memory Allocation Failed");
        return 1;
    }
    printf("Enter ints:\n");
    for (;;) {
        scanf("%d", &input);
        if (input == -1)  break;
        if (count == size) {
            size *= 3;
            int *new_buffer = realloc(array, size * sizeof(int));
            if (new_buffer == NULL) {
                printf("Memory Allocation Failed\n");
                return 1;
            }
            array = new_buffer;
        }
        array[count++] = input;
    }
}