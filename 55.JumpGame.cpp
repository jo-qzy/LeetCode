// 评论提供的，从后往前遍历，n为到前一个记录的点的需要的步长
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = 1;
        for (int i = nums.size() - 2; i >= 0; i--) {
            if (nums[i] >= n)
                n = 1;
            else
                n++;
            if (i == 0 && n > 1)
                return false;
        }
        return true;
    }
};

// 递归超时，但是我认为可行，因为我是差不多类似贪心写的
// 虽然他超时了。。。
class Solution {
public:
    bool canJump(vector<int>& nums) {
        return canJump(nums, 0);
    }
private:
    bool canJump(vector<int>& nums, size_t index) {
        if (index + nums[index] >= nums.size() - 1)
            return true;
        for (size_t i = nums[index]; i > 0; i--) {
            if (canJump(nums, index + i))
                return true;
        }
        return false;
    }
};