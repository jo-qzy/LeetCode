int romanToInt(char* s) {
	assert(s);
	char* cur = s;
	int ret = 0;
	while (*cur != '\0')
	{
		//没什么技巧，就是需要注意的是当遇到1,10,100这几个需要读两个字符
		//因为这几个与其他特定字母结合的时候表示的是减而不是加
		//比如IX为9，IV为4，所以需要特殊处理
		switch (*cur)
		{
		case 'M':
			ret += 1000;
			break;
		case 'D':
			ret += 500;
			break;
		case 'C':
			if (*(cur + 1) == 'M' || *(cur + 1) == 'D')
				ret -= 100;
			else
				ret += 100;
			break;
		case 'L':
			ret += 50;
			break;
		case 'X':
			if (*(cur + 1) == 'C' || *(cur + 1) == 'L')
				ret -= 10;
			else
				ret += 10;
			break;
		case 'V':
			ret += 5;
			break;
		case 'I':
			if (*(cur + 1) == 'X' || *(cur + 1) == 'V')
				ret -= 1;
			else
				ret += 1;
			break;
		}
		cur++;
	}
    return ret;
}