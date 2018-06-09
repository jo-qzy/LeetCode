int strStr(char* haystack, char* needle) {
	if ((haystack == NULL || needle == NULL) || *needle == '\0')
	{
		return 0;
	}
	const char * dst_cur = haystack;
	const char * src_cur = needle;
	while (*dst_cur != '\0')
	{
		//cur指向目标当前位置，归位src_cur到头
		const char * cur = dst_cur;
		src_cur = needle;
		while (*cur != '\0')
		{
			//cur和src同时走
			if (*cur != *src_cur)
			{
				break;
			}
			cur++, src_cur++;
		}
		if (*src_cur == '\0')
		{
			//如果src到尾，说明匹配上了
			return dst_cur - haystack;
		}
		dst_cur++;
	}
	return -1;
}