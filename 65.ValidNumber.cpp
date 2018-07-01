class Solution {
public:
	bool isNumber(string s) {
		//我的解法是有限状态机，将所有状态考虑进行排除
		bool e = false;
		bool ch = false;
		bool num = false;
		int front = 0;
		int back = s.size() - 1;
		//由于序列存在前面和后面有空格的情况，所以先去除前后空格
		//去除前面空格
		for (front; front < s.size(); front++)
		{
			if (s[front] == ' ')
				continue;
			else if ((s[front] <= '9' && s[front] >= '0') || (s[front] == '.'))
				break;
			else if (s[front] == '+' || s[front] == '-')
			{
				//遇到加号减号就将前下标放至+-之后
				front++;
				break;
			}
			else
				return false;
		}
		//当front和size相同，说明序列全为空格
		if (front == s.size())
			return false;
		//去除后面空格
		for (back; back >= 0; back--)
		{
			if (s[back] == ' ')
				continue;
			else if ((s[back] <= '9' && s[back] >= '0') || (s[back] == '.'))
				//考虑'.'的情况是因为存在序列'2.'也是合法序列
				break;
			else
				return false;
		}
		if (front == back && s[front] == '.')
			//存在一个序列只有一个点，特殊处理特殊情况
			return false;
		for (int i = front; i <= back; i++)
		{
			//四种情况：
			//1.数字，直接跳过，检查下一个位置
			//2.小数点，看小数点前是否有e或者别的小数点
			//3.e，e的情况看前面是否有数字序列，是否有别的e
			//4.其他字符
			if (s[i] <= '9' && s[i] >= '0')
			{
				num = true;
				continue;
			}
			else if (s[i] == '.')
			{
				if (ch == true || e == true)
					return false;
				else
					ch = true;
			}
			else if (s[i] == 'e')
			{
				if (num == false || e == true)
					return false;
				else
					e = true;
				if (s[i + 1] == '+' || s[i + 1] == '-')
					i++;
			}
			else
				return false;
		}
		return true;
	}
};