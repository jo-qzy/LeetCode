//执行用时: 12 ms, 在Single Number III的C++提交中击败了98.24% 的用户
class Solution {
public:
	vector<int> singleNumber(vector<int>& nums) {
		if (nums.empty())
			return vector<int>();
		int flag = 0;
		for (int i = 0; i < nums.size(); i++)
		{
			flag ^= nums[i];
		}
		for (int i = 0; i < 32; i++)
		{
			if (((1 << i) & flag) != 0)
			{
				flag = 1 << i;
				break;
			}
		}
		//上述过程为取出异或后结果的最后一个1
		//下面通过flag对数组中的数据进行分组，异或的结果就是寻找的数字
		int num1 = 0, num2 = 0;
		for (int i = 0; i < nums.size(); i++)
		{
			if ((flag & nums[i]) == 0)
				num1 ^= nums[i];
			else
				num2 ^= nums[i];
		}
		return { num1, num2 };
	}
};
