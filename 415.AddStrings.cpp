//8 ms, 在Add Strings的C++提交中击败了89.93% 的用户
class Solution {
public:
	string addStrings(string num1, string num2) {
		if (num1.size() == 0)
			return num2;
		if (num2.size() == 0)
			return num1;
		//方便操作，把长的数作为num1，短的作为num2
		if (num1.size() < num2.size())
			swap(num1, num2);
		//尾到头开始相加
		string::reverse_iterator cur1 = num1.rbegin();
		string::reverse_iterator cur2 = num2.rbegin();
		int flag = 0;
		while (cur2 != num2.rend())
		{
			//短的数肯定先跑完，把短的数都加到长的数去，该进位的进位
			*cur1 += *cur2 - '0';
			if (flag == 1)
			{
				*cur1 += 1;
				flag = 0;
			}
			if (*cur1 > '9')
			{
				flag = 1;
				*cur1 -= 10;
			}
			cur1++, cur2++;
		}
		while (cur1 != num1.rend())
		{
			//长的数这里处理比较方便
			//只有有进位才有可能会出现需要进位的情况
			if (flag == 1)
			{
				flag = 0;
				*cur1 += 1;
				if (*cur1 > '9')
				{
					*cur1 -= 10;
					flag = 1;
				}
			}
			cur1++;
		}
		//最后相加还有一位溢出了，在头部插入一个'1'
		if (flag == 1)
			num1.insert(num1.begin(), '1');
		return num1;
	}
};