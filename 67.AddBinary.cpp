class Solution {
public:
	string addBinary(string a, string b) {
		string ret;
		string* cur;
		int flag = 0;
		//二进制序列相加结果应为长的串的长度或者+1
		if (a.size() > b.size())
		{
			ret = a;
			cur = &b;
		}
		else
		{
			ret = b;
			cur = &a;
		}
		//两指针指向长串（返回串）和短串（需要与长串相加来进位等处理）
		string::iterator ir = ret.end();
		string::iterator is = cur->end();
		while (is != cur->begin())
		{
			//进位处理，直到短串处理完毕
			if (is[-1] == ir[-1])
			{
				if (flag == 1)
				{
					ir[-1] = '1';
				}
				else
				{
					ir[-1] = '0';
				}
				if (is[-1] == '1')
				{
					flag = 1;
				}
				else
				{
					flag = 0;
				}
			}
			else
			{
				if (flag == 1)
				{
					ir[-1] = '0';
				}
				else
				{
					ir[-1] = '1';
				}
			}
			is--, ir--;
		}
		while (flag != 0)
		{
			//存在短串加完后仍有进位未加入长串的情况
			if (ir != ret.begin())
			{
				//进位
				if (ir[-1] == '0')
				{
					ir[-1] = '1';
					flag = 0;
				}
				else
				{
					ir[-1] = '0';
				}
                ir--;
			}
			else
			{
				//到头则直接在头部插入
				ret.insert(0, "1");
                flag = 0;
			}
		}
		return ret;
	}
};