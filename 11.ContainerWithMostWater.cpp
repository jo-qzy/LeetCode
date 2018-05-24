int maxArea(int* height, int heightSize) {
    int max = 0;
    int left = 0;
    int right = heightSize - 1;
    int cur = 0;
	//左右指针法，时间复杂度O(N)
    while (left < right)
    {
		//cur为当前面积
        cur = (right - left) * (height[left] < height[right] ? height[left] : height[right]);
        if (max < cur)
        {
            max = cur;
        }
        if (height[left] > height[right])
        {
			//当左边的高度大时，移动左边的边的面积只能是小于当前面积
			//因为底 = 原来的底 - 1，高最大只能是右边的边的高
			//所以只能移动右边的高
            right--;
        }
        else
        {
			//分析同上
            left++;
        }
    }
    return max;
}