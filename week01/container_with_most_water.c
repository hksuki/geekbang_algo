/**
 * @file container_with_most_water.c
 * @author hksuki (you@domain.com)
 * @brief  homework for geekbang algo containter with most water
 * @version 0.1
 * @date 2021-03-30
 * 
 * @copyright Copyright (c) 2021
 * 
 */

 /**
  * @brief violent first method
  * 
  */

int max(int a, int b) {
    if (a > b) {
        return a;
    } else {
        return b;
    }
}

int min(int a, int b) {
    if (a < b) {
        return a;
    } else {
        return b;
    }
}
int maxArea_violent(int* height, int heightSize){
    int maxValue = 0;
    for (int i = 0; i < heightSize - 1 ; i++) {
        for (int j = i + 1; j < heightSize; j++) {
            int area = min(height[i], height[j]) * (j - i);
            if (area > maxValue) {
                maxValue = area;
            }
        }
    }
    return maxValue;
}  

/**
 * @brief second method with double pointer
 * 
 */

int maxArea_double_pointer(int* height, int heightSize){
    int low = 0, high = heightSize - 1;
    int result = 0, tmp = 0;
    while (low < high) {
        if (height[low] < height[high]) {
            tmp = height[low] * (high - low);
            if (tmp > result) {
                result = tmp;
            }
            low++;
        } else {
            tmp = height[high] * (high - low);
            if (tmp > result) {
                result = tmp;
            }
            high--;
        }
    }
    return result;
} 

/**
 * @brief finally commit on leetcode, referenced from lesson
 * 
 */

 int maxArea(int* height, int heightSize){
    int max_area = 0;
    for (int i = 0, j = heightSize - 1; i < j;) {
        int min_h = height[i] < height[j] ? height[i++] : height[j--];
        max_area = fmax(max_area, (j - i + 1) * min_h);
    }
    return max_area;
}
