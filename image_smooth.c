#include <stdio.h>
#include <stdlib.h>

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

int filter3x3(int** M, int x_s, int x_e, int y_s, int y_e, int* cnt) {
    int sum = 0;
    *cnt = 0;
    printf("{%d %d} {%d %D} %d %p, \n", x_s, x_e, y_s, y_e, M[0][0], M);
    for (int x=x_s; x<=x_e; ++x) {
        for (int y=y_s; y<=y_e; ++y) {
            sum += M[x][y];
            (*cnt)++;
        }
    }
    return sum;
}

int setup_filter_x(int pos_x, int MRowSize,
                   int* x_s, int* x_e) {

    if (MRowSize==1) {
        *x_s = pos_x;
        *x_e = pos_x;
    }
    else if (pos_x==0) {
        *x_s = pos_x;
        *x_e = pos_x + 1;
    }
    else if (pos_x==(MRowSize-1)) {
        *x_s = pos_x - 1;
        *x_e = pos_x;
    }
    else {
        *x_s = pos_x - 1;
        *x_e = pos_x + 1;
    }
    return 1;
}

int setup_filter_y(int pos_y, int MColSize,
                   int* y_s, int* y_e) {

    if (MColSize==1) {
        *y_s = pos_y;
        *y_e = pos_y;
    }
    else if (pos_y==0) {
        *y_s = pos_y;
        *y_e = pos_y + 1;
    }
    else if (pos_y==(MColSize-1)) {
        *y_s = pos_y - 1;
        *y_e = pos_y;
    }
    else {
        *y_s = pos_y - 1;
        *y_e = pos_y + 1;
    }
    return 1;
}

int** imageSmoother(int** M, int MRowSize, int MColSize, int** columnSizes, int* returnSize)
{
    int x_s=0, x_e=1;
    int y_s=0, y_e=1;
    int cnt = 1;
    int sum;
    int** out_M;
    //xxx out_M = malloc( MRowSize * MColSize * sizeof(int) );
    out_M = (int **)malloc(sizeof(int *) * MRowSize);
    for (int i=0; i < MRowSize; i++) {
        out_M[i] = (int *)malloc(sizeof(int) * MColSize);        
    }

    //*returnSize = 0;
    *returnSize=MRowSize;;
    //columnSizes[0]=malloc(sizeof(int)*MRowSize);
    *columnSizes=malloc(sizeof(int)*MRowSize);

    for (int i=0; i< MRowSize; i++) {
        for (int j=0; j < MColSize; j++) {
            setup_filter_x(i, MRowSize, &x_s, &x_e);
            setup_filter_y(j, MColSize, &y_s, &y_e);
            out_M[i][j] = filter3x3(M, x_s, x_e, y_s, y_e, &cnt);
            //printf("tmp= %d ; cnt= %d ;", out_M[i][j], cnt);
            out_M[i][j] = out_M[i][j]/cnt;
            //printf("result = %d\n", out_M[i][j]);

            //(*returnSize)++;
        }
        //columnSizes[0][i] = MColSize;
        (*columnSizes)[i] = MColSize;
    }

    return out_M;
}

int** gen2d(int MRowSize, int MColSize)
{
    //Cannot Work
    //int int_M [3][3];

    //-- Method3  Using ** pointer to a pointer
    int **int_M;
    int_M = (int **)malloc(sizeof(int *) * MRowSize);
    for (int i=0; i < MRowSize; i++) {
        int_M[i] = (int *)malloc(sizeof(int) * MColSize);
    }

    //-- Method4 Using double pointer
    //int** int_M;
    //int_M = (int **)malloc(sizeof(int *) * MRowSize);
    //int_M[0] = (int *)malloc(sizeof(int) * MColSize * MRowSize);
    //for (int i=0; i < MRowSize; i++) {
    //    int_M[i] = int_M[0] + (MColSize * i);
    //}

    int_M[0][0] = 1;
    int_M[0][1] = 1;
    int_M[0][2] = 1;
    int_M[1][0] = 1;
    int_M[1][1] = 0;
    int_M[1][2] = 1;
    int_M[2][0] = 1;
    int_M[2][1] = 1;
    int_M[2][2] = 1;
    
    return int_M; 
}


int main()
{
    int MRowSize = 3;
    int MColSize = 3;

    int returnSize;

    //int columnSizes [MRowSize];
    int **columnSizes;
    columnSizes = (int **)malloc(sizeof(int *) * MRowSize);
    for (int i=0; i < MRowSize; i++) {
        columnSizes[i] = (int *)malloc(sizeof(int) * MColSize);
    }


    //int** int_M = malloc( MRowSize * MColSize * sizeof(int) );
    //int int_M [3][3];
    int **int_M;
    int_M = (int **)malloc(sizeof(int *) * MRowSize);
    for (int i=0; i < MRowSize; i++) {
        int_M[i] = (int *)malloc(sizeof(int) * MColSize);
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

    for (int i=0; i<MRowSize; i++) {
        for (int j=0; j<MColSize; j++) {
            printf("%d ", int_M[i][j]);
        }
        printf("\n");
    }

    int** out_M = imageSmoother(int_M, MRowSize, MColSize, columnSizes, &returnSize);

    printf("returnSize = %d\n", returnSize);
    for (int i=0; i<MRowSize; i++) {
        for (int j=0; j<MColSize; j++) {
            printf("%d ", columnSizes[i][j]);
        }
        printf("\n");
    }

    for (int i=0; i<MRowSize; i++) {
        for (int j=0; j<MColSize; j++) {
            printf("%d ", out_M[i][j]);
        }
        printf("\n");
    }


    return 0;
}

