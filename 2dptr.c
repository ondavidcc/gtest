#include <stdio.h>
#include <stdlib.h>

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

int** gen2d(int MRowSize, int MColSize) {

    //Cannot Work
    //int int_M [3][3];
    
    //-- Method2 Using * Array of pointers
    /*
    int* int_M [MRowSize];
    for (i=0; i<MRowSize; i++) {
        int_M[i] = (int *)malloc(sizeof(int) * MColSize);
    }
    */

/*
    //-- Method3  Using ** pointer to a pointer
    int **int_M;
    int_M = (int **)malloc(sizeof(int *) * MRowSize);
    for (int i=0; i < MRowSize; i++) {
        int_M[i] = (int *)malloc(sizeof(int) * MColSize);
    }
*/
    //-- Method4 Using double pointer
    int** int_M;
    int_M = (int **)malloc(sizeof(int *) * MRowSize);
    int_M[0] = (int *)malloc(sizeof(int) * MColSize * MRowSize);
    for (int i=0; i < MRowSize; i++) {
        //int_M[i] = *(int_M + MColSize * i); //ERROR
        //int_M[i] = *int_M + (MColSize * i);
        //*(int_M+i) = int_M[0] + (MColSize * i);
        //*(int_M+i) = *int_M + (MColSize * i);
        int_M[i] = int_M[0] + (MColSize * i);
        //printf("int_M[%d] = %p |", i, int_M[i]);
        //printf("&int_M[%d] = %p |", i, &int_M[i]);
        //printf("\n");        
    }

    int_M[0][0] = 1;
    int_M[0][1] = 1;
    int_M[0][2] = 1;
    int_M[1][0] = 1;
    int_M[1][1] = 0;
    int_M[1][2] = 1;
    int_M[2][0] = 1;
    int_M[2][1] = 1;
    int_M[2][2] = 1;

    printf("int_M = %p \n", int_M);
    printf("&int_M[0] = %p \n", &int_M[0]);    
    printf("int_M[0] = %p \n", int_M[0]);
    printf("int_M[1] = %p \n", int_M[1]);
    printf("int_M[2] = %p \n", int_M[2]);
    //printf("int_M[3] = %p \n", int_M[3]);
    printf("&int_M[0][0] = %p \n", &int_M[0][0]);
    
    return int_M; 
}

int main() {

    int MRowSize = 3;
    int MColSize = 3;

    int returnSize;

    int** out_M = gen2d(MRowSize, MColSize);
    for (int i=0; i<MRowSize; i++) {
        for (int j=0; j<MColSize; j++) {
            printf("%d ", out_M[i][j]);
        }
        printf("\n");
    }

    printf("out_M = %p \n", out_M);
    printf("out_M[0] = %p \n", out_M[0]);

    return 0;
}