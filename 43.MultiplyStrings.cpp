//执行用时: 12 ms, 在Multiply Strings的C++提交中击败了48.02% 的用户
class Solution {
public:
	string multiply(string num1, string num2) {
		if (num1.size() < num2.size())
			swap(num1, num2);
		if (num1 == "0" || num2 == "0")
			return "0";
		int flag = 0;
		string ret;
		string tmp;
		//把短的数当做num2，少乘几次
		string::reverse_iterator cur1 = num1.rbegin();
		string::reverse_iterator cur2 = num2.rbegin();
		string::reverse_iterator cur;
		for (; cur2 != num2.rend(); cur2++)
		{
			//判断当前需要乘的数是不是0，是的话就不算了
			if (*cur2 == '0')
				continue;
			tmp = num1;
			flag = 0;
			//这里如果要乘的是1，那么就直接是num1，就省一个for循环
			if (*cur2 != '1')
			{
				for (cur1 = num1.rbegin(), cur = tmp.rbegin(); cur1 != num1.rend(); cur1++, cur++)
				{
					char mul = (*cur1 - '0') * (*cur2 - '0');
					*cur = mul % 10 + flag + '0';
					flag = mul / 10;
					if (*cur > '9')
					{
						*cur -= 10;
						flag += 1;
					}
				}
				//最高位如果还有溢出需要进位的
				if (flag != 0)
					tmp.insert(tmp.begin(), flag + '0');
			}
			//乘个位，就是这个数
			//乘十位，后面一个0
			//乘百位，后面两个0
			//这句insert就是在后面加几个0用的
			tmp.insert(tmp.end(), cur2 - num2.rbegin(), '0');
			//如果ret不为空，就相加得到结果
			if (ret.size() != 0)
				ret = addStrings(ret, tmp);
			else
				ret = tmp;
		}
		return ret;
	}
private:
	string addStrings(string& num1, string& num2) {
		//刚写了415.AddStrings，相加两数，直接把代码拿来用了
		//函数就是实现两数相加
		//https://github.com/jo-qzy/LeetCode/blob/master/415.AddStrings.cpp
		if (num1.size() < num2.size())
			swap(num1, num2);
		string::reverse_iterator cur1 = num1.rbegin();
		string::reverse_iterator cur2 = num2.rbegin();
		int flag = 0;
		while (cur2 != num2.rend())
		{
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
		if (flag == 1)
			num1.insert(num1.begin(), '1');
		return num1;
	}
};