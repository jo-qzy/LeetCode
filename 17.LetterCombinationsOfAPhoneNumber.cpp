/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** letterCombinations(char* digits, int* returnSize) {
	//正常求法是递归求解，但是c写起来真的是太不方便了，不能像c++那样string + string
	//而且一般递归问题改成非递归都很麻烦，不过经历了一下午还是解决了
	char* cur = digits;
	int cur_divide = 0;//当前划分区间
	int prev_divide = 0;//前一次划分区间
	char** ret = NULL;
	const char ch[10][5] = { "","","abc","def","ghi","jkl","mno","pqrs","tuv", "wxyz" };
	int str_legth = strlen(digits) + 1;//包含'\0'，所以+1
	int i = 0;
	*returnSize = 1;
	while (*cur != '\0')
	{
		if (*cur != '7' && *cur != '9')
		{
			(*returnSize) *= 3;
		}
		else
		{
			(*returnSize) *= 4;
		}
		cur++;
	}
	cur = digits;
	cur_divide = (*returnSize);
	ret = (char**)malloc(sizeof(char*) * (*returnSize));
	for (int i = 0; i < (*returnSize); i++)
	{
		*(ret + i) = (char*)malloc(sizeof(char) * str_legth);
	}
	if (str_legth == 1)
	{
		*returnSize = 0;
		return ret;
	}
	while (*cur != '\0')
	{
		int start = 0;
		int ret_start = 0;
		int ch_index = 0;//字符的位置下标
		//这里的str_legth和前面的意义不同，前面表示给的digits的长度，这里当做数字对应的字符串长度
		//比如2对应就是3——"abc"，7对应4——"pqrs"
		str_legth = strlen(ch[*cur - '0']);
		prev_divide = cur_divide;
		cur_divide /= str_legth;
		//区间划分很重要，当数字对应的字符是3个，就在前一个基础上分为3个区，4个即在前一个基础上划分四个区间
		while (start < prev_divide)
		{
			ret_start = start;//这里比较难懂，之后会写博客来配图解释
			while (ret_start < (*returnSize))
			{
				//由于区间是分散的，所以每次开始的位置都不一样
				for (i = ret_start; i < ret_start + cur_divide; i++)
				{
					*(*(ret + i) + (cur - digits)) = ch[*cur - '0'][ch_index];//在对应位置放入字符
				}
				ret_start += prev_divide;
			}
			ch_index++;
			start += cur_divide;
		}
		cur++;
	}
	//最后在字符串尾部加'\0'
	for (i = 0; i < (*returnSize); i++)
	{
		*(*(ret + i) + (cur - digits)) = '\0';
	}
	return ret;
}

//c++版本
class Solution {
public:
	vector<string> letterCombinations(string digits) {
        if (digits.size() == 0)
            return vector<string>();
		string::iterator cur = digits.begin();
		int n = 1;
		vector<string> key = { string(), string(), "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
		while (cur != digits.end())
		{
			if (*cur != '7' && *cur != '9')
				n *= 3;
			else
				n *= 4;
			cur++;
		}
		vector<string> ret(n);
		vector<string>::iterator p = ret.begin();
		cur = digits.begin();
		int cur_size = n;
		while (cur != digits.end())
		{
			string::iterator key_cur = key[*cur - '0'].begin();
			cur_size /= key[*cur - '0'].size();
			for (int i = 0; i < n; i += cur_size)
			{
				for (int j = i; j < i + cur_size; j++)
				{
					ret[j] += *key_cur;
				}
				key_cur++;
				if (key_cur == key[*cur - '0'].end())
					key_cur = key[*cur - '0'].begin();
			}
			cur++;
		}
		return ret;
	}
};