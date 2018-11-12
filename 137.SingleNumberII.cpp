//本题自己没想出来，参考网址
//https://blog.csdn.net/Koala_Tree/article/details/80228525
class Solution {
public:
	int singleNumber(vector<int>& nums) {
		int ones = 0;
		int twos = 0;
		for (int i = 0; i < nums.size(); i++)
		{
			//如果数字出现一次，则只会在one出现
			//出现两次只会在two里面出现
			//出现三次则经过运算变为0
			ones = (ones ^ nums[i]) & ~twos;
			twos = (twos ^ nums[i]) & ~ones;
		}
		return ones;
	}
};