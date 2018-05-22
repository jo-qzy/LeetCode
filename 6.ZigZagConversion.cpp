char* convert(char* s, int numRows) {
	assert(s);
	int size = strlen(s) + 1;
	char* ret = (char*)malloc(size);
    if (numRows == 1)
    {
		//单独处理特殊字符串
        strncpy(ret, s, size);
        return ret;
    }
	assert(ret);
	char* cur = ret;
	char* get = s;
	int row_count = numRows * 2 - 2;//增量一直在变，总结一下规律
	//假设numRows传入为n，可以画图找规律
	//第一行增量为2n-2
	//第二行增量为2n-4,2依次交替
	//第三行增量为2n-6,4依次交替
	//……每行增量减少2，直至增量变为2
	//第n-1行增量为2,2n-4依次交替
	//第n行增量比较特殊，为2n-2
	int increment = numRows * 2;//每次的增量
	int increment_tmp = 0;//作为增量的临时存储变量
	for (int i = 0; i < numRows; i++)
	{
		//get作为获取当前字符的指针
		get = s + i;
		if (increment > 2)
		{
			//每次的增量减少2
			increment -= 2;
		}
		else if (increment == 2)
		{
			//当前一次增量为2，将增量置为2n-2
			increment = row_count;
		}
		increment_tmp = increment;
		while (get - s < size - 1)
		{
			*cur++ = *get;
			get += increment_tmp;
			//变换增量
			increment_tmp = row_count - increment_tmp;
			if (increment_tmp == 0)
			{
				increment_tmp = row_count;
			}
		}
	}
    *cur = '\0';
	return ret;
}