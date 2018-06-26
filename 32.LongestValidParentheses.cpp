class Solution {
public:
	int longestValidParentheses(string s) {
		vector<char> stack;
		int max_length = 0;
		int prev_length = 0;
		int cur_length = 0;
		for (int i = 0; i < s.size(); i++)
		{
			if (s[i] == '(')
			{
				stack.push_back('(');
			}
			else if (s[i] == ')')
			{
				if (stack.empty() != true)
				{
					cur_length += 2;
					stack.pop_back();
					if (stack.empty() == true)
					{
						prev_length = cur_length + prev_length;
						cur_length = 0;
					}
				}
				else
				{
					if (max_length < cur_length + prev_length)
					{
						max_length = cur_length + prev_length;
						prev_length = 0;
					}
					cur_length = 0;
				}
			}
		}
		if (stack.empty() == true && max_length < cur_length + prev_length)
		{
			max_length = cur_length + prev_length;
		}
		else if (stack.empty() == false && max_length < cur_length)
		{
			max_length = cur_length;
		}
		else if (cur_length == 0 && max_length < prev_length)
		{
			max_length = prev_length;
		}
		return max_length;
	}
};