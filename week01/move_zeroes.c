/**
 * @file move_zeroes.c
 * @author hksuki (you@domain.com)
 * @brief  homework for geekbang algo move zeros
 * @version 0.1
 * @date 2021-03-30
 * 
 * @copyright Copyright (c) 2021
 * 
 */

/**
 * @brief first program without any reference
 * 
 */
void moveZeroes_first(int* nums, int numsSize){
    int i = 0, real = 0;
    if (nums == NULL) {
        return;
    }
    bool *flags = (bool*)malloc(sizeof(bool)*numsSize);
    if (flags == NULL) {
        return;
    }
    memset(flags, 0, numsSize*sizeof(bool));
    for (i = 0; i < numsSize; i++) {
        if (nums[i] == 0) {
            flags[i] = true;
        }
    }
    for (i = 0, real = 0; i < numsSize; i++) {
        if (flags[i] == true) {
            continue;
        } else {
            nums[real] = nums[i];
            real++;
        }
    }
    while (real < numsSize) {
        nums[real++] = 0;
    }
}

/**
 * @brief second program with first reference,
 *        flags array is useless
 * 
 */
void moveZeroes_second(int* nums, int numsSize){
    int i = 0, real = 0;
    if (nums == NULL) {
        return;
    }
    for (i = 0, real = 0; i < numsSize; i++) {
        if (nums[i] == 0) {
            continue;
        } else {
            nums[real] = nums[i];
            real++;
        }
    }
    while (real < numsSize) {
        nums[real++] = 0;
    }
}

/**
 * @brief third program with one loop by swap
 * 
 */
void swap(int *array, int i, int j) {
    int tmp = array[i];
    array[i] = array[j];
    array[j] = tmp;
}
void moveZeroes_third(int* nums, int numsSize){
    int i = 0, real = 0;
    if (nums == NULL) {
        return;
    }
    for (i = 0, real = 0; i < numsSize; i++) {
        if (nums[i] == 0) {
            continue;
        } else {
            swap(nums, i, real);
            real++;
        }
    }
}

/**
 * @brief fourth program optimizing switch 
 * 
 */

void swap(int *array, int i, int j) {
    int tmp = array[i];
    array[i] = array[j];
    array[j] = tmp;
}
void moveZeroes(int* nums, int numsSize){
    int i = 0, real = 0;
    if (nums == NULL) {
        return;
    }
    for (i = 0, real = 0; i < numsSize; i++) {
        if (nums[i] != 0) {
            swap(nums, i, real);
            real++;
        }
    }
}