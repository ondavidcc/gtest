#include <stdio.h>

int findMaxConsecutiveOnes(int* nums, int numsSize) {
    int cur_max = 0;
    int prev_max = 0;
    int nums_prev1 = 0;
    for (int i=0; i < numsSize; i++) {
        if (nums[i]==1) {
            nums_prev1 = 1;

            if (cur_max>0) {
                cur_max++;
            }
            else {
                cur_max = 1;
            }
        }
        //else if (nums_prev1) {
        //    nums_prev1 = 0;
        //
        //}
        else {
            nums_prev1 = 0;
            if (cur_max > prev_max) {
                prev_max = cur_max;
            }
            cur_max = 0;
        }
        printf("%d > %d %d \n", nums[i], cur_max, prev_max);
    }

    //Remember to Pop LAST
    if (cur_max > prev_max) {
        return  cur_max;
    }    
    return prev_max;
}

int main()
{
    int numsSize = 5;
    int nums[] = {1, 0, 1, 1, 0};

    findMaxConsecutiveOnes(nums, numsSize);

    return 0;
}