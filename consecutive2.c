#include <stdio.h>

int findMaxConsecutiveOnes(int* nums, int numsSize) {
    int cur_max = 0;
    int cur_cnt[2] = {0, 0};
    int prev_max = 1;
    int zero_find = 0;

    //printf("%d %d \n", cur_cnt[0], cur_cnt[1]);

    for (int i=0; i < numsSize; i++) {
        if (nums[i]==1) {
            if (cur_cnt[0]>0) {
                cur_cnt[0]++;
            }
            else {
                cur_cnt[0] = 1;
            }
        }
        else {
            zero_find = 1;
            cur_max = cur_cnt[0] + cur_cnt[1];

            if (cur_max > prev_max) {
                prev_max = cur_max;
            }

            if (cur_cnt[0]>0) {
                cur_cnt[1] = 1 + cur_cnt[0];
            }
            else {
                cur_cnt[1] = 1;
            }
            cur_cnt[0] = 0;
        }
        printf("%d > prev_max[%d] ", nums[i], prev_max);
        printf("cur_max[%d] cur_cnt=[%d, %d]\n", cur_max, cur_cnt[0], cur_cnt[1]);

    }

    //Remember to Pop LAST
    //if (zero_find)
        cur_max = cur_cnt[0] + cur_cnt[1];
    //else
    //    cur_max = cur_cnt[0] + cur_cnt[1];

    if (cur_max > prev_max) {
        return  cur_max;
    }    
    return prev_max;
}

int main()
{
    int numsSize = 8;
    int nums[] = {1, 1, 1, 0, 1, 1, 1, 0};

    printf("ans:%d\n", findMaxConsecutiveOnes(nums, numsSize));

    return 0;
}