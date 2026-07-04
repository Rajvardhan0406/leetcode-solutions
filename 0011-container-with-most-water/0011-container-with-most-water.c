int maxArea(int* height, int heightSize) {
    int left = 0, right = heightSize - 1;
    int maxWater = 0;
    while (left < right) {
        int h = height[left] < height[right] ? height[left] : height[right];
        int water = h * (right - left);
        if (water > maxWater) maxWater = water;
        if (height[left] < height[right])
            left++;
        else
            right--;
    }
    return maxWater;
}