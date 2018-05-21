int lengthOfLongestSubstring(char* s) {
	int count = 0;
	char* start = s;
	char* end = s;
	char bitmap[255] = { 0 };
	while (*end != '\0')
	{
		if (bitmap[*end] == 0)
		{
			bitmap[*end] = 1;
		}
		else
		{
			if (end - start > count)
			{
				count = end - start;
			}
			while (*start != *end)
			{
				bitmap[*start] = 0;
				start++;
			}
			start++;
		}
		end++;
	}
	if (end - start > count)
	{
		count = end - start;
	}
	return count;
}