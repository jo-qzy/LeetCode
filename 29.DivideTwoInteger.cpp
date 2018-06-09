int divide(int dividend, int divisor) {
	long long divd = dividend, div = divisor;
	int flag = 1;
	int ret = 0;
	if (divd < 0)
	{
		divd = -divd;
		flag = -flag;
	}
	if (divisor < 0)
	{
		div = -div;
		flag = -flag;
	}
	while (divd >= div)
	{
		long long tmp = div;
		long long tmp_count = 1;
		while (tmp + tmp < divd)
		{
			//不能用乘法就用位运算，快速减
			tmp = tmp << 1;
			tmp_count = tmp_count << 1;
		}
		if (INT_MAX - ret <= tmp_count && flag == 1)
		{
			return INT_MAX;
		}
		divd -= tmp;
		ret += tmp_count;
	}
	return flag * ret;
}
