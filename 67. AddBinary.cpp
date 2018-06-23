#include <iostream>

using namespace std;

class Solution {
public:
	string addBinary(string a, string b) {
		string ret;
		string* cur;
		string::iterator is;
		int flag = 0;
		if (a.size() > b.size())
		{
			ret = a;
			cur = &b;
		}
		else
		{
			ret = b;
			cur = &a;
		}
		is = cur->end();

		return ret;
	}
};

int main()
{
	string a = "1010";
	string b = "1011";
	Solution s;
	s.addBinary(a, b);
	return 0;
}