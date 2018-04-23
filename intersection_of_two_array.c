#include <stdio.h>
#include <stdlib.h>
/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* intersect(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    int Max;
    int used[nums1Size];

    for (int i=0; i<nums1Size; ++i) {
        used[i] = 0;
    }

    if (nums1Size > nums2Size) {
        Max = nums1Size;
    }
    else {
        Max = nums2Size;
    }
    int *ret;
    ret = malloc( Max * sizeof(int) );
    //*returnSize = 0;
    int k=0;
    
    for (int j=0; j<nums2Size; ++j) {
        for (int i=0; i<nums1Size; ++i) {
            if (used[i]==0) {
                if (nums1[i]==nums2[j]) {
                    ret[k] = nums1[i];
                    used[i] = 1;
                    printf("%d \n", ret[k]);
                    k++;
                    i = nums1Size;
                    //*returnSize++;
                }
            }
        }
    }
    *returnSize = k;
    printf("%p \n", returnSize);
    return ret;
}

int main() {
    int nums1Size = 4;
    int nums2Size = 6;
    int nums1[] = {0, 5, 2, 1};
    int nums2[] = {1, 3, 5, 3, 2,2};

    int returnSize;
    printf("%p \n", &returnSize);

    int* ret = intersect(nums1, nums1Size, nums2, nums2Size, &returnSize);

    printf("%p \n", &returnSize);
    printf("returnSize = %d \n",  returnSize);

    for (int k=0; k<returnSize; k++) {
                printf("%d \n", ret[k]);
    }

    return 0;
}