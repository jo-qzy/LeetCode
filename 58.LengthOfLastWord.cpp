class Solution {
public:
	int lengthOfLastWord(string s) {
		int length = 0;
		int back_index = s.size();
		int front_index = 0;
		//要记录前后下标，因为会出现字符串尾部为空格的情况
		for (front_index = back_index; front_index >= 0; front_index--)
		{
			if (s[front_index] == ' ')
			{
				length = back_index - front_index - 1;
				if (length != 0)
				{
					break;
				}
				back_index = front_index;
			}
		}
		if (front_index == -1)
		{
			length = back_index;
		}
		return length;
		}
};