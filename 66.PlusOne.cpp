class Solution {
public:
	vector<int> plusOne(vector<int>& digits) {
		int index = digits.size() - 1;
		bool flag = false;
		digits[index] += 1;
		if (digits[index] == 10)
		{
			digits[index] = 0;
			flag = true;
		}
		else
			return digits;
		for (index -= 1; index >= 0; index--)
		{

			if (flag == true)
			{
				digits[index] += 1;
				flag = false;
			}
			if (digits[index] == 10)
			{
				digits[index] = 0;
				flag = true;
			}
			else
			{
				return digits;
			}
		}
		digits.insert(digits.begin(), 1);
		return digits;
	}
};