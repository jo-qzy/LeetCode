class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		int size = nums.size();
		nums.push_back(0);//需要计算前n个数的和，在后面插一个0方便计算
		int min_index = size;
		int ret = nums[0];//ret首先等于数列的第一个数
						  //先看懂算法再思考为什么要在最后插0
		for (int i = 1; i < size; i++)
		{
			//将每个位置的数置成前n个序列的和
			//这样求序列和序列间的数的和只需要用nums[m] - nums[n]就好了
			nums[i] += nums[i - 1];
		}
		for (int i = 0; i < size; i++)
		{
			//如果序列间的差大于ret，更新ret
			if (nums[i] - nums[min_index] > ret)
			{
				ret = nums[i] - nums[min_index];
			}
			//当最小的和比前面的和均小时，更新最小的和，因为只有减去最小和才有可能得到最大值
			if (nums[i] < nums[min_index])
			{
				min_index = i;
			}
		}
		return ret;
	}
};

//递归
class AnotherSolution {
public:
	int maxSubArray(vector<int>& nums) {
		return partSolve(nums, 0, nums.size() - 1);
	}

	int partSolve(vector<int>& nums, int left, int right)
	{
		//递归结束条件
		if (left == right)
		{
			return nums[left];
		}

		//分为左右两部分处理
		int mid = left + right >> 1;
		int l_ret = partSolve(nums, left, mid);
		int r_ret = partSolve(nums, mid + 1, right);

		//处理横跨中间部分
		int tmp_sum = 0, l_max = nums[mid], r_max = nums[mid + 1];
		for (int i = mid; i >= left; i--)
		{
			//穷举左半部分的以mid开始的最大值
			tmp_sum += nums[i];
			if (l_max < tmp_sum)
			{
				l_max = tmp_sum;
			}
		}
		tmp_sum = 0;
		for (int i = mid + 1; i <= right; i++)
		{
			//穷举右半部分的以mid + 1开始的最大值
			tmp_sum += nums[i];
			if (r_max < tmp_sum)
			{
				r_max = tmp_sum;
			}
		}

		//返回最大值
		int ret = l_max + r_max;
		if (ret < l_ret)
		{
			ret = l_ret;
		}
		if (ret < r_ret)
		{
			ret = r_ret;
		}

		return ret;
	}
};
