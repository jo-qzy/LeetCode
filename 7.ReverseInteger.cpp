int reverse(int x) {
	int max = INT_MAX;
	int num = x;
	int flag = 1;
	if (x < 0)
	{
		//保持ret为正，所以需要记录符号
		flag = -1;
		num = -x;
	}
	int ret = 0;
	while (num != 0)
	{
		if (ret > 0 && max / ret < 10)
		{
			//先判断ret*10是否会溢出
			return 0;
		}
		ret = ret * 10;
		if (max - ret < num % 10)
		{
			//判断下一个需要加的数加上是否会溢出
			return 0;
		}
		ret += num % 10;
		num /= 10;
	}
	return flag * ret;
}