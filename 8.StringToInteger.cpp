int myAtoi(char* str) {
	assert(str);
	char* cur = str;
	long long ret = 0;
	int flag = 1;
	//存在Atoi之后会出现溢出的情况，所以用long long来存储INT_MAX
	long long max = INT_MAX;
	while (*cur == ' ')
	{
		//跳过空格位置
		cur++;
	}
	if (*cur == '-')
	{
		//记录下符号位
		flag = -1;
		cur++;
	}
	else if (*cur == '+')
	{
		//跳过正符号位，想题目一定要仔细，其他都过了，栽在这里了
		cur++;
	}
	else if (*cur < '0' || *cur > '9')
	{
		//无法转成整数，直接返回0
		return 0;
	}
	while (*cur >= '0' && *cur <= '9')
	{
		ret *= 10;
		ret += *cur - '0';
		if (flag == 1 && ret > max)
		{
			//正数溢出，返回INT_MAX
			return INT_MAX;
		}
		else if (flag == -1 && ret > max + 1)
		{
			//特殊情况，如果是负数，超出绝对值的INT_MIN，返回整型最小值
			//这里不能用INT_MAX + 1去比较，因为INT_MAX + 1是INT_MIN
			return INT_MIN;
		}
		cur++;
	}
	return (int)(flag * ret);
}
