#include <stdio.h>

#define mark(x) (x) |= 1<<16;
#define is_marked(x) ((x) & 1<<16)
void zero(int* matrix, int rows, int cols) {
    for (int i = 0; i < rows * cols; i++) {
        if (matrix[i] == 0) {
            int row = i / rows;
            for (int zc = 0; zc < cols; zc++)
                mark(matrix[(row * cols) + zc]);

            int column = i % cols;
            for (int zr = 0; zr < rows; zr++)
                mark(matrix[(zr * cols) + column]);
        }
    }

    for (int i = 0; i < rows * cols; i++)
        if (is_marked(matrix[i]))
            matrix[i] = 0;
}

void pprint(int* a, int rows, int cols) {
    for (int i = 0, k = 0; i < rows * cols;i++, k++) {
        if (k >= cols) {
            k = 0;
            printf("\n");
        }
        printf("%d ",a[i]);
    }
    printf("\n---------\n");
}

int main(void) {
    int a[] = {1,1,1,1,
               1,0,1,1,
               1,1,1,1};
    pprint(a,3,4);
    zero(a,3,4);
    pprint(a,3,4);
}
