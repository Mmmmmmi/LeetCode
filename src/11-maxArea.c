/*
给定 n 个非负整数 a1，a2，...，an，每个数代表坐标中的一个点 (i, ai) 。
在坐标内画 n 条垂直线，垂直线 i 的两个端点分别为 (i, ai) 和 (i, 0)。
找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。
说明：你不能倾斜容器，且 n 的值至少为 2。
图中垂直线代表输入数组 [1,8,6,2,5,4,8,3,7]。
在此情况下，容器能够容纳水（表示为蓝色部分）的最大值为 49。

示例:
    输入: [1,8,6,2,5,4,8,3,7]
    输出: 49

class Solution {
public:
    int maxArea(vector<int>& height) {
    }
};
*/
#include <stdio.h>

int MaxArea(int *height, int heightSize) 
{
    int a = 0;
    int b = 0;
    int maxarea = 0;
    int area = 0;
    if (height == NULL || heightSize == 0) {
        return 0;
    }
#if 0    
    for (int i = 0; i < heightSize; i++) {
        for (int j = i + 1; j < heightSize; j++) {
            a = height[i] > height[j] ? height[j] : height[i];         //高为两个边中小的
            b =  j - i;
            area = a * b;
            maxarea = maxarea > area ? maxarea : area;
        }
    }
    return maxarea;
#else
    int left = 0;
    int right = heightSize - 1;
    maxarea = 0;
    while(left < right) {
        
        a = height[left] > height[right] ? height[right] : height[left];
        b = right - left;
        
        area = a * b;

        maxarea = maxarea > area ? maxarea : area;
        
        if (height[left] <= height[right]) {
            left++;
        }
        else {
            right--;
        }

    }
    
    return maxarea;


#endif


}


int main()
{
    int height[] = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    int heightSize = sizeof(height) / sizeof(height[0]);
    printf("MaxArea = %d\n", MaxArea(height, heightSize));
    return 0;
}

